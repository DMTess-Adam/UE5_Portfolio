// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AbilitySystemInterface.h"
#include "Interface/WobGasInterface.h"
#include "Blueprint/UserWidget.h"
#include "WobGasCharacter.generated.h"

UCLASS()
class WOBGASSYSTEM_API AWobGasCharacter : public ACharacter, public IAbilitySystemInterface, public IWobGasInterface
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AWobGasCharacter();

	virtual class UAbilitySystemComponent* GetAbilitySystemComponent() const override;

	virtual void InitialiseAttributes();

	virtual void GiveAbilities();

	virtual void PossessedBy(AController* NewController) override;

	virtual void OnRep_PlayerState() override;

	/* WobGasInterface */

	UFUNCTION(BlueprintImplementableEvent, Category = "Attribute Events")
	void OnDeath();


	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category="Interact")
	AActor* GetInteractTarget();

	virtual void Landed(const FHitResult& Hit) override;

	// Queries the appropriate forward vector for a character.  Required to get correct forward vectors for HMDs rather than the standard actor forward vector, without
	// forcing specific dependencies into the module.
	FVector GetCorrectForwardVector_Implementation() { return GetActorForwardVector(); };

	TArray<TSubclassOf<UAttributeSet>> GetAssignedAttributeSets_Implementation() { return AssignedAttributeSets; };

protected:

	//Specific attribute sets that should be initialised on the ability component
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category ="Attributes")
	TArray<TSubclassOf<UAttributeSet>> AssignedAttributeSets;

	UFUNCTION(BlueprintNativeEvent, Category="Attribute Events")
	void OnMovementSpeedRateChanged(const float& NewValue);

	/*Handles returning the view camera to its default location post cinematic event.This is to ensure that any camera manipulation that may happen
	 during any abilities restores the camera view to the appropriate parent and offset once the event has ended.
	 */
	UFUNCTION(BlueprintNativeEvent, Category = "Attribute Events")
	void OnCinematicCameraEvent(const bool bIsTagActive);

	// This is the base movement speed in cm/s that walking movement speed is calculated from, this value is multiplied by the current MovementSpeedRate attribute.
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Attributes")
	float BaseWalkMovementSpeed{ 350.f };

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Attributes")
	float BaseCrouchedMovementSpeed{ 250.f };

	// Minimum distance the character must fall before taking fall damage. 
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Falling")
	float FallDistanceThreshold;

	//The base fall damage value. Final damage is calculated as BaseFallDamage * (FallDistance/Threshold) * Multiplier.
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Falling")
	float BaseFallDamage{ 10 };

	// Multiplier for final fall damage calculation. Damage is calculated as BaseFallDamage * (FallDistance/Threshold) * Multiplier.
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Falling")
	float FallDamageScaleMultiplier{ 1 };

	virtual void OnMovementModeChanged(EMovementMode PrevMovementMode, uint8 PreviousCustomMode) override;

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintNativeEvent)
	void OnStartedFall();


	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category="Component")
	TObjectPtr<class UCameraComponent> ViewCamera;

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category="Component")
	TObjectPtr<class UWidgetInteractionComponent> WidgetInteraction;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Component", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<class UWOBAbilityComponent> AbilitySystemComponent;

	UPROPERTY()
	TObjectPtr<class UWobGasAttributes> Attributes;

	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "GAS")
	TSubclassOf<class UGameplayEffect> DefaultAttributeEffect;

	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "GAS")
	TArray<TSubclassOf<class UWobGasAbilityBase>> DefaultAbilities;

	UFUNCTION(BlueprintCallable, Category="Menu")
	void ToggleMenu_2D();

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category ="Main Menu")
	TSubclassOf<UUserWidget> MainMenuClass;
	
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	virtual void OnConstruction(const FTransform& Transform) override;

private:

	UPROPERTY()
	FVector ViewCameraDefaultLocation;

	UPROPERTY()
	FRotator ViewCameraDefaultRotation;

	UPROPERTY()
	float FallStartZ;

	TObjectPtr<UUserWidget> MenuInstance;
	
	// Binds any events to the attribute event delegates defined in WOBAbilityComponent
	virtual void BindAttributeListeners() const;
};
