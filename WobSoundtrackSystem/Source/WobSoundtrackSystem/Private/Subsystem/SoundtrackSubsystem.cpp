// Copyright - DMTesseracT


#include "Subsystem/SoundtrackSubsystem.h"
#include "Actor/SoundtrackPlayer.h"

void USoundtrackSubsystem::PostInitialize()
{	

	SoundtrackPlayer = GetWorld()->SpawnActor<ASoundtrackPlayer>();

	if (!SoundtrackPlayer)
	{		
		UE_LOG(LogClass, Warning, TEXT("Failed to spawn soundtrack player"));
		return;
	}

	UE_LOG(LogTemp, Warning, TEXT("Spawned player"));
	OnPlayerReady();

}

void USoundtrackSubsystem::SetSoundtrackByConfig(const FMetasoundtrackConfig config, const bool bForceRestart)
{
	// queue the config if the player isnt ready
	if (!SoundtrackPlayer)
	{
		UE_LOG(LogTemp, Warning, TEXT("Player not ready. queued"));
		QueuedConfig = config;
		bHasQueued = true;
		return;
	}

	UE_LOG(LogTemp, Warning, TEXT("Forwarding track config"));
	SoundtrackPlayer->PlayTrackConfig(config, bForceRestart);
	return;
}

void USoundtrackSubsystem::StopMusic()
{
	if (SoundtrackPlayer)
	{
		SoundtrackPlayer->Stop();
	}
}

void USoundtrackSubsystem::FadeOutMusic(const float Time)
{
	if (SoundtrackPlayer)
	{
		SoundtrackPlayer->FadeOut(Time);
	}
	return;
}

void USoundtrackSubsystem::NPCPatrolNotify(AActor* NPC)
{
	SetTrackedNPCState(NPC, 0);
}

void USoundtrackSubsystem::NPCAlertNotify(AActor* NPC)
{
	SetTrackedNPCState(NPC, 1);
}

void USoundtrackSubsystem::NPCAttackNotify(AActor* NPC)
{
	SetTrackedNPCState(NPC, 2);
}

void USoundtrackSubsystem::SetTrackedNPCState(AActor* Key, const uint8 State)
{
	TrackedNPCActorState.Emplace(Key, State);
	AsssessCombatState();
}

void USoundtrackSubsystem::AsssessCombatState()
{
	uint8 LowestValue = 0;
	for (auto& Elem : TrackedNPCActorState)
	{
		if (Elem.Value > LowestValue) LowestValue = Elem.Value;
	}
	
	if (LowestValue != ActiveHighestCombatState)
	{
		ActiveHighestCombatState = LowestValue;		
		InitCombatSoundtrack(ActiveHighestCombatState);
	}
}

void USoundtrackSubsystem::OnKickEvent()
{
	OnKick.Broadcast();
}

void USoundtrackSubsystem::OnSnareEvent()
{
	OnSnare.Broadcast();
}

void USoundtrackSubsystem::OnVocalUpdateEvent(const float& Value)
{
	OnVocalUpdate.Broadcast(Value);
}

void USoundtrackSubsystem::OnTrackChangesAppliedEvent(const FMetasoundtrackConfig NewConfig)
{
	OnTrackChangesApplied.Broadcast(NewConfig);
}


void USoundtrackSubsystem::BindSoundtrackEvents()
{
	if (!SoundtrackPlayer) return;

	SoundtrackPlayer->OnKick.AddDynamic(this, &USoundtrackSubsystem::OnKickEvent);
	SoundtrackPlayer->OnSnare.AddDynamic(this, &USoundtrackSubsystem::OnSnareEvent);
	SoundtrackPlayer->OnVocalUpdate.AddDynamic(this, &USoundtrackSubsystem::OnVocalUpdateEvent);
	SoundtrackPlayer->OnAudioStateChanged.AddDynamic(this, &USoundtrackSubsystem::OnTrackChangesAppliedEvent);
}

void USoundtrackSubsystem::OnPlayerReady()
{
	BindSoundtrackEvents();
	if (SoundtrackPlayer && bHasQueued)
	{
		SoundtrackPlayer->PlayTrackConfig(QueuedConfig, true);
		bHasQueued = false;
	}
	return;
}
