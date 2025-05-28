// Fill out your copyright notice in the Description page of Project Settings.


#include "Subsystem/DialogEditorSubsystem.h"
#include <LevelEditor.h>

void UDialogEditorSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);

	BindSelectEvent();
}

void UDialogEditorSubsystem::BindSelectEvent()
{
	FLevelEditorModule& LevelEditor = FModuleManager::GetModuleChecked<FLevelEditorModule>(TEXT("LevelEditor"));
	LevelEditor.OnActorSelectionChanged().AddUObject(this, &UDialogEditorSubsystem::EditorSelectionChanged);
	return;
}
