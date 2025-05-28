// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "ActorComponent/NpcDialogComponent.h"
#include <Sound/SoundBase.h>
#include "DialogManagerSubsystem.generated.h"




DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnNewSequence, const FNpcDialogSequence&, Sequence);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnSequenceFinished, const FNpcDialogSequence&, Sequence);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnDialogEnded);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnDialogStarted);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnSubtitleDialogPlay, USoundBase*, SoundFile);

/**
 * 
 */
UCLASS()
class RPGDIALOGSYSTEM_API UDialogManagerSubsystem : public UWorldSubsystem
{
	GENERATED_BODY()
	
public:

	//Delegate for when an NPC has started playing an audio file that supports the subtitle system.
	UPROPERTY(BlueprintAssignable, BlueprintCallable, Category = "Delegates")
	FOnSubtitleDialogPlay OnSubtitleAudioPlay;

	UPROPERTY(BlueprintAssignable, BlueprintCallable, Category="Delegates")
	FOnNewSequence OnNewSequenceDelegate;

	UPROPERTY(BlueprintAssignable, BlueprintCallable, Category = "Delegates")
	FOnSequenceFinished OnSequenceFinishedDelegate;

	UPROPERTY(BlueprintAssignable, BlueprintCallable, Category = "Delegates")
	FOnDialogEnded OnDialogEndedDelegate;

	UPROPERTY(BlueprintAssignable, BlueprintCallable, Category = "Delegates")
	FOnDialogStarted OnDialogStartedDelegate;

	UFUNCTION(BlueprintCallable, Category ="Subtitles")
	void NotifySubtitleFilePlaying(USoundBase* SoundFile)
	{
		OnSubtitleAudioPlay.Broadcast(SoundFile);
	}

	UFUNCTION(BlueprintCallable, Category ="Dialog Manager")
	TArray<FDialogChoice> GetCurrentSequenceQualifiedChoices();

	UFUNCTION(BlueprintCallable, Category="Dialog Manager")
	void RegisterNewInteraction(AActor* DialogNPC);

	UFUNCTION(BlueprintCallable, Category="Dialog Manager")
	void NewSequence(struct FNpcDialogSequence Sequence);

	UFUNCTION(BlueprintCallable, Category="Dialog Manager")
	void SequenceFinished(struct FNpcDialogSequence sequence);

	//Skips to the end of the currently playing sequence, if one is playing.
	UFUNCTION(BLueprintCallable, Category="Dialog Manager")
	void SkipSequence();

	/*Dispatch the next sequence by the given ID.NOTE: Typically you should use SelectDialogChoice and pass in the choice struct
	 for full functionality, including script execution. */ 
	UFUNCTION(BlueprintCallable, Category="Dialog Manager")
	void MakeDialogOptionSelection(const int SelectionIndex);

	UFUNCTION(BlueprintCallable, Category="Dialog Manager")
	void EndCurrentDialog();

	UFUNCTION(BlueprintCallable, Category ="Dialog Manager")
	bool IsDialogActive() { return bDialogIsActive; };

	/* Use this as the default option for submitting a dialog choice when you have the full struct available. Executes any script events before invoking the next sequence.
	*/
	UFUNCTION(BlueprintCallable, Category="Dialog Manager")
	void SelectDialogChoice(FDialogChoice Choice);


private:

	void GiveQuests(APawn* TargetPawn, const TArray<FName> Quests);

	void RemoveQuests(APawn* TargetPawn, const TArray<FName> Quests);

	void CompleteQuests(APawn* TargetPawn, const TArray<FName> Quests);

	void GiveItems(APawn* TargetPawn, const TMap<FName, int> Items);

	void RemoveItems(APawn* TargetPawn, const TMap<FName, int> Items);

	void DistributeSequenceQuestsAndItems(const FNpcDialogSequence& Sequence);

	void DistributeDialogChoiceQuestsAndItems(const FDialogChoice& DialogChoice);

	bool bDialogIsActive{ false };

	bool GetPlayerPawnInterfaced(APawn*& OutPawn);

	class UNpcDialogComponent* GetActiveNPCDialogComponent();

	FNpcDialogSequence ActiveSequence;

	UPROPERTY()
	TSubclassOf<UDialogScriptEventBase> OnEndScriptEvent;

	TObjectPtr<AActor> ActiveDialogNPC;



};
