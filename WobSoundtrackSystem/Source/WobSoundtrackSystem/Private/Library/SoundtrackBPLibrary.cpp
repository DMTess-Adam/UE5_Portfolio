// Copyright - DMTesseracT


#include "Library/SoundtrackBPLibrary.h"
#include "Subsystem/SoundtrackSubsystem.h"

USoundtrackSubsystem* USoundtrackBPLibrary::GetSoundtrackSubsystem(UWorld* WorldContext)
{
	if (!WorldContext) return nullptr;

	return WorldContext->GetSubsystem<USoundtrackSubsystem>();
}
