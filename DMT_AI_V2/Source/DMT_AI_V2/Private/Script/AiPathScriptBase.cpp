// Fill out your copyright notice in the Description page of Project Settings.


#include "Script/AiPathScriptBase.h"


void UAiPathScriptBase::NativeExecute(AActor* Instigator)
{
	if (!Instigator) return;

#if WITH_EDITOR
	FEditorDelegates::EndPIE.AddUObject(this, &UAiPathScriptBase::FinishExecute);
#endif

	FCoreDelegates::OnPreExit.AddUObject(this, &UAiPathScriptBase::SessionEnding);


	AddToRoot();
	WorldContext = Instigator->GetWorld();
	Execute(Instigator);
}

void UAiPathScriptBase::FinishExecute(const bool SessionEnding)
{
	if(IsRooted()) RemoveFromRoot();
}

void UAiPathScriptBase::SessionEnding()
{
}

