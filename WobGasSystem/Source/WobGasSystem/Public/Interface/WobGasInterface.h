// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "AttributeSet.h"
#include "WobGasInterface.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UWobGasInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class WOBGASSYSTEM_API IWobGasInterface
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:

	UFUNCTION(BlueprintImplementableEvent, Category = "Attribute Events")
	void OnDeath();

	UFUNCTION(BlueprintImplementableEvent, Category = "Attribute Events")
	void OnFallDamage();

	UFUNCTION(BlueprintImplementableEvent, Category = "Attribute Events")
	void OnFireDamage();

	UFUNCTION(BlueprintImplementableEvent, Category = "Attribute Events")
	void OnPhysicalDamage();

	UFUNCTION(BlueprintImplementableEvent, Category = "Attribute Events")
	void OnFearDamage();

	UFUNCTION(BlueprintImplementableEvent, Category = "Attribute Events")
	void OnHealthAttributeChanged(float NewValue, float OldValue);

	UFUNCTION(BlueprintImplementableEvent, Category = "Attribute Events")
	void OnMaxHealthAttributeChanged(float NewValue, float OldValue);

	// Queries the appropriate forward vector for a character.  Required to get correct forward vectors for HMDs rather than the standard actor forward vector.
	UFUNCTION(BlueprintNativeEvent, Category = "Ability Helpers")
	FVector GetCorrectForwardVector();

	UFUNCTION(BlueprintNativeEvent, Category ="Attribute Events")
	TArray<TSubclassOf<UAttributeSet>> GetAssignedAttributeSets();
	
	// Allows characters to specify where a gameplay ability should start its trace from.  This is used to allow Desktop and VR to specify different values.
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category ="Ability Helpers")
	FVector GetAbilityTraceStartLocation();

	// Allows characters to specify the forward vector to calculate the end location of a trace from.  This is used to allow Desktop and VR to specify different values.
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "Ability Helpers")
	FVector GetAbilityTraceForwardVector();

};
