// Copyright - DMTesseracT

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "WobCommonUiInterface.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UWobCommonUiInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class WOBCOMMONUI_API IWobCommonUiInterface
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:

	UFUNCTION(BlueprintImplementableEvent)
	void GameplayButtonEventStarted(const struct FGameplayButtonTapEventData EventData);

	UFUNCTION(BlueprintImplementableEvent)
	void GameplayButtonEventEnded(const FString& Reason);

};
