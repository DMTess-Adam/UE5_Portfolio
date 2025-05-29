// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "AbilitySystemComponent.h"
#include "WobGasAttributes.generated.h"

#define ATTRIBUTE_ACCESSORS(ClassName, PropertyName)\
	GAMEPLAYATTRIBUTE_PROPERTY_GETTER(ClassName, PropertyName)\
	GAMEPLAYATTRIBUTE_VALUE_GETTER(PropertyName)\
	GAMEPLAYATTRIBUTE_VALUE_SETTER(PropertyName)\
	GAMEPLAYATTRIBUTE_VALUE_INITTER(PropertyName)

/**
 * 
 */



UCLASS()
class WOBGASSYSTEM_API UWobGasAttributes : public UAttributeSet
{

	GENERATED_BODY()

public:




	UWobGasAttributes();

	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
	virtual void PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue) override;
	virtual void PostGameplayEffectExecute(const struct FGameplayEffectModCallbackData& Data) override;



	/* ---------------- ATTRIBUTES -------------*/

	/* ----- Dynamic Effect Damage Magnitude Specifier ----- */

	// This isn't a specific attribute. it exists so that gameplay effects can specify a base damage
	// that executions can draw on to calculate the damage from a small set of damage calculations. Though every 
	// ability system will have one, its value can be largely ignored. 
	UPROPERTY(BlueprintReadOnly, Category = "Attributes", ReplicatedUsing = OnRep_EffectDamageMagSpecifier)
	FGameplayAttributeData EffectDamageMagSpecifier;
	ATTRIBUTE_ACCESSORS(UWobGasAttributes, EffectDamageMagSpecifier);

	UFUNCTION()
	virtual void OnRep_EffectDamageMagSpecifier(const FGameplayAttributeData& OldEffectDamageSpecifier);

	/* ---- CHARGE ---- */
	/* ---- HEALTH ---- */
	UPROPERTY(BlueprintReadOnly, Category = "Attributes", ReplicatedUsing = OnRep_Charge)
	FGameplayAttributeData Charge;
	ATTRIBUTE_ACCESSORS(UWobGasAttributes, Charge);

	UFUNCTION()
	virtual void OnRep_Charge(const FGameplayAttributeData& OldCharge);

	UPROPERTY(BlueprintReadOnly, Category = "Attributes", ReplicatedUsing = OnRep_MaxCharge)
	FGameplayAttributeData MaxCharge;
	ATTRIBUTE_ACCESSORS(UWobGasAttributes, MaxCharge);
	UFUNCTION()
	virtual void OnRep_MaxCharge(const FGameplayAttributeData& OldMaxCharge);

	/* ---- HEALTH ---- */
	UPROPERTY(BlueprintReadOnly, Category = "Attributes", ReplicatedUsing = OnRep_Health)
	FGameplayAttributeData Health;
	ATTRIBUTE_ACCESSORS(UWobGasAttributes, Health);

	UFUNCTION()
	virtual void OnRep_Health(const FGameplayAttributeData& OldHealth);

	UPROPERTY(BlueprintReadOnly, Category = "Attributes", ReplicatedUsing = OnRep_MaxHealth)
	FGameplayAttributeData MaxHealth;
	ATTRIBUTE_ACCESSORS(UWobGasAttributes, MaxHealth);

	UFUNCTION()
	virtual void OnRep_MaxHealth(const FGameplayAttributeData& OldHealth);


	/* --- Terror --- */

	UPROPERTY(BlueprintReadOnly, Category = "Attributes", ReplicatedUsing = OnRep_Terror)
	FGameplayAttributeData Terror;
	ATTRIBUTE_ACCESSORS(UWobGasAttributes, Terror);

	UFUNCTION()
	virtual void OnRep_Terror(const FGameplayAttributeData& OldTerror);

	UPROPERTY(BlueprintReadOnly, Category = "Attributes", ReplicatedUsing = OnRep_MaxTerror)
	FGameplayAttributeData MaxTerror;
	ATTRIBUTE_ACCESSORS(UWobGasAttributes, MaxTerror);

	UFUNCTION()
	virtual void OnRep_MaxTerror(const FGameplayAttributeData& OldMaxTerror);


	/* Level and Experience */

	UPROPERTY(BlueprintReadOnly, Category = "Attributes", ReplicatedUsing = OnRep_CharacterLevel)
	FGameplayAttributeData CharacterLevel;
	ATTRIBUTE_ACCESSORS(UWobGasAttributes, CharacterLevel);

	UFUNCTION()
	virtual void OnRep_CharacterLevel(const FGameplayAttributeData& OldCharacterLevel);

	UPROPERTY(BlueprintReadOnly, Category = "Attributes", ReplicatedUsing = OnRep_ExperiencePoints)
	FGameplayAttributeData ExperiencePoints;
	ATTRIBUTE_ACCESSORS(UWobGasAttributes, ExperiencePoints);

	UFUNCTION()
	virtual void OnRep_ExperiencePoints(const FGameplayAttributeData& OldExperiencePoints);

	UPROPERTY(BlueprintReadOnly, Category = "Attributes", ReplicatedUsing = OnRep_MovementSpeedRate)
	FGameplayAttributeData MovementSpeedRate;
	ATTRIBUTE_ACCESSORS(UWobGasAttributes, MovementSpeedRate);

	UFUNCTION()
	virtual void OnRep_MovementSpeedRate(const FGameplayAttributeData& OldMovementSpeedRate);



	/* ---- RESISTANCES  ---- */

	/*
	* Resistances should be >= 0 and < MaxResistance. to account for a minimum of damage passthrough any resistance, this value should be less than 1.0.
	* If you want to be immune to something, you should apply an appropriate immunity gameplay tag.
	* Resistance values will be clamped to MaxResistance in post gameplay effect
	*/

	// This is the default resistance cap. In most cases it's best not to adjust this per-instance, but is exposed for edge cases.
	UPROPERTY(BlueprintReadWrite, Category = "Attributes")
	float MaxResistance{ 0.95f };

	UPROPERTY(BlueprintReadOnly, Category = "Attributes", ReplicatedUsing = OnRep_PhysicalResistance)
	FGameplayAttributeData PhysicalResistance;
	ATTRIBUTE_ACCESSORS(UWobGasAttributes, PhysicalResistance);

	UFUNCTION()
	virtual void OnRep_PhysicalResistance(const FGameplayAttributeData& OldPhysicalResistance);


	UPROPERTY(BlueprintReadOnly, Category = "Attributes", ReplicatedUsing = OnRep_DarknessResistance)
	FGameplayAttributeData DarknessResistance;
	ATTRIBUTE_ACCESSORS(UWobGasAttributes, DarknessResistance);

	UFUNCTION()
	virtual void OnRep_DarknessResistance(const FGameplayAttributeData& OldDarknessResistance);


	UPROPERTY(BlueprintReadOnly, Category = "Attributes", ReplicatedUsing = OnRep_FireResistance)
	FGameplayAttributeData FireResistance;
	ATTRIBUTE_ACCESSORS(UWobGasAttributes, FireResistance);

	UFUNCTION()
	virtual void OnRep_FireResistance(const FGameplayAttributeData& OldFireResistance);


	UPROPERTY(BlueprintReadOnly, Category = "Attributes", ReplicatedUsing = OnRep_LightResistance)
	FGameplayAttributeData LightResistance;
	ATTRIBUTE_ACCESSORS(UWobGasAttributes, LightResistance);

	UFUNCTION()
	virtual void OnRep_LightResistance(const FGameplayAttributeData& OldLightResistance);


private :

	UFUNCTION()
	void ClampPreAttributeChange_Health(float& NewValue);

	UFUNCTION()
	void ClampPreAttributeChange_MaxHealth(float& NewValue);

	UFUNCTION()
	void ClampPreAttributeChange_ExperiencePoints(float& NewValue);

	UFUNCTION()
	void ClampPreAttributeChange_CharacterLevel(float& NewValue);

	UFUNCTION()
	void ClampPreAttributeChange_MovementSpeedRate(float& NewValue);

	UFUNCTION()
	void ClampPreAttributeChange_PhysicalResistance(float& NewValue);

	UFUNCTION()
	void ClampPreAttributeChange_DarknessResistance(float& NewValue);

	UFUNCTION()
	void ClampPreAttributeChange_LightResistance(float& NewValue);

	UFUNCTION()
	void ClampPreAttributeChange_FireResistance(float& NewValue);

	UFUNCTION()
	void ClampPreAttributeChange_Terror(float& NewValue);

	UFUNCTION()
	void ClampPreAttributeChange_MaxTerror(float& NewValue);

	UFUNCTION()
	void ClampPreAttributeChange_Charge(float& NewValue);

	UFUNCTION()
	void ClampPreAttributeChange_MaxCharge(float& NewValue);



	void OnHealthModified(const FGameplayEffectModCallbackData& Data);
};
