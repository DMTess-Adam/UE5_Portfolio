// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AiPathNode.generated.h"



USTRUCT(BlueprintType)
struct FAiPathNodeData
{
	GENERATED_BODY()

	//How long to wait at this node.
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (ClampMin = "0"))
	float WaitTime{ 0.f };
	
	//if above zero, this will override the targets Max Walk Speed when it arrives at the node.
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (ClampMin = "0"))
	float NewMovementSpeed{0.f};

	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (ClampMin = "0"))
	float AcceptanceRadius{ 10.f };

	UPROPERTY(BlueprintReadWrite,EditAnywhere)
	TSubclassOf<class UAiPathScriptBase> PathScript;

};


DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnNodeReached, AAiPathNode*, Node, AActor*, ArrivedActor);

UCLASS(Blueprintable)
class DMT_AI_V2_API AAiPathNode : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AAiPathNode();

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "AI Path")
	FAiPathNodeData NodeData;

	// Called by patrolling actors when they reach this node. Broadcasts OnNodeReached and invokes ActorArrivedAtNode() blueprint event. 
	virtual void NativeActorArrivedAtNode(AActor* Actor) final;

	//Customisable event for IoC implementation options.
	UFUNCTION(BlueprintImplementableEvent, Category = "AI Path")
	void ActorArrivedAtNode(AActor* Actor);

	UFUNCTION(BlueprintCallable, Category ="AI Path")
	AAiPathNode* GetNextPathNode() { return NextNode; };

	void PostEditMove(bool bFinished) override;

	// Event for when a patrolling AI reaches this node. 
	UPROPERTY(BlueprintAssignable, Category="Events")
	FOnNodeReached OnNodeReached;

protected:

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	void OnConstruction(const FTransform& Transform)override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI Path")
	TObjectPtr<AAiPathNode> NextNode;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AI Path")
	TObjectPtr<class USplineComponent> PathSpline;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AI Path")
	TObjectPtr<UStaticMeshComponent> VisualMesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI Path")
	TSoftObjectPtr<UStaticMesh> SplineMesh;

	// The length of a single Spline Segment, used to divide splines up to spawn Spline meshes evenly.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI Path")
	float SplineSegmentLength{ 20.f };

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI Path")
	FVector SplineMeshScale{FVector(1.0f)};

	// when looping spline points to add meshes, starts adding from this point onwards, skipping any point index before this index. e.g. to skip the first point, set this to 1.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI Path")
	int SplineMeshStartIndex{ 0 };

	// When looping spline points to add meshes, stops adding meshes at segments - SplineMeshEndTrim. e.g. set this to 1 if you want to skip the last point, 2 for hte last two etc..
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI Path")
	int SplineMeshEndTrim{ 0 };

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI Path")
	float SplineTraceHeight{ 50.f };

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI Path")
	float SplineZOffset{ 5.f };

	void PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent) override;

	UFUNCTION()
	void GenerateSplineMeshes();

private:

	UPROPERTY()
	TArray<class UStaticMeshComponent*> SplineMeshes;

	static void ForceUpdateAllNodes(UWorld* World);

	void UpdateSpline();

	//Trace for the nearest surface below the spline points and reposition them to follow the environment.
	void ConformSplineToTerrain();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
