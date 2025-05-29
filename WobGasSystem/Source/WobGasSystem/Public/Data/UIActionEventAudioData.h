// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include <InputAction.h>
#include "Engine/DataAsset.h"
#include "UIActionEventAudioData.generated.h"


USTRUCT(BlueprintType)
struct FUIActionEventAudioTiming
{

	GENERATED_BODY()

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TObjectPtr<UInputAction> AssignedAction;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float Start;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float End;

};
/**
 * 
 */
UCLASS()
class WOBGASSYSTEM_API UUIActionEventAudioData : public UDataAsset
{
	GENERATED_BODY()
	
public:

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TObjectPtr<USoundBase> AudioFile;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TArray<FUIActionEventAudioTiming> Sequences;

};
