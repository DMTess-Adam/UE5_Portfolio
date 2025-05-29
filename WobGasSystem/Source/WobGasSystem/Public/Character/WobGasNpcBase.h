// Copyright - DMTesseracT

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AbilitySystemInterface.h"
#include "Interface/WobGasInterface.h"
#include "WobGasNpcBase.generated.h"

UCLASS()
class WOBGASSYSTEM_API AWobGasNpcBase : public ACharacter, public IAbilitySystemInterface, public IWobGasInterface
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AWobGasNpcBase();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	virtual class UAbilitySystemComponent* GetAbilitySystemComponent() const override;

	virtual void InitialiseAttributes();

	virtual void GiveAbilities();

	virtual void PossessedBy(AController* NewController) override;

	//Invoked when health changes. Default implementation handles invoking OnDeath function when health hits zero.
	UFUNCTION(BlueprintNativeEvent, Category ="Attribute Events")
	void OnHealthChanged(const float& NewValue);

	virtual void DisplayDebug(UCanvas* Canvas, const FDebugDisplayInfo& DebugDisplay, float& YL, float& YPos) override;

	UFUNCTION(BlueprintNativeEvent, Category = "Attribute Events")
	void OnMovementSpeedRateChanged(const float& NewValue);

	TArray<TSubclassOf<UAttributeSet>> GetAssignedAttributeSets_Implementation() { return AssignedAttributeSets; };

protected:

	UFUNCTION(BlueprintImplementableEvent, Category ="Debug")
	TArray<FString> GetDebugLines();

	UFUNCTION(BlueprintNativeEvent)
	void OnStunnedStateChange(const bool bIsActive);

	//Specific attribute sets that should be initialised on the ability component
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Attributes")
	TArray<TSubclassOf<UAttributeSet>> AssignedAttributeSets;

	void BindAttributeListeners();

	UFUNCTION(BlueprintImplementableEvent, Category ="Attribute Events")
	void OnDeath();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	TObjectPtr<class UWOBAbilityComponent> AbilitySystemComp;

	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "GAS")
	TSubclassOf<class UGameplayEffect> DefaultAttributeEffect;

	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "GAS")
	TArray<TSubclassOf<class UWobGasAbilityBase>> DefaultAbilities;

	//  Base walk speed (cm/s) for this npc. Final speed is calculated by multiplying this value with current MovementSpeedRate attribute.
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Attributes")
	float BaseWalkSpeed{ 350.f };
	

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
