// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "AiPathScriptBase.generated.h"

/**
 * 
 */
UCLASS(Blueprintable, BlueprintType)
class DMT_AI_V2_API UAiPathScriptBase : public UObject
{
	GENERATED_BODY()

public:

	virtual void NativeExecute(AActor* Instigator);

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category ="PathScript")
	void Execute(AActor* Instigator);

	UFUNCTION(BlueprintCallable, Category="PathScript")
	void FinishExecute(const bool SessionEnding);

	UFUNCTION(BlueprintCallable)
	UWorld* GetWorldContext() { return WorldContext; };

	void SessionEnding();
private:

	UPROPERTY()
	TObjectPtr<UWorld> WorldContext;
};
