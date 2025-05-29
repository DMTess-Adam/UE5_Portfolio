// Copyright - DMTesseracT

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "DesktopInteractableInterface.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UDesktopInteractableInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class WOBGASSYSTEM_API IDesktopInteractableInterface
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category ="Desktop Interact")
	void DII_TryInteract();

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "Desktop Interact")
	void DII_EnableRangeHighlight();

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "Desktop Interact")
	void DII_DisableRangeHighlight();

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "Desktop Interact")
	void DII_EnableInteractFocusHighlight();

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "Desktop Interact")
	void DII_DIsableInteractFocusHighlight();

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "Desktop Interact")
	void DII_RelayMovementInput(const FVector2D Input);

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "Desktop Interact")
	void DII_RelayCameraLookInput(const FVector2D Input);

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "Desktop Interact")
	void DII_RelayBinaryActionInput();

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "Desktop Interact")
	void DII_RelayCrouchInput(bool bIsCrouched);

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "Desktop Interact")
	void DII_RelayJumpInput();

};
