// Copyright - DMTesseracT

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "GameplayTags.h"
#include "DesktopEnhancedInputComponent.generated.h"

class UAbilitySystemComponent;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class WOBGASSYSTEM_API UDesktopEnhancedInputComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UDesktopEnhancedInputComponent();

	UFUNCTION(BlueprintCallable, Category ="Enhanced Input")
	void AddMovement(const FVector2D& InVector);

	UFUNCTION(BlueprintCallable, Category = "Enhanced Input")
	void AddCameraLook(const FVector2D& InVector);

	UFUNCTION(BlueprintCallable, Category = "Enahnced Input")
	void Jump();

	UFUNCTION(BlueprintCallable, Category ="Enhanced Input")
	void Crouch();


protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	ACharacter* GetOwnerCharacter();

	UAbilitySystemComponent* GetOwnerAbilitySystem();

	bool GetOwnerAndAbilitySystemComponent(ACharacter*& OwnerChar, UAbilitySystemComponent*& AbilitySystem);

	// returns true if the owner does not have any of the given tags. false otherwise, or if the owner / ability system are invalid.
	bool OwnerDoesNotHaveAnyTags(FGameplayTagContainer Tags);

	// returns true if the owner has any of the given tags. false if not, or if the owner / ability system are invalid.
	bool OwnerHasAnyTags(FGameplayTagContainer Tags);

	bool OwnerHasTag(FGameplayTag Tag);

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
};
