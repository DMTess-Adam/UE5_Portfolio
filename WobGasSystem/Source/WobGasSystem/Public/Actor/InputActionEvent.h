// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ActionEventTypes.h"
#include "GameplayTags.h"
#include "InputMappingContext.h"
#include "InputActionEvent.generated.h"


DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnEventComplete, const bool, bSuccess);

UCLASS()
class WOBGASSYSTEM_API AInputActionEvent : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AInputActionEvent();

	UFUNCTION(BlueprintCallable)
	float GetDuration() { return Duration; };

	UPROPERTY(BlueprintAssignable, BlueprintCallable)
	FOnEventComplete OnEventCompleteDelegate;

	// start the event, binding input events from the target player controller.
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void StartEvent(APlayerController* TargetPlayerController);

	// stop the event early. 
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void StopEvent(const bool bEndSuccessfully);

	UFUNCTION(BlueprintCallable, BlueprintPure)
	bool IsEventActive() { return bEventActive; };

	UFUNCTION(BlueprintNativeEvent)
	void OnInput(const FInputActionValue& Value);

	// true if the event is not ongoing and was completed successfuly.
	UFUNCTION(BlueprintCallable)
	bool WasSuccessful() { return !bEventActive && bEventSuccessful; };

protected:
	
	//Gameplay tag to use as actor event when the event finishes. this is sent to the EventInstigator by default when the event completes.
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (ExposeOnSpawn = "true"))
	FGameplayTag EventEndTag;

	//Game time seconds when the event started
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere)
	float EventStartTime{ 0.f };

	// Reference to the actor that spawned the event.
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (ExposeOnSpawn = "true"))
	TObjectPtr<AActor> EventInstigator;

	UPROPERTY()
	TObjectPtr<APlayerController> BoundPlayerController;

	// binds the input actions for the input mapping context, filtering the correct input to the OnCorrectInput and all other inputs to OnIncorrectInput
	void BindInputListeners(APlayerController* TargetPlayerController, UInputAction* CorrectAction);

	UFUNCTION(BlueprintNativeEvent)
	void OnCorrectInput(const FInputActionValue& Value);
	virtual void OnCorrectInput_Implementation(const FInputActionValue& Value) {};

	UFUNCTION(BlueprintNativeEvent)
	void OnIncorrectInput(const FInputActionValue& Value);
	virtual void OnIncorrectInput_Implementation(const FInputActionValue& Value) {};

	// the mapping context that is used for Input Actions.
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Settings", meta=(ExposeOnSpawn="true"))
	TObjectPtr<UInputMappingContext> InputMappingContext;

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, meta = (ExposeOnSpawn = "true"))
	EActionEventTypes EventType{ EActionEventTypes::Sequence };

	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (ExposeOnSpawn = "true"))
	float Duration{ 5.0f };

	// this is the input action that is expected to be input. any other action from the mapping context will be considered incorrect.
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (ExposeOnSpawn = "true"))
	TObjectPtr<class UInputAction> ExpectedInputAction;

	UFUNCTION(BlueprintNativeEvent)
	void OnEventStarted();
	virtual void OnEventStarted_Implementation() {};

	UFUNCTION(BlueprintNativeEvent)
	void OnEventStoppedEarly();
	virtual void OnEventStoppedEarly_Implementation() {};
	
	UFUNCTION(BlueprintNativeEvent)
	void OnEventComplete(const bool bSuccessful);
	virtual void OnEventComplete_Implementation(const bool bSuccessful);

	UFUNCTION()
	void OnEventDurationExpired();

	//Is the event live?
	UPROPERTY()
	bool bEventActive;

	// true if the event was completed successfully by the target
	UPROPERTY()
	bool bEventSuccessful;

	UFUNCTION(BlueprintCallable)
	void CompleteEvent(const bool bSuccess) { OnEventCompleteDelegate.Broadcast(bSuccess); return; };

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	FTimerHandle EventTimer;


public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
