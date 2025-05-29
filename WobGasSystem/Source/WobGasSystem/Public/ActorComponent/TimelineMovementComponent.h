// Copyright - DMTesseracT

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AbilitySystemInterface.h"
#include "Components/TimelineComponent.h"
#include "Data/CharacterMovementData.h"
#include "TimelineMovementComponent.generated.h"



DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnCrouchTick, FVector&, Value);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnCrouchFinished);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnForwardDashTick, float&, Value);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnForwardDashFinished);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class WOBGASSYSTEM_API UTimelineMovementComponent : public UActorComponent
{
	GENERATED_BODY()



protected:

	UTimelineMovementComponent();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	ACharacter* GetOwnerCharacter();

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Config")
	TObjectPtr<UCharacterMovementData> MovementData;

public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;


	// ==== Crouch ====
	/* Note: Due to the way crouching is implemented differently between characters,
	* its up to the individual implementations to apply the output from crouch timelines appropriately.
	* You should bind to the OnCrouchTick delegate and apply the output value.
	*/
public:

	UFUNCTION()
	void Crouch();

	UPROPERTY(BlueprintAssignable)
	FOnCrouchTick OnCrouchTick;

	UPROPERTY(BlueprintAssignable)
	FOnCrouchFinished OnCrouchFinished;

	// Tick implementation for crouch timeline.
	UFUNCTION()
	void CrouchTimelineProgress(float Value);

	// Returns if this component thinks the owning character is crouched.
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Movement|Crouch")
	bool IsCrouched() { return bIsCrouched; };

protected:
	FTimeline CrouchCurveFTimeline;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Movement|Crouch")
	UCurveFloat* CrouchCurveFloat;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Movement|Crouch")
	FVector CrouchStartLoc{ FVector(0) };

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Movement|Crouch")
	FVector CrouchEndLoc{ FVector(0,0,-40.f) };


	bool bIsCrouched;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Movement|Crouch")
	float CapsuleStandingHalfHeight{96.f};


	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Movement|Crouch")
	float CapsuleCrouchHalfHeight{ 30.f };
	// === End Crouch ===


	// === Forward Dash ===

public:

	UFUNCTION(BlueprintCallable, Category = "Movement|ForwardDash")
	void ForwardDash();

	UPROPERTY(BlueprintAssignable)
	FOnForwardDashTick OnForwardDashTick;

	UPROPERTY(BlueprintAssignable)
	FOnForwardDashFinished OnForwardDashFinished;

	UFUNCTION()
	void ForwardDashTimelineProgress(float Value);

	UFUNCTION()
	void ForwardDashFinished();

protected:

	FTimeline ForwardDashFTimeline;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Movement|ForwardDash")
	UCurveFloat* ForwardDashCurveFloat;

	// The max time between taps to instigate Dash (Double tap grace period).
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Movement|ForwardDash")
	float DashDoubleTapInterval{ 0.3f };

	// The minimum amount of time (in seconds) between dash activations.
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Movement|ForwardDash")
	float MinimumTimeBetweenDash{ 1.0f };

	// the last time an input was registered to the dash input, used to calculate double tap activation
	float LastDashInstigatedTime;

	// the last time the dash was actually activated, used to restrict successive activations.
	float LastDashActivationTime;
};
