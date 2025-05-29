// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "WobGasSystem.h"
#include "WobGasAbilityBase.generated.h"



/**
 * 
 */

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnAbilityInputActionEventSuccess);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnAbilityInputActionEventFail);

/*
* Default Instancing subclass (Per Actor). 
*/
UCLASS()
class WOBGASSYSTEM_API UWobGasAbilityBase : public UGameplayAbility
{
	GENERATED_BODY()
	

public:


	UPROPERTY(BlueprintAssignable, BlueprintCallable, Category ="Input Events")
	FOnAbilityInputActionEventSuccess OnAbilityInputActionEventSuccess;

	UPROPERTY(BlueprintAssignable, BlueprintCallable, Category = "Input Events")
	FOnAbilityInputActionEventFail OnAbilityInputActionEventFail;

	UWobGasAbilityBase();

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Ability")
	EGasAbilityInputId AbilityInputId = EGasAbilityInputId::None;

	void OnAvatarSet(const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilitySpec& Spec) override;

	virtual void SetTargetInfo(AActor* TargetInfo) { TargetActor = TargetInfo; };

	virtual void ActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, const FGameplayEventData* TriggerEventData) override;
protected:

	UFUNCTION(BlueprintCallable, Category="Helpers", BlueprintPure)
	class UWOBAbilityComponent* GetOwnerWobAbilityComponent();

	virtual void OnActiveCancelTagAdded();

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Target Data")
	TObjectPtr<AActor> TargetActor;

	//This ability is canceled if any of these tags are present at any point during execution. 
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = Tags)
	FGameplayTagContainer ActiveOwnerCancelTags;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Ability")
	class UInputAction* TriggerInput;

	UFUNCTION(BlueprintImplementableEvent, Category="Input Events")
	void OnTriggerInputPressed();

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category ="Ability")
	bool bActivateOnGranted{false};

	UPROPERTY()
	TArray<class UAbilityTask_WaitGameplayTagAdded*> ActiveTagTasks;
};
