// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "WOBAbilityComponent.generated.h"


// attribute value specific delegates
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FDamageTaken, const float&, Damage);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTerrorTaken, const float&, Terror);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FZeroHealth);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnGainedExperience, const float&, Amount);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnLevelUp, const float&, NewLevel);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnMaxTerror);

// ambiguous attribute change delegates. These only announce that a value has just been changed in any way and report the current value.
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnHealthChanged, const float&, NewValue);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMaxHealthChanged, const float&, NewValue);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMovementSpeedRateChanged, const float&, NewValue);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnTerrorChangedChanged, const float&, NewValue);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnActiveTerrorEvent, const bool, bIsActive);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnCinematicCameraEvent, const bool, bIsActive);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnStunnedTagEvent, const bool, bIsActive);

/**
 * 
 */
UCLASS(Blueprintable, meta = (BlueprintSpawnableComponent))
class WOBGASSYSTEM_API UWOBAbilityComponent : public UAbilitySystemComponent
{
	GENERATED_BODY()
	
public :

	void InitializeComponent() override;

	/* ---- DELEGATES ----
 These are triggered via PostGameplayEffectExecute when appropriate scenarios are evaluated.
 Used to broadcast certain events off the back of executions. These are used to effect gameplay
 when certain attributes are modified or hit certain conditions, such as health reaching zero.
 It's also possible to build combat logs out of data captured from executions if desired.
*/
	UPROPERTY(BlueprintAssignable)
	FDamageTaken OnDamageTaken;

	UPROPERTY(BlueprintAssignable)
	FOnActiveTerrorEvent OnActiveTerrorEvent;

	UPROPERTY(BlueprintAssignable)
	FTerrorTaken OnTerrorTaken;

	UPROPERTY(BlueprintAssignable)
	FOnCinematicCameraEvent OnCinematicCameraEvent;

	UPROPERTY(BlueprintAssignable)
	FZeroHealth OnZeroHealth;

	UPROPERTY(BlueprintAssignable)
	FOnGainedExperience OnGainExperience;

	UPROPERTY(BlueprintAssignable)
	FOnLevelUp OnLevelUp;

	UPROPERTY(BlueprintAssignable)
	FOnMovementSpeedRateChanged OnMovementSpeedRateChanged;

	UPROPERTY(BlueprintAssignable)
	FOnMaxTerror OnMaxTerror;

	UPROPERTY(BlueprintAssignable)
	FOnHealthChanged OnHealthChanged;

	UPROPERTY(BlueprintAssignable)
	FOnMaxHealthChanged OnMaxHealthChanged;

	UPROPERTY(BlueprintAssignable)
	FOnStunnedTagEvent OnStunnedTagEvent;


	UFUNCTION(BlueprintCallable, Category="Gameplay Effects")
	void ApplyInjuredMovement();


	virtual FGameplayEffectContextHandle MakeCustomEffectContext();

	// returns the first active instance of the ability class specified. or none if not found. 
	UFUNCTION(BlueprintCallable, Category="Gameplay Abilities")
	bool GetActiveAbilityByClass(const TSubclassOf<UWobGasAbilityBase> Class, class UWobGasAbilityBase*& ActiveAbility);

	// Tries to activate an ability, setting targetactor data. Always fails if the class is not a subclass of UWobGasAbilityBase and instancing policy is not per-actor.
	UFUNCTION(BlueprintCallable, Category="Gameplay Abilities")
	bool TryActivateAbilityWithTargetData(const TSubclassOf<UWobGasAbilityBase> Class, AActor* TargetActor);

protected:

	// The gameplay tag that should represent when a player is currently in a fear aura.
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Gameplay Tags")
	FGameplayTag ActiveTerrorGameplayTag;

	UFUNCTION(BlueprintNativeEvent) 
	void OnShriekTagChanged(const FGameplayTag Tag, int32 NewCount);

	// The gameplay tag that should represent when a players camera is being controlled by an external source.
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Gameplay Tags")
	FGameplayTag CinematicCameraGameplayTag;

	UFUNCTION(BlueprintNativeEvent)
	void OnCinematicCameraTagChanged(const FGameplayTag Tag, int32 NewCount);

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Passive Gameplay Effects")
	UGameplayEffect* InjuredMovementSpeedEffect;

	// The gameplay tag that should represent when an actor is currently stunned.
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Gameplay Tags")
	FGameplayTag ActiveStunGameplayTag;

	UFUNCTION(BlueprintNativeEvent)
	void OnStunnedTagChanged(const FGameplayTag Tag, int32 NewCount);


	void HandleAttributeChanged(const FOnAttributeChangeData& Data);

private:

	UPROPERTY()
	FGameplayEffectSpecHandle InjuredMovementHandle;
};
