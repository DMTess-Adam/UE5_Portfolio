// Copyright - DMTesseracT


#include "Script/DmtAiScriptV2Common.h"
#include "Interface/DmtAiInterfaceV2.h"


void UDmtAiScriptV2Common::OnHostileTargetPerceived_Implementation(AActor* Target, FAIStimulus Stimulus, FCharacterAiData CharacterData)
{
	// Ignore if the target has specified gameplay tags 
	if (HasAnyIgnoreGameplayTags(Target)) return;

	UpdatePerceivedTrackedActorState(Target, Stimulus, CharacterData, HostileActorData);

	// if we can see any target while in any state other than Attack then we need to transition to attack.
	if (HasVisibleTarget(true) && GetCurrentAIState() != ENPCAIState::ATTACK)
	{
		SetCurrentAIState(ENPCAIState::ATTACK);
		OnTransitionToAttack();
		return;
	}

	// if we gained a target while in patrol then we need to transition to alert, if the above condition wasn't met.
	if (GetCurrentAIState() == ENPCAIState::PATROL)
	{
		OnTransitionToAlert();
		return;
	}
}

void UDmtAiScriptV2Common::OnHostileTargetLost_Implementation(AActor* Target, FAIStimulus Stimulus, FCharacterAiData CharacterData)
{
	UpdateLostTrackedActorState(Target, Stimulus, CharacterData, HostileActorData);

	if (!HasVisibleTarget() && GetCurrentAIState() == ENPCAIState::ATTACK)
	{
		SetCurrentAIState(ENPCAIState::ALERT);
		OnTransitionToAlert();
		return;
	}
}

AActor* UDmtAiScriptV2Common::GetCurrentTarget_Implementation()
{
	//forcefully return no target if we aren't in attack state.
	if (GetCurrentAIState() != ENPCAIState::ATTACK) return nullptr;

	// trace LOS to current target, valid if in LOS
	if (ValidateCurrentTarget()) return CurrentTarget;

	//pick a new target or nullptr if we can't
	return SelectAttackTarget();
}

FVector UDmtAiScriptV2Common::GetYoungestAlertLocation()
{
	FVector YoungestData = FVector();
	float YoungestTime = ActorTrackingTimeout + 1;
	for (auto& HostileData : HostileActorData)
	{
		if (HostileData.Value.LastStimulusTime > WorldContext->GetTimeSeconds() - YoungestTime)
		{
			YoungestTime = HostileData.Value.LastStimulusTime;
			YoungestData = HostileData.Value.LastSenseLocation;
		}
	}
	return YoungestData;
}

FVector UDmtAiScriptV2Common::GetAlertTargetLocation_Implementation()
{
	return FVector();
}

bool UDmtAiScriptV2Common::HasTargetInMap(TMap<AActor*, FAiTrackedActorData>& Map, const bool RequireLineOfSight)
{
	if (Map.IsEmpty()) return false;

	for (auto& Pair : Map)
	{
		if (Pair.Value.TargetActor.IsValid())
		{
			if (RequireLineOfSight)
			{
				if (!Pair.Value.bSighted) continue; // if LOS is required and not valid on this target then move on.
			}
			return true;
		}
	}
	return false;
}

bool UDmtAiScriptV2Common::HasAnyAttackTargets()
{
	return HasTargetInMap(HostileActorData, true);
}

bool UDmtAiScriptV2Common::HasAnyAlertTargets()
{
	return HasTargetInMap(HostileActorData, false);
}

void UDmtAiScriptV2Common::OnPerceptionTargetUpdated_Implementation(AActor* Target, FAIStimulus Stimulus)
{
	// dont add any new perception targets that dont qualify due to ignored gameplay tags.
	if (Stimulus.WasSuccessfullySensed() && HasAnyIgnoreGameplayTags(Target)) return;
	
	Super::OnPerceptionTargetUpdated_Implementation(Target, Stimulus);
}



AActor* UDmtAiScriptV2Common::SelectAttackTarget_Implementation()
{
	float HighestThreat = -1.f;
	AActor* ThreatActor = nullptr;
	for (auto& Pair : HostileActorData)
	{
		if (Pair.Value.ThreatValue > HighestThreat && IsTargetInLOS(Pair.Value.TargetActor.Get()))
		{
			ThreatActor = Pair.Value.TargetActor.Get();
			HighestThreat = Pair.Value.ThreatValue;
		}
	}
	return ThreatActor;
}

bool UDmtAiScriptV2Common::IsTargetInLOS(AActor* Target)
{
	if (!WorldContext) return false;

	FHitResult Result;
	UKismetSystemLibrary::LineTraceSingle(
		WorldContext,
		ParentActor.Get()->GetActorLocation(),
		Target->GetActorLocation(),
		UEngineTypes::ConvertToTraceType(TargetTraceCollisionChannel),
		false,
		TArray<AActor*>{ParentActor.Get()},
		bDrawDebugTrace,
		Result,
		true
	);

	return Result.bBlockingHit && Result.GetActor() == Target;
}

bool UDmtAiScriptV2Common::ValidateCurrentTarget()
{
	if (CurrentTarget == nullptr) return false;

	return IsTargetInLOS(CurrentTarget);
}

void UDmtAiScriptV2Common::UpdatePerceivedTrackedActorState(AActor* Target, FAIStimulus Stimulus, FCharacterAiData CharacterData, TMap<AActor*, FAiTrackedActorData>& PerceptionMap)
{
	
	FAiTrackedActorData* ActiveData;
	if (PerceptionMap.Contains(Target))
	{
		FAiTrackedActorData& ExistingData = *PerceptionMap.Find(Target);
		ActiveData = &ExistingData;
	}
	else
	{
		ActiveData = &PerceptionMap.Add(Target, FAiTrackedActorData(Target, CharacterData.Name, 0.f));
	}

	ActiveData->LastStimulusTime = WorldContext->GetTimeSeconds();

	ActiveData->bSighted = IsTargetInLOS(Target);
	UE_LOG(LogTemp, Warning, TEXT("Perception type: %s"), *Stimulus.Type.Name.ToString());
	if (Stimulus.Type.Name.ToString().Contains("Sight"))
	{
		ActiveData->LastSenseLocation = Stimulus.StimulusLocation;
	}

	if (Stimulus.Type.Name.ToString().Contains("Hearing"))
	{
		ActiveData->LastSenseLocation = Stimulus.StimulusLocation;
	}

	if (Stimulus.Type.Name.ToString().Contains("Damage"))
	{
		ActiveData->LastSenseLocation = Stimulus.StimulusLocation;
	}
	UpdateDataMaps();
}

void UDmtAiScriptV2Common::UpdateLostTrackedActorState(AActor* Target, FAIStimulus Stimulus, FCharacterAiData CharacterData,TMap<AActor*, FAiTrackedActorData>& PerceptionMap)
{
	FAiTrackedActorData* ActiveData;

	ActiveData = &*PerceptionMap.Find(Target);

	if (ActiveData)
	{
		ActiveData->LastStimulusTime = WorldContext->GetTimeSeconds();		
	

		if (Stimulus.Type.Name.ToString().Contains("Sight"))
		{
			ActiveData->LastSenseLocation = Stimulus.StimulusLocation;			
			ActiveData->bSighted = IsTargetInLOS(Target);
		}

		if (Stimulus.Type.Name.ToString().Contains("Hearing"))
		{
			ActiveData->LastSenseLocation = Stimulus.StimulusLocation;
		}

		if (Stimulus.Type.Name.ToString().Contains("Damage"))
		{
			ActiveData->LastSenseLocation = Stimulus.StimulusLocation;
		}
	}
	UpdateDataMaps();
}

bool UDmtAiScriptV2Common::HasVisibleTarget(const bool bUsePerceptionSight)
{

	for (auto& HostileData : HostileActorData)
	{
		// if set, don't Trace LOS, just rely on AI Sight config. 
		if (bUsePerceptionSight)
		{
			if (HostileData.Value.bSighted) 
				return true;

			continue;
		}

		if(IsTargetInLOS(HostileData.Value.TargetActor.Get()))
		{
			return true;
		}
	}
	return false;
}

void UDmtAiScriptV2Common::UpdateDataMaps()
{
	
}

bool UDmtAiScriptV2Common::HasAnyIgnoreGameplayTags(AActor* Target)
{
	if (Target->Implements<UDmtAiInterfaceV2>())
	{
		FGameplayTagContainer Container = IDmtAiInterfaceV2::Execute_GetActorGameplayTags(Target);
		return Container.HasAny(IgnoreTargetTrackingTags);
	}

	return false;
}

void UDmtAiScriptV2Common::RemoveTimedOutTargetsFromMap(TMap<AActor*, FAiTrackedActorData>& Map)
{
	if (!WorldContext) return;
	float CurrentTime = WorldContext->TimeSeconds;
	TArray<AActor*> Timeouts;

	for (auto& Pair : Map)
	{
		// flag if the target is invalid.
		if (!Pair.Value.TargetActor.IsValid())
		{
			Timeouts.Add(Pair.Value.TargetActor.Get());
			continue;
		}

		// check if the target has ignore tags and mark as timeout if so.
		if (HasAnyIgnoreGameplayTags(Pair.Value.TargetActor.Get()))
		{
			Timeouts.Add(Pair.Value.TargetActor.Get());
			continue;
		}

		// if we can still see them, don't remove them.
		if (IsTargetInLOS(Pair.Value.TargetActor.Get())) continue;
		
		// if last stim was outside of timeout then flag for remove.
		if (CurrentTime - Pair.Value.LastStimulusTime >= ActorTrackingTimeout)
		{
			Timeouts.Add(Pair.Value.TargetActor.Get());
		}	
	}

	for (auto& Timeout : Timeouts)
	{
		Map.Remove(Timeout);
	}
}
