// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Actor/InputActionEvent.h"
#include "InputActionEvent_Sequence.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnSequenceInput, const bool, bCorrectInput);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnNewSequenceStep, UInputAction*, ExpectedInput);

USTRUCT(BlueprintType)
struct FInputSequenceData
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TMap<UInputAction*, USoundBase*> ActionSoundMap;

};
/**
 * 
 */
UCLASS()
class WOBGASSYSTEM_API AInputActionEvent_Sequence : public AInputActionEvent
{
	GENERATED_BODY()
	
	AInputActionEvent_Sequence();

public:

	UPROPERTY(blueprintAssignable, BlueprintCallable)
	FOnSequenceInput OnSequenceInput;

	UPROPERTY(blueprintAssignable, BlueprintCallable)
	FOnNewSequenceStep OnNewSequenceStep;

	virtual void OnCorrectInput_Implementation(const FInputActionValue& Value) override;

	virtual void OnIncorrectInput_Implementation(const FInputActionValue& Value) override;

	virtual void StartEvent_Implementation(APlayerController* TargetPlayerController) override;

	UFUNCTION(BlueprintCallable)
	FInputSequenceData GetSequenceAudioData() { return SequenceAudioData; };

	UFUNCTION(BlueprintCallable)
	TArray<UInputAction*> GetInputSequence() { return InputSequence; };

protected:

	UFUNCTION(BlueprintCallable)
	void NextStepInSequence();

	UFUNCTION(BlueprintCallable)
	void SetExpectedActionInput(UInputAction* Action);

	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (ExposeOnSpawn = "true"))
	TObjectPtr<class UUIActionEventAudioData> AudioData;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (ExposeOnSpawn = "true"))
	TArray<TObjectPtr<UInputAction>> InputSequence;

	// Audio data associated with UI action inputs.
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (ExposeOnSpawn = "true"))
	FInputSequenceData SequenceAudioData;

private:

	int NextInputIndex{ 0 };
};
