// Copyright - DMTesseracT

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "Ability/WobGasAbilityBase.h"
#include "DashAbility.generated.h"

/**
 * 
 */
UCLASS()
class WOBGASSYSTEM_API UDashAbility : public UWobGasAbilityBase
{
	GENERATED_BODY()
	
	virtual void ActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, const FGameplayEventData* TriggerEventData) override;

};
