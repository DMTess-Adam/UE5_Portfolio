// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "GasInventoryInterface.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UGasInventoryInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class WOBGASSYSTEM_API IGasInventoryInterface
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category="GasInventory")
	class UGasInventory* GetInventoryComponent();

};
