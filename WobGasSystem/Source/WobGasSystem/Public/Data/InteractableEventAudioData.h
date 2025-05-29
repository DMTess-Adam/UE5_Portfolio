// Copyright - DMTesseracT

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "InteractableEventAudioData.generated.h"

/**
 * 
 */
UCLASS(BlueprintType)
class WOBGASSYSTEM_API UInteractableEventAudioData : public UDataAsset
{
	GENERATED_BODY()
	
public:

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Audio")
	TObjectPtr<USoundBase> OnInteract;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Audio")
	TObjectPtr<USoundBase> OnInteractEnd;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Audio")
	TObjectPtr<USoundBase> OnInspect;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Audio")
	TObjectPtr<USoundBase> OnInspectEnd;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Audio")
	TObjectPtr<USoundBase> OnUseDefault;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Audio")
	TObjectPtr<USoundBase> OnDiscardDefault;
};
