// Copyright - DMTesseracT

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "DA_ItemTeleportEffectSystems.generated.h"

class UNiagaraSystem;

/**
 * 
 */
UCLASS(BlueprintType)
class WOBGASSYSTEM_API UDA_ItemTeleportEffectSystems : public UDataAsset
{
	GENERATED_BODY()
	
public:

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Teleport")
	TObjectPtr<UNiagaraSystem> TeleportOutSystem;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Teleport")
	float OutDelay;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Teleport")
	TObjectPtr<UNiagaraSystem> TeleportInSystem;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Teleport")
	float InDelay;
};
