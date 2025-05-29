// Copyright - DMTesseracT

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "ItemRarityData.generated.h"

/**
 * 
 */
UCLASS()
class WOBGASSYSTEM_API UItemRarityData : public UDataAsset
{
	GENERATED_BODY()
	
public:

	// Map of item rarity
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Rarity")
	TMap<uint8, FLinearColor> RarityMap;
};
