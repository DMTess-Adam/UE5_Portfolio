// Copyright - DMTesseracT

#pragma once

#include "CoreMinimal.h"
#include "GameplayTags.h"
#include "Components/ActorComponent.h"
#include "DesktopInteractComponent.generated.h"

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class WOBGASSYSTEM_API UDesktopInteractComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UDesktopInteractComponent();

	/*Returns the qualified interactable target, if one exists. */
	UFUNCTION(BlueprintCallable, Category = "Interactables")
	bool GetInteractableTarget(AActor*& Target);

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	/*Radius that interactible items will be highlighted */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Interact Distance")
	float MaxDetectRadius{ 100.f };

	/*Maximum Distance that items can be interacted with */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Interact Distance")
	float MaxInteractDistance{ 100.f };

	// toggle debug trace for interactable range trace
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Debug")
	bool DrawRadiusDebugTrace;

	// toggle debug trace for interactable line trace
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Debug")
	bool DrawInteractDebugTrace;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Interact Audio")
	TObjectPtr<USoundBase> InteractSound;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category ="Interact Distance")
	TEnumAsByte<ECollisionChannel> InteractTraceChannel;

	// if true, radius ticks are allowed to include MinRadiusTickSeconds in trace conditions. if false, radius checks will only fire when
	// the owning actor has traveled MinDistanceBetweenRadiusTrace from the last location. Keep this false if not needed for performance optimisation.
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category ="Interact Distance")
	bool bAllowMinRadiusTick;

	//the minimum time between sphere traces for objects in range. This ensures trace radius fires at this interval regardless of min distance
	// between trace, to account for instances where new items may spawn in the existing radius. This should ideally be infrequent.
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category ="Interact Distance", meta=(EditCondition="bAllowMinRadiusTick"))
	float MinRadiusTickSeconds{ 0.5 };

	//if the distance between the last recorded location and current location is greater than this value, a radius check is allowed. 
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Interact Distance")
	float MinDistanceBetweenRadiusTrace{ MaxDetectRadius / 2 };


public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

private:

	float LastRadiusTickTime;

	FVector LastRadiusTickLocation;

	bool OwnerHasTag(FGameplayTag Tag); 

	UPROPERTY()
	TSoftObjectPtr<AActor> TargetInteractable;

	UPROPERTY()
	TArray<TSoftObjectPtr<AActor>> InteractablesInRadius;

	void TickInteractables();

	/*Trace in a radius around the owner for Interactables and instigate highlight. Handles removing highlight from disqualified references */
	void TraceRadiusForInteractable(const TArray<TSoftObjectPtr<AActor>> Actors);

	bool IsLookingAt(AActor* Target);

	void TraceForInteractable();

};
