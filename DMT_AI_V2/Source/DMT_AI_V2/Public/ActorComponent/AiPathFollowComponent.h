// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Navigation/PathFollowingComponent.h"
#include "AITypes.h"
#include "AiPathFollowComponent.generated.h"


class AAiPathNode;
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class DMT_AI_V2_API UAiPathFollowComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UAiPathFollowComponent();

	UFUNCTION(BlueprintCallable, Category = "Ai Path")
	void SetTargetNode(AAiPathNode* Node) { TargetNode = Node; };

	UFUNCTION(BlueprintCallable, Category = "Ai Path")
	AAiPathNode* GetTargetNode() { return TargetNode; };

	UFUNCTION(BlueprintCallable, Category ="Ai Path")
	void SetNodeAndStartPatrol(AAiPathNode* Node) { SetTargetNode(Node); StartPatrol(); };

	//Attempts to start patroling, returns true if successful. false if disallowed or no valid patrol node. 
	UFUNCTION(BlueprintCallable, Category = "Ai Path")
	bool StartPatrol();

	//Pause patrol. returns true if pause successful.
	UFUNCTION(BlueprintCallable, Category = "Ai Path")
	bool PausePatrol();

	//Allows patrol
	UFUNCTION(BlueprintCallable, Category ="Ai Path")
	void EnablePatrol() { bPatrolAllowed = true; };

	//Disallows patrol
	UFUNCTION(BlueprintCallable, Category = "Ai Path")
	void DisablePatrol() { bPatrolAllowed = false; };

	UFUNCTION(BlueprintCallable, Category = "Ai Path")
	void ToggleAllowPatrol() { bPatrolAllowed = !bPatrolAllowed; };

protected:

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Settings")
	bool bStartPatrolOnSpawn{ true };

	// The AI Path's current target node
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Node")
	TObjectPtr<AAiPathNode> TargetNode;

private:
	
	void OnMoveFinished(FAIRequestID RequestID, const FPathFollowingResult& Result);

	void ReachedNode();

	class AAIController* GetController();

	bool bPatrolPaused{ false };

	bool bPatrolAllowed{ bStartPatrolOnSpawn };

	bool bArrivedAtNode;

	bool bMoveInProgress;

	void WaitFinished();

	UPROPERTY()
	FTimerHandle NodeWaitHandle;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	virtual void MoveToNode();

	
public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
};
