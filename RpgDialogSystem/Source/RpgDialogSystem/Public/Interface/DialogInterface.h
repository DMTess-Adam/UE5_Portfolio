// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "DialogInterface.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UDialogInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class RPGDIALOGSYSTEM_API IDialogInterface
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category ="Dialog System")
	bool HasQuest(const FName QuestId);

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "Dialog System")
	bool CompletedQuest(const FName QuestId);

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "Dialog System")
	bool HasItem(const FName ItemId);

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "Dialog System")
	bool HasNumItem(const FName ItemId, const int Num);

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "Dialog System")
	bool AddQuest(const FName QuestId);

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "Dialog System")
	bool RemoveQuest(const FName QuestId);

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "Dialog System")
	bool CompleteQuest(const FName QuestId);
	
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "Dialog System")
	void DialogSequenceInitalised(struct FNpcDialogSequence sequence);

	// dispatched to player pawn at the end of a level sequence, to allow for 
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "Dialog System")
	void DialogSequenceEnded(struct FNpcDialogSequence sequence);

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "Dialog System")
	void EndDialogInteraction();

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "Dialog System")
	void PlayDialog(class USoundBase* FileToPlay);

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "Dialog System")
	bool AddItem(const FName ItemId, const int NumItems);

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "Dialog System")
	bool RemoveItem(const FName ItemId, const int NumItems);
};
