// Copyright - DMTesseracT

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AbilitySystemInterface.h"
#include "GameplayEffectTypes.h"
#include "GameplayTagContainer.h"
#include "GasVolume.generated.h"

UENUM()
enum EAuraVolumeType
{
	None,
	Box,
	Sphere,
	Capsule,
};

USTRUCT(BlueprintType)
struct FAuraBoxConfig
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FVector Extent{FVector(50,50,50)};
};

USTRUCT(BlueprintType)
struct FAuraSphereConfig
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float Radius{50.0f};
};

USTRUCT(BlueprintType)
struct FAuraCapsuleConfig
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float Radius{10.f};

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float halfHeight{44.f};
};

class UGameplayEffect;
class UWOBAbilityComponent;

/*A volume with a customisable shape that applies a specified gameplay effect on any pawns in it's volume on each tick. Useful for creating Auras/Area effects */
UCLASS(PrioritizeCategories = "Settings")
class WOBGASSYSTEM_API AGasVolume : public AActor, public IAbilitySystemInterface
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AGasVolume();

	virtual class UAbilitySystemComponent* GetAbilitySystemComponent() const override;

	/*Explicitly enable the gas volume tick, enabling the aura. */
	UFUNCTION(BlueprintCallable, Category = "State")
	void EnableAura();

	/*Explicitly disable the gas volume tick, turning off this aura */
	UFUNCTION(BlueprintCallable, Category = "State")
	void DisableAura();

	/*Toggle this gas volume's tick. Useful if you don't know the current state and want to ensure switching to the opposite state. i.e. on/off buttons etc. */
	UFUNCTION(BlueprintCallable, Category = "State")
	void ToggleAura();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "Component")
	TObjectPtr<USceneComponent> RootSceneComponent;

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "Component")
	TObjectPtr<UWOBAbilityComponent> AbilityComponent;
	
	/* The shape to create for the volume */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Settings|Shape")
	TEnumAsByte<EAuraVolumeType> VolumeShapeType{EAuraVolumeType::Box};

	/* The appropriate shape component as specified by VolumeShapeType. Automatically created OnConstruction */
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "Component")
	TObjectPtr<UShapeComponent> VolumeShapeComponent;

	/* The Aura tick frequency */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Settings")
	float TickFrequency{0.2};

	/*The gas effect to apply every tick */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Settings|Effect")
	TSubclassOf<UGameplayEffect> GameplayEffect;
	
	/*The spec created for the effect that this actor applies. Setup once on construction and reused throughout runtime. */
	UPROPERTY()
	FGameplayEffectSpecHandle EffectSpecHandle;

	/*Per spec overridable magnitude modifiers. If the gameplay effect specified has SetByCaller magnitude values, you must list them here so that they are 
	updated appropriately. Failing to apply the expected SetByCaller values will result in runtime errors. */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(Categories="AttributeEffects"), Category = "Settings|Effect")
	TMap<FGameplayTag, float> MagnitudeModifiers;

	/* Box configuration */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Settings|Shape|Shape Settings", meta=(EditCondition="VolumeShapeType == EAuraVolumeType::Box", EditConditionHides))
	FAuraBoxConfig BoxConfig;

	/* Sphere configuration */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Settings|Shape|Shape Settings", meta = (EditCondition = "VolumeShapeType == EAuraVolumeType::Sphere", EditConditionHides))
	FAuraSphereConfig SphereConfig;

	/* Cpasule configuration */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Settings|Shape|Shape Settings", meta = (EditCondition = "VolumeShapeType == EAuraVolumeType::Capsule", EditConditionHides))
	FAuraCapsuleConfig CapsuleConfig;

	virtual void OnConstruction(const FTransform& Transform) override;

	void PostEditChangeProperty(struct FPropertyChangedEvent& e) override;
private:

	/*Internal function for creating the appropriate shape component. handles setting up the desired shape and bounds settings on construction. */
	void SetupVolume();

	/*Construction function that is used to apply config changes to the volume component without replacing it. Used when the volume type hasn't changed between construct calls */
	void UpdateVolumeBounds();

	/* Reference to previously used */
	TEnumAsByte<EAuraVolumeType> PreviousShapeType;

	void ApplyAura();

	void SetMagnitudesInSpec(FGameplayEffectSpecHandle& SpecHandle);

	void BuildAttributeMagnitudeMap();

	void MakeEffectSpec();

	/*Attempts to find a SetBycaller magnitude for the given data tag on the gameplay effect spec. Returns true if the returned value is not 0. */
	bool GetSetByCallerAttributeMagnitude(const FGameplayTag DataTag, float& Value);


public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
