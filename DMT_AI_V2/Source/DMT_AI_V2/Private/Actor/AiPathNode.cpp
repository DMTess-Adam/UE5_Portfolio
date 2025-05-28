// Fill out your copyright notice in the Description page of Project Settings.


#include "Actor/AiPathNode.h"
#include "Components/SplineComponent.h"
#include "Components/StaticMeshComponent.h"
#include "EngineUtils.h"  //  Required for TActorIterator
#include "Components/SplineMeshComponent.h"
#include "Interface/DmtAiPatrolInterface.h"
#include "Engine/World.h"

// Sets default values
AAiPathNode::AAiPathNode()
{
    PrimaryActorTick.bCanEverTick = false;

    // Root component
    RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));

    // Editor Visual representation
    VisualMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("VisualMesh"));
    VisualMesh->SetupAttachment(RootComponent);

    // Spline component
    PathSpline = CreateDefaultSubobject<USplineComponent>(TEXT("PathSpline"));
    PathSpline->SetupAttachment(RootComponent);
}

void AAiPathNode::NativeActorArrivedAtNode(AActor* Actor)
{
    OnNodeReached.Broadcast(this, Actor);  
    ActorArrivedAtNode(Actor); 

    if (Actor->Implements<UDmtAiPatrolInterface>())
    {
        IDmtAiPatrolInterface::Execute_ArrivedAtPatrolNode(Actor, this);
    }

    ActorArrivedAtNode(Actor);
}



void AAiPathNode::PostEditMove(bool bFinished)
{
    ForceUpdateAllNodes(GetWorld());
}

// Called when the game starts or when spawned
void AAiPathNode::BeginPlay()
{
	Super::BeginPlay();
	
}

void AAiPathNode::OnConstruction(const FTransform& Transform)
{
    Super::OnConstruction(Transform);
    UpdateSpline();

}

void AAiPathNode::PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent)
{
    Super::PostEditChangeProperty(PropertyChangedEvent);

    if (PropertyChangedEvent.Property)
    {
        ForceUpdateAllNodes(GetWorld());
    }
}

void AAiPathNode::GenerateSplineMeshes()
{

    // assert that the spline is actually valid 
    if (!PathSpline || PathSpline->GetNumberOfSplinePoints() < 2)
    {
        UE_LOG(LogClass, Warning, TEXT("No Path Spline, or not enough points"));
        return;
    }

    ConformSplineToTerrain();

    UStaticMesh* Mesh = SplineMesh.LoadSynchronous();
    if (!Mesh) return;


    // Get total spline length
    float SplineLength = PathSpline->GetSplineLength();

    // Calculate how many new points we need (excluding the first point)
    int32 NumSegments = FMath::FloorToInt(SplineLength / SplineSegmentLength);

    for (int32 i = SplineMeshStartIndex; i < NumSegments - SplineMeshEndTrim; i++)
    {
        float Distance = i * SplineSegmentLength;
        FVector iStartPos = PathSpline->GetLocationAtDistanceAlongSpline(Distance, ESplineCoordinateSpace::World);
        FRotator iStartRot = PathSpline->GetTangentAtDistanceAlongSpline(Distance, ESplineCoordinateSpace::World).Rotation();

        UStaticMeshComponent* SplineMeshC = NewObject<UStaticMeshComponent>(this);
        SplineMeshC->SetStaticMesh(Mesh);
        SplineMeshC->SetWorldScale3D(SplineMeshScale);
        SplineMeshC->SetWorldLocation(iStartPos);
        SplineMeshC->SetWorldRotation(iStartRot);
        SplineMeshC->SetMobility(EComponentMobility::Movable);
        SplineMeshC->SetVisibility(true);
        SplineMeshC->AttachToComponent(PathSpline, FAttachmentTransformRules::KeepWorldTransform);

        SplineMeshC->bHiddenInGame = true;
        SplineMeshC->RegisterComponent();

        SplineMeshes.Add(SplineMeshC);
    }
}

void AAiPathNode::ForceUpdateAllNodes(UWorld* World)
{
    if (!World) return;

    for (TActorIterator<AAiPathNode> It(World); It; ++It)
    {
        AAiPathNode* Node = *It;
        if (Node)
        {
            Node->RerunConstructionScripts(); // Forces the node to update in the editor            
        }
    }
}

void AAiPathNode::UpdateSpline()
{
    if (!PathSpline) return;

    PathSpline->ClearSplinePoints();
    for (UStaticMeshComponent* Mesh : SplineMeshes)
    {
        if (Mesh) Mesh->DestroyComponent();
    }
    SplineMeshes.Empty();

    if (NextNode)
    {
        // Get direction vector towards NextNode
        FVector Direction = (NextNode->GetActorLocation() - GetActorLocation()).GetSafeNormal();

        // Rotate the PathSpline component to align its forward axis with Direction
        FRotator SplineRotation = Direction.Rotation();
        PathSpline->SetWorldRotation(SplineRotation);

        // Calculate distance & number of segments
        float Distance = FVector::Dist(GetActorLocation(), NextNode->GetActorLocation());
        int NumSegments = FMath::FloorToInt(Distance / SplineSegmentLength);

        // Add spline points along local X axis
        for (int i = 1; i <= NumSegments; i++)  // Start at 1 to avoid duplicate first point
        {
            FVector LocalOffset = FVector(i * SplineSegmentLength, 0, 0); // Move along X in local space
            FVector WorldPosition = PathSpline->GetComponentTransform().TransformPosition(LocalOffset);

            PathSpline->AddSplinePoint(WorldPosition, ESplineCoordinateSpace::World);
        }

        // Ensure the last point is exactly at NextNode
        PathSpline->AddSplinePoint(NextNode->GetActorLocation(), ESplineCoordinateSpace::World);

        // Update spline
        PathSpline->UpdateSpline();

        GenerateSplineMeshes();
    }
}

void AAiPathNode::ConformSplineToTerrain()
{

    if (!PathSpline) return;

    UWorld* World = GetWorld();
    if (!World) return;

    // Get spline length & point count
    int32 NumPoints = PathSpline->GetNumberOfSplinePoints();
    if (NumPoints < 2) return;

    // Iterate over spline **in segment order**
    for (int32 i = 0; i < NumPoints; i++)
    {
        // Get the world-space location of this spline point
        FVector SplinePoint = PathSpline->GetLocationAtSplinePoint(i, ESplineCoordinateSpace::World);

        // Perform downward trace to find terrain
        FVector TraceStart = SplinePoint + FVector(0, 0, SplineTraceHeight);
        FVector TraceEnd = SplinePoint - FVector(0, 0, SplineTraceHeight * 2);

        FHitResult Hit;
        FCollisionQueryParams TraceParams;
        TraceParams.bTraceComplex = false;
        TraceParams.AddIgnoredActor(this); // Avoid self-interaction
        if(NextNode) TraceParams.AddIgnoredActor(NextNode);
        // Perform trace
        if (World->LineTraceSingleByChannel(Hit, TraceStart, TraceEnd, ECC_Visibility, TraceParams))
        {
            // If we hit something, adjust this spline point
            FVector AdjustedLocation = Hit.ImpactPoint + FVector(0, 0, SplineZOffset);
            PathSpline->SetLocationAtSplinePoint(i, AdjustedLocation, ESplineCoordinateSpace::World);
        }
    }
    // **Ensure spline updates visually**
    PathSpline->UpdateSpline();
} 

// Called every frame
void AAiPathNode::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

