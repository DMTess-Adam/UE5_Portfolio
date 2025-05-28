// Copyright - DMTesseracT


#include "Actor/SoundtrackPlayer.h"
#include "Components/AudioComponent.h"
#include "MetasoundGeneratorHandle.h"
#include "MetasoundOutputSubsystem.h"
#include "MetasoundPrimitives.h"
#include "MetasoundDataReference.h"
#include "Subsystem/SoundtrackSubsystem.h"

// Sets default values
ASoundtrackPlayer::ASoundtrackPlayer()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	AudioComponent = CreateDefaultSubobject<UAudioComponent>(TEXT("AudioComponent"));
	AudioComponent->SetupAttachment(GetRootComponent());
}

void ASoundtrackPlayer::PlayTrackConfig(const FMetasoundtrackConfig config, const bool bRestartExistingAudio)
{
	if (!AudioComponent)
	{
		return;
	}
	
	bool bSoundFileChanged = false;

	// if we're forcefully restarting the existing audio, then stop it, reassign the file and start playback
	if (bRestartExistingAudio || (config.MetasoundFile && AudioComponent->Sound != config.MetasoundFile))
	{
		UE_LOG(LogTemp, Warning, TEXT("Replaced metasound file"));
		AudioComponent->Stop();
		AudioComponent->Sound = config.MetasoundFile;
		bSoundFileChanged = true;

	}

	if(!AudioComponent->IsPlaying())
		AudioComponent->Play(); // metasound wont set some parameters unless the file is playing
	

	AudioComponent->SetFloatParameter(FName("LoopDuration"), config.LoopDuration);
	AudioComponent->SetFloatParameter(FName("StartTime"), config.StartTime);

	if (bSoundFileChanged) BindListeners();

	if (config.TransitionTime <= 0)
	{
		// pause the audio so we can set the changes immediately, without any unexpected slippage
		AudioComponent->SetPaused(true);
		AudioComponent->SetFloatParameter(FName("CleanGain"), config.CleanGain);
		AudioComponent->SetFloatParameter(FName("BassGain"), config.GuitarGain);
		AudioComponent->SetFloatParameter(FName("SynthGain"), config.SynthGain);
		AudioComponent->SetFloatParameter(FName("DrumGain"), config.DrumGain);
		AudioComponent->SetFloatParameter(FName("VocalGain"), config.VocalGain);
		AudioComponent->SetFloatParameter(FName("GlobalGain"), config.GlobalGain);
	
		//unpause the audio.
		AudioComponent->SetPaused(false);

		// Explicitly trigger on play to restart the audio if necessary.
		if(bRestartExistingAudio) AudioComponent->SetTriggerParameter(FName("UE.Source.OnPlay"));
		
		return;
	}

	LastConfig = GoalConfig.IsValid() ? GoalConfig : MakeShared<FMetasoundtrackConfig>();
	TransitioningConfig = MakeShared<FMetasoundtrackConfig>();
	GoalConfig = MakeShared<FMetasoundtrackConfig>(config);

	FTimerDelegate Delegate; Delegate.BindUObject(this, &ASoundtrackPlayer::LerpConfigGains);
	TransitionTimeSeconds = 0;
	GetWorld()->GetTimerManager().ClearTimer(LerpConfigHandle);
	GetWorld()->GetTimerManager().SetTimer(LerpConfigHandle, Delegate, LerpInterval, true);

}

void ASoundtrackPlayer::Stop()
{
	if (AudioComponent)
	{
		AudioComponent->Stop();
	}
}

void ASoundtrackPlayer::FadeOut(const float Time)
{
	if (AudioComponent)
	{
		AudioComponent->FadeOut(Time, 0.0f);
	}
}

// Called when the game starts or when spawned
void ASoundtrackPlayer::BeginPlay()
{
	Super::BeginPlay();
	
}

void ASoundtrackPlayer::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Destroy();

	Super::EndPlay(EndPlayReason);
}

void ASoundtrackPlayer::BindListeners()
{
	UMetaSoundOutputSubsystem* MetaSubsystem = GetWorld()->GetSubsystem<UMetaSoundOutputSubsystem>();

	FOnMetasoundOutputValueChanged Kick; Kick.BindUFunction(this, FName("OnKickEvent"));
	FOnMetasoundOutputValueChanged Snare; Snare.BindUFunction(this, FName("OnSnareEvent"));
	FOnMetasoundOutputValueChanged VocalValue; VocalValue.BindUFunction(this, FName("OnVocalUpdateEvent"));

	if (MetaSubsystem)
	{
		MetaSubsystem->WatchOutput(AudioComponent, FName("OnKick"), Kick);
		MetaSubsystem->WatchOutput(AudioComponent, FName("OnSnare"), Snare);
	}
}

void ASoundtrackPlayer::OnKickEvent(FName Name, const FMetaSoundOutput& Output)
{
	OnKick.Broadcast();
}

void ASoundtrackPlayer::OnSnareEvent(FName Name, const FMetaSoundOutput& Output)
{
	OnSnare.Broadcast();
}

void ASoundtrackPlayer::OnVocalUpdateEvent(FName Name, const FMetaSoundOutput& Output)
{
	float value = 0.0f;
	Output.Get(value);
	OnVocalUpdate.Broadcast(value);
}

void ASoundtrackPlayer::LerpConfigGains()
{
	TransitionTimeSeconds += LerpInterval;
	TransitionTimeSeconds = FMath::Clamp(TransitionTimeSeconds, 0.f, GoalConfig->TransitionTime);

	if (TransitioningConfig->AllGainsEqual(*GoalConfig.Get()) || !AudioComponent || !AudioComponent->IsPlaying())
	{
		GetWorld()->GetTimerManager().ClearTimer(LerpConfigHandle);		
		return;
	}

	float Alpha = FMath::Clamp(TransitionTimeSeconds / GoalConfig->TransitionTime, 0.f, 1.f);
	
	TransitioningConfig->CleanGain = FMath::Lerp(LastConfig->CleanGain, GoalConfig->CleanGain, Alpha);
	TransitioningConfig->GuitarGain = FMath::Lerp(LastConfig->GuitarGain, GoalConfig->GuitarGain, Alpha);
	TransitioningConfig->SynthGain = FMath::Lerp(LastConfig->SynthGain, GoalConfig->SynthGain, Alpha);
	TransitioningConfig->DrumGain = FMath::Lerp(LastConfig->DrumGain, GoalConfig->DrumGain, Alpha);
	TransitioningConfig->VocalGain = FMath::Lerp(LastConfig->VocalGain, GoalConfig->VocalGain, Alpha);
	TransitioningConfig->GlobalGain = FMath::Lerp(LastConfig->GlobalGain, GoalConfig->GlobalGain, Alpha);

	AudioComponent->SetFloatParameter(FName("CleanGain"), TransitioningConfig->CleanGain);
	AudioComponent->SetFloatParameter(FName("BassGain"), TransitioningConfig->GuitarGain);
	AudioComponent->SetFloatParameter(FName("SynthGain"), TransitioningConfig->SynthGain);
	AudioComponent->SetFloatParameter(FName("DrumGain"), TransitioningConfig->DrumGain);
	AudioComponent->SetFloatParameter(FName("VocalGain"), TransitioningConfig->VocalGain);
	AudioComponent->SetFloatParameter(FName("GlobalGain"), TransitioningConfig->GlobalGain);

	if (TransitionTimeSeconds >= GoalConfig->TransitionTime)
	{
		GetWorld()->GetTimerManager().ClearTimer(LerpConfigHandle);
		return;
	}
}


