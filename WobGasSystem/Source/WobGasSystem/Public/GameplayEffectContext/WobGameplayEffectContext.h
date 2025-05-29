#pragma once

#include "CoreMinimal.h"
#include "GameplayEffectTypes.h"
#include "WobGameplayEffectContext.generated.h"

// Custom Effect Context that extends FGameplayEffectContext
USTRUCT(BlueprintType)
struct WOBGASSYSTEM_API FWobGameplayEffectContext : public FGameplayEffectContext
{
    GENERATED_BODY()

public:
    // Custom property to store damage type
    UPROPERTY(BlueprintReadWrite, Category = "Gameplay Effect Context")
    FString DamageType;

    // Overrides
    virtual UScriptStruct* GetScriptStruct() const override;
    virtual FGameplayEffectContext* Duplicate() const override;
    virtual bool NetSerialize(FArchive& Ar, UPackageMap* Map, bool& bOutSuccess) override;
};

// Required to enable NetSerialization
template <>
struct TStructOpsTypeTraits<FWobGameplayEffectContext> : public TStructOpsTypeTraitsBase2<FWobGameplayEffectContext>
{
    enum
    {
        WithNetSerializer = true,
        WithCopy = true
    };
};
