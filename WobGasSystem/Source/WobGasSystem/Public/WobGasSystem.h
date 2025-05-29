// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "NativeGameplayTags.h"
#include "Modules/ModuleManager.h"

UE_DECLARE_GAMEPLAY_TAG_EXTERN(TAG_DamageType_Fire);
UE_DECLARE_GAMEPLAY_TAG_EXTERN(TAG_DamageType_Physical);
UE_DECLARE_GAMEPLAY_TAG_EXTERN(TAG_DamageType_Fall);
UE_DECLARE_GAMEPLAY_TAG_EXTERN(TAG_DamageType_Fear);

UENUM(BlueprintType)
enum class EGasAbilityInputId : uint8
{
	None,
	Confirm,
	Cancel
};


class FWobGasSystemModule : public IModuleInterface
{
public:

	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;

protected:

	void PrintInventory(const TArray<FString>& Args, UWorld* World);
};
