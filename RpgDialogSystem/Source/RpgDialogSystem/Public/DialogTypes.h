// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DialogTypes.generated.h"

class ULevelSequence;
class UAnimationAsset;
class UDialogScriptEventBase;

UENUM()
enum class EQuestState : uint32
{
	NOT_STARTED,
	IN_PROGRESS,
	COMPLETED
};


/* list of data points that are triggered at varying points in dialog.Used for grouping quest and item modification activity during dialog sequences.
* these are generally triggered at the start of a new sequence and when a dialog option is selected.
*/
USTRUCT(BlueprintType)
struct FNpcDialogEventData
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Triggered Events")
	TArray<FName> GivesQuests;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Triggered Events")
	TArray<FName> CompletesQuests;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Triggered Events")
	TArray<FName> RemovesQuests;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Triggered Events")
	TMap<FName, int> GivesItems;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Triggered Events")
	TMap<FName, int> RemovesItems;
};

USTRUCT(BlueprintType)
struct FDialogChoice
{
	GENERATED_BODY()

	// the text to display as the dialog choice.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (WrapText = "true"))
	FText DisplayText;

	// Conditions for each choice presented to the player at the end of the sequence. (e.g., "HasQuest:1")
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FString> QualifyingConditions;

	// Dialog Script events to dispatch when this option is selected.
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<TSubclassOf<UDialogScriptEventBase>> ScriptEvents;

	// index of the next sequence this dialog should trigger. -1 will end the dialog.
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 NextSequenceIndex{ -1 };

	// list of Key/Value pairs to apply to the NPC's dialog states when this choice is selected.
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TMap<FString, bool> DialogStateModifiers;

	//Inventory and quest events triggered when the Dialog choice is selected
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Triggered Events")
	FNpcDialogEventData ChoiceEventData;
};


USTRUCT(BlueprintType)
struct FNpcDialogSequence
{
	GENERATED_BODY()

	/* If true, this sequence is considered viable as an initial dialog sequence, and it's QualifyingConditions will be assessed
	when the dialog interaction is initiated. if qualified, it will be selected to play if its priority is highest of all qualified sequences.
	Sequences that are specifically triggered by dialog options should set this to false.
	*/
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Qualification")
	bool bConsideredForDialogStart;

	// Priority that this sequence has when being considered for the initial dialog. Highest priority will be selected.
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Qualification", meta = (EditCondition = "bConsideredForDialogStart"))
	int SelectionPriority{ 1 };

	/* list of dialog conditions that must be met for this dialog to be allowed to play. Usually only relevant
	 to sequences that are not initiated from previous dialog options (such as starting a new dialog interaction).
	 Default implementations do not care about these conditions when a sequence is selected from a player dialog choice,
	 since their viability should already be evaluated from the ChoiceConditions.
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Qualification", meta = (EditCondition = "bConsideredForDialogStart"))
	TArray<FString> QualifyingConditions;

	/*Level sequence to instantiate and play. */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LevelSequence")
	TObjectPtr<ULevelSequence> LevelSequence;

	// Text version of the dialog in the sequence. 
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Dialog")
	FText DialogText;

	// Multiple choice options for the player, presented at the end of the sequence
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Dialog Options")
	TArray<FDialogChoice> PlayerChoices;

	// if a positive integer, will go to this sequence immediately after this sequence ends, bypassing any dialog options.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Dialog Settings")
	int AutoSelectNextSequence{ -1 };

	//Inventory and quest events triggered when the sequence starts
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Triggered Events")
	FNpcDialogEventData SequenceEventData;

	//When this sequence is played, the owning NPC will execute the script specified below when the dialog ends. This will be overridden if subsequent sequences play and specify a script.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Triggered Events")
	TSubclassOf<UDialogScriptEventBase> DialogEndScriptEvent;

};