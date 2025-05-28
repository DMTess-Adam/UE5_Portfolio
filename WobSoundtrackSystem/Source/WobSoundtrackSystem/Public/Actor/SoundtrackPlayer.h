// Copyright - DMTesseracT

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SoundtrackDataTypes.h"
#include "SoundtrackPlayer.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FPlayerOnKick);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FPlayerOnSnare);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FPlayerOnVocalUpdate, const float&, Value);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnAudioStateChanged, const FMetasoundtrackConfig, NewConfig);

UCLASS()
class WOBSOUNDTRACKSYSTEM_API ASoundtrackPlayer : public AActor
{
	GENERATED_BODY()
	
public:	

	UPROPERTY(BlueprintAssignable, Category = "Events")
	FPlayerOnKick OnKick;

	UPROPERTY(BlueprintAssignable, Category = "Events")
	FPlayerOnSnare OnSnare;

	UPROPERTY(BlueprintAssignable, Category = "Events")
	FPlayerOnVocalUpdate OnVocalUpdate;

	UPROPERTY(BlueprintAssignable, Category ="Events")
	FOnAudioStateChanged OnAudioStateChanged;

	// Sets default values for this actor's properties
	ASoundtrackPlayer();

	UFUNCTION(BlueprintCallable, Category="Soundtrack")
	void PlayTrackConfig(const FMetasoundtrackConfig config, const bool bRestartExistingAudio = false);

	void Stop();

	void FadeOut(const float Time);


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

	void BindListeners();

	UFUNCTION()
	void OnKickEvent(FName Name, const struct FMetaSoundOutput& Output);

	UFUNCTION()
	void OnSnareEvent(FName Name, const struct FMetaSoundOutput& Output);

	UFUNCTION()
	void OnVocalUpdateEvent(FName Name, const struct FMetaSoundOutput& Output);

	UPROPERTY()
	TObjectPtr<UAudioComponent> AudioComponent;

	UFUNCTION()
	void LerpConfigGains();

private:

	UPROPERTY()
	FTimerHandle LerpConfigHandle;

	UPROPERTY()
	float TransitionTimeSeconds;

	UPROPERTY()
	float LerpInterval{ 0.01f };

	TSharedPtr<FMetasoundtrackConfig> LastConfig;

	TSharedPtr<FMetasoundtrackConfig> TransitioningConfig;

	TSharedPtr<FMetasoundtrackConfig> GoalConfig;
};
