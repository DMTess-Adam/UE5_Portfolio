#pragma once

#include "CoreMinimal.h"
#include "SoundtrackDataTypes.generated.h"

USTRUCT(BlueprintType)
struct FMetasoundtrackConfig
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TObjectPtr<USoundBase> MetasoundFile;

	// the time it should take to interpolate levels to the config levels.
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float TransitionTime{ 4.0f };

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float StartTime{ 0.0f };

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float LoopDuration{ -1.0f };

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float DrumGain{ 0.0f };

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float CleanGain{ 0.0f };

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float GuitarGain{ 0.0f };

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float VocalGain{ 0.0f };

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float SynthGain{ 0.0f };

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float GlobalGain{ 0.0f };

	bool AllGainsEqual(const FMetasoundtrackConfig& Comparator)
	{
		return (Comparator.CleanGain == CleanGain
			&& Comparator.DrumGain == DrumGain
			&& Comparator.GlobalGain == GlobalGain
			&& Comparator.GuitarGain == GuitarGain
			&& Comparator.SynthGain == SynthGain
			&& Comparator.VocalGain == VocalGain);
	}

};