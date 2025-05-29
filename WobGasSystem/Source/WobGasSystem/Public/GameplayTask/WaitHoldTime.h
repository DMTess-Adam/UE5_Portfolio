// Copyright - DMTesseracT

#pragma once

#include "CoreMinimal.h"
#include "GameplayTask.h"
#include "InputAction.h"
#include "WaitHoldTime.generated.h"



DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnHoldUpdate, float, Progress, bool, bIsHeld);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnHoldFinished);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnHoldFailed);
/**
 * 
 */
UCLASS()
class WOBGASSYSTEM_API UWaitHoldTime : public UGameplayTask
{
	GENERATED_BODY()
	
public:
	static UWaitHoldTime* StartHoldTask(UObject* WorldContextObject, AActor* OwningActor, float HoldTime, UInputAction* TrackingAction);
	
	UWaitHoldTime(const FObjectInitializer& ObjectInitializer);

	virtual void Activate() override;

	virtual void TickTask(float DeltaTime) override;

public:
	UPROPERTY(BlueprintAssignable, Category = "HoldTime")
	FOnHoldUpdate OnHoldUpdate;

	UPROPERTY(BlueprintAssignable, Category = "HoldTime")
	FOnHoldFinished OnHoldFinished;

	UPROPERTY(BlueprintAssignable, Category = "HoldTime")
	FOnHoldFailed OnHoldFailed;

protected:

	UInputAction* InputAction;
	float HoldTimeElapsed;
	float HoldTimeThreshold;
	AActor* Owner;

	FTimerHandle Timer;

	UFUNCTION()
	void OnActionEvent();

private: 
	struct FEnhancedInputActionValueBinding*ActionBinding;


};
