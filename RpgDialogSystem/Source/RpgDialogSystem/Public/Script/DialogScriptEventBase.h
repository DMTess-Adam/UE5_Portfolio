// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "DialogScriptEventBase.generated.h"

/**
 * Dialog script UObject that receives the target actor as the Instigator. Is executed as necessary during or after dialog events, as specified.
 * NOTE: Due to the nature of this class and how it is spawned/referenced, this class Explicitly removes itself from Garbage collection when instantiated.
 * YOU MUST CALL FinishExecute() once the script has finished to allow Garbage Collection or you'll cause a memory leak.
 */
UCLASS(Blueprintable)
class RPGDIALOGSYSTEM_API UDialogScriptEventBase : public UObject
{
	GENERATED_BODY()
	
public:

	// Should be called to initialise the script in native code. This calls ExecuteScript for blueprint instance logic.
	void NativeExecute(AActor* Instigator);

	// called by NativeExecute.
	UFUNCTION(BlueprintImplementableEvent, Category="Script")
	void ExecuteScript(AActor* Instigator, UWorld* World);

	// get the world context associated with the instigator of this script.
	UFUNCTION(BlueprintCallable, Category="Script")
	UWorld* GetWorldContext() { return WorldContext; };

	// call to ensure cleanup. this MUST be called to allow garbage collection.
	UFUNCTION(BlueprintCallable, Category="Script")
	void FinishExecute(const bool SessionEnding);

	void SessionEnding();

protected:



	UFUNCTION(blueprintCallable, Category ="Helpers")
	void SpawnActor(const TSubclassOf<AActor> Actor, const FTransform Transform);

	UFUNCTION(BlueprintCallable, Category ="Helpers")
	APawn* GetPlayer();

private:

	UWorld* WorldContext;
};
