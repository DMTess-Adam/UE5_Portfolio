// Copyright - DMTesseracT

#pragma once

#include "CoreMinimal.h"
#include "GameplayEffectExecutionCalculation.h"
#include "TerrorTickExecution.generated.h"

/**
 * 
 */
UCLASS()
class WOBGASSYSTEM_API UTerrorTickExecution : public UGameplayEffectExecutionCalculation
{
	GENERATED_BODY()
	
	UTerrorTickExecution();

protected:
	virtual void Execute_Implementation(
		const FGameplayEffectCustomExecutionParameters& ExecutionParams,
		FGameplayEffectCustomExecutionOutput& OutExecutionOutput) const override;
};
