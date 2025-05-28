// Copyright - DMTesseracT

#pragma once

#include "CoreMinimal.h"
#include "CommonButtonBase.h"
#include "WobMenuButtonBase.generated.h"

/**
 * 
 */
UCLASS(Blueprintable)
class WOBCOMMONUI_API UWobMenuButtonBase : public UCommonButtonBase
{
	GENERATED_BODY()
	
	virtual void HandleFocusReceived() override;

	virtual void HandleFocusLost() override;

	UFUNCTION(BlueprintCallable) 
	void ApplyHoverStyle();

	UFUNCTION(BlueprintCallable)
	void ApplyUnHoveredStyle();

protected:

	void GetChildTextWidgets(UWidget* Parent, TArray<class UCommonTextBlock*>& OutWidgets);

};
