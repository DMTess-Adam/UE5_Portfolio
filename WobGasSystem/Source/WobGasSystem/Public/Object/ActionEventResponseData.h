// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "ActionEventResponseData.generated.h"

/**
 * 
 */
UCLASS()
class WOBGASSYSTEM_API UActionEventResponseData : public UObject
{
	GENERATED_BODY()
	

protected:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (ExposeOnSpawn = "true"))
	bool bEventSuccessful;
};
