// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "DialogTypes.h"
#include "DataAsset/RpgDialogSequenceData.h"
#include "NpcDialogComponent.generated.h"

class ULevelSequence;
class UAnimationAsset;
class UDialogScriptEventBase;



UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class RPGDIALOGSYSTEM_API UNpcDialogComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UNpcDialogComponent();

	/*Starts dialog event. If a sequence is set, it should engage the dialog event. If not, it'll fall back to
	generic dialog if it's set. Otherwise it will do nothing.
	*/
	UFUNCTION(BlueprintCallable, Category="Dialog")
	void BeginInteract();

	UFUNCTION(BlueprintCallable, Category = "Dialog")
	bool CanStartADialog();

	UFUNCTION(BlueprintCallable, Category="Dialog")
	TArray<FDialogChoice> FilterQualifiedChoices() { return GetValidDialogChoices(CurrentDialogSequence); };

	UFUNCTION(BlueprintCallable, Category="Dialog")
	bool CheckDialogCondition(const FString Condition);

	UFUNCTION()
	void OnSequenceFinished();

	UFUNCTION(BlueprintCallable, Category = "Dialog")
	void PlaySequenceAtIndex(const int Index);

	UFUNCTION(BlueprintCallable, Category ="Dialog")
	void AddDialogState(const FString Key, const bool Value) 
	{
		DialogStateModifiers.Add(Key, Value);
	};

	//immediately stop a sequence that's currently playing, optionally calling the SequenceFinished as if it finished naturally. if false, no notify is sent that the sequence ended.
	UFUNCTION(BlueprintCallable, Category ="Dialog")
	void StopCurrentSequence(const bool bCallSequenceFinished);

protected:

	// Called when the game starts
	virtual void BeginPlay() override;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Dialog")
	URpgDialogSequenceData* DialogSequences;



	UPROPERTY()
	TObjectPtr<class ULevelSequencePlayer> ActivePlayer;

	/* Audio file to play when no dialog interactions are available - This is typical passive speech that will play
	that won't capture the players control. */
	UPROPERTY(blueprintReadWrite, EditAnywhere, Category="Dialog")
	TObjectPtr<class USoundBase> DefaultAudioOnlyInteract;

	// internal state to allow full cinematic dialog or to just play an audio file.
	UPROPERTY()
	bool bUseAudioOnly;

	UPROPERTY() 
	FNpcDialogSequence CurrentDialogSequence;

	// Instanced copy of Dialog State for this components owner. This is to prevent the data assets state from being overwritten.
	UPROPERTY()
	TMap<FString, bool> DialogStateModifiers;

private:

	// invoke DialogSequenceStart on owner.
	void BeginDialog();

	// invoke DialogSequenceEnded on owner.
	void EndDialog();

	// do not call this directly. use PlaySequenceAtIndex to ensure the internal state maintains integrity.
	void PlaySequence(ULevelSequence* Sequence);

	// split a full condition string into its key/values
	bool SplitCondition(const FString ConditionString, FString& TypeOut, FString& ValueOut);

	// split a condition value into its Id/Count values.
	bool SplitValue(const FString Value, FString& IdOut, FString& NumOut);

	// get player pawn with interface qualification
	bool GetPlayerPawn(APawn*& OutPawn);

	// get owner with interface qualification
	bool GetOwnerWithInterface(AActor*& OwnerActor);

	TArray<FDialogChoice> GetValidDialogChoices(FNpcDialogSequence Node);

	void OnSequenceInitialised(FNpcDialogSequence sequence);

	class DialogManagerSubsystem* GetDialogManager();



public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
};
