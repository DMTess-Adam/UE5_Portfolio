// Copyright - DMTesseracT

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "SoundtrackDataTypes.h"
#include "SoundtrackSubsystem.generated.h"




DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnKick);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnSnare);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnVocalUpdate, const float&, Value);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnTrackChangesFinished, const FMetasoundtrackConfig, NewConfig);
/**
 * 
 */
UCLASS()
class WOBSOUNDTRACKSYSTEM_API USoundtrackSubsystem : public UWorldSubsystem
{
	GENERATED_BODY()
	

public:


	UPROPERTY(BlueprintAssignable, Category="Events")
	FOnKick OnKick;

	UPROPERTY(BlueprintAssignable, Category = "Events")
	FOnSnare OnSnare;

	UPROPERTY(BlueprintAssignable, Category = "Events")
	FOnVocalUpdate OnVocalUpdate;

	// Called when soundtrack configs are fully applied. If a transition time was specified in the config, this is called
	// after that time has expired and all of the levels have hit their final settings.
	UPROPERTY(BlueprintAssignable, Category="Events")
	FOnTrackChangesFinished OnTrackChangesApplied;

	void PostInitialize() override;

	UFUNCTION(BlueprintCallable, Category="Soundtrack")
	void SetSoundtrackByConfig(const FMetasoundtrackConfig config, const bool bForceRestart = false);

	UFUNCTION(BlueprintCallable, Category = "Soundtrack")
	void StopMusic();

	UFUNCTION(BlueprintCallable, Category = "Soundtrack")
	void FadeOutMusic(const float Time);

	UFUNCTION(BlueprintCallable, Category = "Soundtrack")
	void NPCPatrolNotify(AActor* NPC);

	UFUNCTION(BlueprintCallable, Category ="Soundtrack")
	void NPCAlertNotify(AActor* NPC);

	UFUNCTION(BlueprintCallable, Category = "Soundtrack")
	void NPCAttackNotify(AActor* NPC);
	

	UFUNCTION(BlueprintCallable, Category = "Soundtrack")
	void SetSoundtrackCombatMode(const bool bNewMode)
	{
		bCombatMode = bNewMode;
	};

	// Start playing the combat soundtrack, starting with the given level.
	UFUNCTION(BlueprintCallable, Category = "Soundtrack")
	void InitCombatSoundtrack(const uint8 InitialState)
	{
		SetSoundtrackCombatMode(true);
		if (CombatSoundtrackConfig.Contains(InitialState))
		{
			SetSoundtrackByConfig(*CombatSoundtrackConfig.Find(InitialState));
		}
		return;
	};

	UFUNCTION(BlueprintCallable, Category = "Soundtrack")
	void SetCombatSoundtrackData(const TMap<uint8, FMetasoundtrackConfig> InCombatSoundtrackData)
	{
		CombatSoundtrackConfig = InCombatSoundtrackData;
	};

protected:

	UFUNCTION()
	void SetTrackedNPCState(AActor* Key, const uint8 State);

	UFUNCTION()
	void AsssessCombatState();

	//Combat mode is used for escalating/descelating audio states based on combat states. if disabled, any events processed by NPC's are ignored.
	UPROPERTY()
	bool bCombatMode;

	UFUNCTION()
	void OnKickEvent();

	UFUNCTION()
	void OnSnareEvent();

	UFUNCTION()
	void OnVocalUpdateEvent(const float& Value);

	UFUNCTION()
	void OnTrackChangesAppliedEvent(const FMetasoundtrackConfig NewConfig);

private:

	uint8 ActiveHighestCombatState{ 0 };

	UPROPERTY()
	TMap<AActor*, uint8> TrackedNPCActorState;

	UPROPERTY()
	TMap<uint8, FMetasoundtrackConfig> CombatSoundtrackConfig;

	void BindSoundtrackEvents();

	void OnPlayerReady();

	UPROPERTY()
	bool bHasQueued{ false };

	UPROPERTY()
	FMetasoundtrackConfig QueuedConfig;

	UPROPERTY()
	TObjectPtr<class ASoundtrackPlayer> SoundtrackPlayer;
};
