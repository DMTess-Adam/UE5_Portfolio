// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Actor/InputActionEvent.h"
#include "InputActionEvent_Mash.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMashIncrement, const float&, TotalProgress);
/**
 * 
 */
UCLASS()
class WOBGASSYSTEM_API AInputActionEvent_Mash : public AInputActionEvent
{
	GENERATED_BODY()
	
	AInputActionEvent_Mash();

	UPROPERTY(BlueprintAssignable, BlueprintCallable)
	FOnMashIncrement OnMashIncrement;

};
