// Copyright - DMTesseracT

#pragma once

#include "CoreMinimal.h"
#include "Ability/WobGasAbilityBase.h"
#include "InputAction.h"
#include "WobGasHoldTimeAbility.generated.h"

/**
 * 
 */
UCLASS()
class WOBGASSYSTEM_API UWobGasHoldTimeAbility : public UWobGasAbilityBase
{
	GENERATED_BODY()
	

	void ActivateAbility(const FGameplayAbilitySpecHandle Handle,
		const FGameplayAbilityActorInfo* ActorInfo,
		const FGameplayAbilityActivationInfo ActivationInfo,
		const FGameplayEventData* TriggerEventData
	) override;

protected:

	// threshold for when Hold should succeed
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="HoldTime")
	float HoldTimeThreshold;

	// the input action to track
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "HoldTime")
	UInputAction* TrackingAction;

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category ="HoldTime")
	void OnHoldFinished();

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category ="HoldTime")
	void OnHoldFailed();

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "HoldTime")
	void OnHoldUpdate(const float Elapsed, const bool bIsHeld);

private:

	TObjectPtr<class UWaitHoldTime> HoldTask;
};
