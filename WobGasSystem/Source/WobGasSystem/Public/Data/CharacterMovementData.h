// Copyright - DMTesseracT

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "CharacterMovementData.generated.h"


USTRUCT()
struct FCharMovementSettings
{
	GENERATED_USTRUCT_BODY()

	// Standard movement speed when in default movement
	UPROPERTY(EditAnywhere)
	float BaseWalkSpeed{ 600.f };

	//The maximum movement speed when forward dashing
	UPROPERTY(EditAnywhere)
	float ForwardDashSpeed{ 600.f };
};
/**
 * 
 */
UCLASS(Blueprintable)
class WOBGASSYSTEM_API UCharacterMovementData : public UDataAsset
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere)
	FCharMovementSettings Settings;
};
