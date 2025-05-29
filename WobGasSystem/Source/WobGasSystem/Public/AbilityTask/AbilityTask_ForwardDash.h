// Copyright - DMTesseracT

#pragma once

#include "CoreMinimal.h"
#include "Abilities/Tasks/AbilityTask.h"
#include "Components/TimelineComponent.h"
#include "Data/CharacterMovementData.h"
#include "AbilityTask_ForwardDash.generated.h"


DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnDashFinished);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnDashFailed);

/**
 * 
 */
UCLASS()
class WOBGASSYSTEM_API UAbilityTask_ForwardDash : public UAbilityTask
{
	GENERATED_BODY()
	
public: 
	UFUNCTION(BlueprintCallable, Category = "Ability|Tasks", meta = (HidePin = "OwningAbility", DefaultToSelf = "OwningAbility", BlueprintInternalUseOnly = "TRUE"))
	static UAbilityTask_ForwardDash* ForwardDash(UGameplayAbility* OwningAbility, FName TaskInstanceName, UCurveFloat* Curve, UCharacterMovementData* MovementData, TSubclassOf<UGameplayEffect> GameplayEffectClass);

	virtual void Activate() override;

	UAbilityTask_ForwardDash();

	UPROPERTY(BlueprintAssignable)
	FOnDashFinished OnDashFinished;

	UPROPERTY(BlueprintAssignable)
	FOnDashFailed OnDashFailed;

	virtual void InitSimulatedTask(UGameplayTasksComponent& InGameplayTasksComponent) override;

	/** Tick function for this task, if bTickingTask == true */
	virtual void TickTask(float DeltaTime) override;

	virtual void OnDestroy(bool AbilityIsEnding) override;

	protected:

	UPROPERTY()
	FVector ForwardVector;

	UPROPERTY()
	TObjectPtr<ACharacter> TargetCharacter;

	UPROPERTY()
	TObjectPtr<UAbilitySystemComponent> OwnerAbilitySystemComponent;

	UPROPERTY()
	TSubclassOf<UGameplayEffect> EffectClass;

	UPROPERTY()
	FGameplayEffectSpecHandle EffectSpecHandle;

	UPROPERTY()
	FActiveGameplayEffectHandle ActiveHandle;

	UPROPERTY()
	FGameplayEffectContextHandle EffectContextHandle;

	UFUNCTION()
	void TimelineProgress(float Value);

	UFUNCTION()
	void TimelineFinished();

	TObjectPtr<UCurveFloat> CurveFloat;

	TObjectPtr<UCharacterMovementData> MovementData;

	FTimeline Timeline;
};
