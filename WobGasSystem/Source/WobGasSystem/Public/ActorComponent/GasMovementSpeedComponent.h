// Copyright - DMTesseracT

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "GameplayEffect.h"
#include "GasMovementSpeedComponent.generated.h"

class UAbilitySystemComponent;
struct FOnAttributeChangeData;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class WOBGASSYSTEM_API UGasMovementSpeedComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UGasMovementSpeedComponent();

	// movement attribute change response, bound to appropriate delegate in attributes.
	void OnMovementChanged(const FOnAttributeChangeData& Data);

	void OnHealthChanged(const FOnAttributeChangeData& Data);

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	UPROPERTY(BlueprintReadOnly, Category="Ability System Component")
	TWeakObjectPtr<UAbilitySystemComponent> OwnerASC;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Settings")
	float BaseMovementSpeed{ 400.f };

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Settings")
	TSubclassOf<UGameplayEffect> InjuredEffect;

	UPROPERTY()
	FActiveGameplayEffectHandle ActiveInjuredEffectHandle;

	// update movement speed, fetches the movement rate from the attribute set then applies it in the calculation for movement speed. 
	void UpdateMovementSpeed();

	// update movement speed to the given value. The value should be the current attribute value. If you don't have it, use the overloaded function with no args.
	void UpdateMovementSpeed(const float& NewRate);

private:

	UPROPERTY()
	bool bInitialised;


public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
};
