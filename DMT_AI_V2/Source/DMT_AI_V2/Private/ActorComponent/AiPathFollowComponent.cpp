// Fill out your copyright notice in the Description page of Project Settings.


#include "ActorComponent/AiPathFollowComponent.h"
#include "AIController.h"
#include "Actor/AiPathNode.h"
#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Navigation/PathFollowingComponent.h"

// Sets default values for this component's properties
UAiPathFollowComponent::UAiPathFollowComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

bool UAiPathFollowComponent::StartPatrol()
{
	bPatrolPaused = !bPatrolAllowed; 
	if (bPatrolAllowed && TargetNode) 
	{ 
		MoveToNode(); 
	} 
	return bPatrolAllowed && TargetNode;
}

bool UAiPathFollowComponent::PausePatrol()
{
	bPatrolPaused = true; 
	
	AAIController* Controller = GetController();
	if (Controller)
	{
		Controller->StopMovement();
	}
	return bPatrolPaused;

}


void UAiPathFollowComponent::OnMoveFinished(FAIRequestID RequestID, const FPathFollowingResult& Result)
{

	// reached node.
	if (!TargetNode || !GetOwner()) return;
	
	if (Result.IsSuccess())
	{
		TargetNode->NativeActorArrivedAtNode(GetOwner());

		// end of path logic
		if (!TargetNode->GetNextPathNode())
		{
			GetOwner()->SetActorRotation(TargetNode->GetActorRotation());
		}

		// Set new movement speed if specified and owner is a character class.
		if (TargetNode->NodeData.NewMovementSpeed > 0)
		{
			ACharacter* AsCharacter = Cast<ACharacter>(GetOwner());
			if (AsCharacter)
			{
				UCharacterMovementComponent* Movement = AsCharacter->GetCharacterMovement();
				if (Movement)
				{
					Movement->MaxWalkSpeed = TargetNode->NodeData.NewMovementSpeed;
				}
			}
		}


		// move on immediately if there is no valid wait time at this node.
		if (TargetNode->NodeData.WaitTime <= 0)
		{
			WaitFinished();
			return;
		}
		
		// set timer for node wait time
		FTimerDelegate Delegate; Delegate.BindUObject(this, &UAiPathFollowComponent::WaitFinished);
		GetWorld()->GetTimerManager().SetTimer(NodeWaitHandle, Delegate, TargetNode->NodeData.WaitTime, false);
		return;		
	}

	if (Result.IsInterrupted())
	{
		// Movement interrupted.
		return;
	}

	if (Result.IsFailure())
	{
		// Failed to reach
		WaitFinished();
		return;
	}



}

AAIController* UAiPathFollowComponent::GetController()
{
	APawn* Owner = Cast<APawn>(GetOwner());
	if(!Owner)
		return nullptr;

	return Cast<AAIController>(Owner->GetController());
}

void UAiPathFollowComponent::WaitFinished()
{
	TargetNode = TargetNode->GetNextPathNode();
	bMoveInProgress = false;
	if (TargetNode)
	{
		MoveToNode();
	}
}

// Called when the game starts
void UAiPathFollowComponent::BeginPlay()
{
	Super::BeginPlay();

	if (TargetNode.Get() && bStartPatrolOnSpawn)
	{
		MoveToNode();
	}
	// ...
	
}

void UAiPathFollowComponent::MoveToNode()
{
	if (!TargetNode.Get() || !bPatrolAllowed || bPatrolPaused || bMoveInProgress) return;

	AAIController* Controller = GetController();
	if (!Controller) return;

	//It's possible that the AI Controller may be a new controller at any point in the components life cycle, so we do this here to be sure we get the right result for each new move request.
	Controller->GetPathFollowingComponent()->OnRequestFinished.RemoveAll(this);
	Controller->GetPathFollowingComponent()->OnRequestFinished.AddUObject(this, &UAiPathFollowComponent::OnMoveFinished);

	bMoveInProgress = true;
	FAIMoveRequest MoveRequest;
	MoveRequest.SetGoalLocation(TargetNode.Get()->GetActorLocation());
	MoveRequest.SetAcceptanceRadius(TargetNode->NodeData.AcceptanceRadius);
	Controller->MoveTo(MoveRequest);

}


// Called every frame
void UAiPathFollowComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

}

