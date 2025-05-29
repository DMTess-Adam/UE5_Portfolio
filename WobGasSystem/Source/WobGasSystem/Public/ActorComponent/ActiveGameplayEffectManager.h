// Copyright - DMTesseracT

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ActiveGameplayEffectManager.generated.h"

class UWOBAbilityComponent;
class UGameplayEffect;

USTRUCT()
struct FWobActiveEffectsData
{
	GENERATED_BODY()

	UPROPERTY()
	TSubclassOf<UGameplayEffect> EffectClass;

	UPROPERTY()
	float Duration = 0.0f;

	UPROPERTY()
	bool bIsInfinite = false;

	UPROPERTY()
	int32 NumStacks = 1;

	bool operator == (const TSubclassOf<UGameplayEffect> Comparator) const
	{
		return EffectClass == Comparator;
	}

	FWobActiveEffectsData() {};

	FWobActiveEffectsData(TSubclassOf<UGameplayEffect> _EffectClass, const float _Duration, const bool _bIsInfinite, const int32 _NumStacks) 
	{
		EffectClass = _EffectClass;
		Duration = _Duration;
		bIsInfinite = _bIsInfinite;
		NumStacks = _NumStacks;
	}
};

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class WOBGASSYSTEM_API UActiveGameplayEffectManager : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UActiveGameplayEffectManager();

	UFUNCTION(BlueprintCallable, Category ="Active Effects Data")
	void PrepareForSave();

	//Should be used when reloading a save game to restore effects data.
	UFUNCTION()
	void LoadState(const TArray<FWobActiveEffectsData> RestoreData);

	UFUNCTION()
	TArray<FWobActiveEffectsData> GetActiveEffects() { return ActiveEffects; };

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	UPROPERTY()
	TObjectPtr<UWOBAbilityComponent> OwnerAbilityComp;

	UPROPERTY()
	TArray<FWobActiveEffectsData> ActiveEffects;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
};
