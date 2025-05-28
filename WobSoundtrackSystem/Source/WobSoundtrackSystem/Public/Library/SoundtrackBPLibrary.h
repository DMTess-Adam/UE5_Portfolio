// Copyright - DMTesseracT

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "SoundtrackBPLibrary.generated.h"

/**
 * 
 */
UCLASS()
class WOBSOUNDTRACKSYSTEM_API USoundtrackBPLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

	// used for getting the subsystem in unsafe BP objects.
	UFUNCTION(BlueprintCallable, Category ="SoundtrackLibrary")
	static class USoundtrackSubsystem* GetSoundtrackSubsystem(UWorld* WorldContext);
	
};
