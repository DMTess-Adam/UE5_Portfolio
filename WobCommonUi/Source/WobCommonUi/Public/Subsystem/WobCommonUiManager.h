// Copyright - DMTesseracT

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/LocalPlayerSubsystem.h"
#include "GameplayTags.h"
#include "CommonUITypes.h"
#include "WobCommonUiManager.generated.h"
/**
 * 
 */



class UCommonActivatableWidget;
class UCommonActivatableWidgetStack;

UENUM()
enum class EGameplayButtonTapEvent : uint8
{
	SINGLE_TAP,
	BUTTON_MASH,
	PRECISION_TAP,
};

USTRUCT(BlueprintType, Blueprintable)
struct FGameplayButtonTapEventData
{
	GENERATED_BODY()

	// the type of input event to display. 
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Settings")
	EGameplayButtonTapEvent EventType;

	//The input data that is tied to this event. Used for displaying the right input key on the UI.
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Settings")
	FDataTableRowHandle InputActionRowData;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Settings")
	float TotalDisplayTime;

	// How many times the key needs to be pressed to reach 100%.
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Settings|Button Mash", meta=(EditCondition="EventType == EGameplayButtonTapEvent::BUTTON_MASH"))
	int NumTapsRequired{ 1 };

	// The base precision tap size, as a percentage of the total bar. (i.e. 0.1 would be 10% of the bar)
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Settings|Precision Tap", meta=(EditCondition="EventType == EGameplayButtonTapEvent::PRECISION_TAP"))
	float PrecisionTapSize;

	/* Where along the bar the precision area is.The center of the precision tap size will be this position.i.e. if precision tap size is 0.1 and this position is 0.5, then
	   the precision area will range from 0.45-0.55 of the full bar area.
	*/
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Settings|Precision Tap", meta=(EditCondition = "EventType == EGameplayButtonTapEvent::PRECISION_TAP"))
	float PrecisionTapCentralPosition;
};

UENUM()
enum class ECommonWidgetLayerInputMode : uint8
{
	GameOnly,
	GameAndUi,
	UiOnly
};

USTRUCT()
struct FUserInterfaceWidgetStackInfo
{
	GENERATED_BODY()

	UPROPERTY()
	UCommonActivatableWidgetStack* StackWidget;

	UPROPERTY()
	int Priority;

	UPROPERTY()
	ECommonWidgetLayerInputMode InputMode;

public:

	FUserInterfaceWidgetStackInfo() 
	{
		StackWidget = nullptr;
		Priority = 0;
		InputMode = ECommonWidgetLayerInputMode::GameAndUi;
	};

	FUserInterfaceWidgetStackInfo(UCommonActivatableWidgetStack* _StackWidget, const int _Priority, const ECommonWidgetLayerInputMode _InputMode)
	{
		StackWidget = _StackWidget;
		Priority = _Priority;
		InputMode = _InputMode;
	}

	bool operator < (const FUserInterfaceWidgetStackInfo Comparator) const
	{
		return Priority < Comparator.Priority;
	}

	bool operator==(const FUserInterfaceWidgetStackInfo Comparator) const
	{
		return StackWidget == Comparator.StackWidget;
	}
};

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnButtonTapEventStartedDelegate, UUserWidget*&, EventWidget);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnButtonTapEventEndedDelegate, const bool, Successful);


UCLASS()
class WOBCOMMONUI_API UWobCommonUiManager : public ULocalPlayerSubsystem
{
	GENERATED_BODY()
	
public:



	UFUNCTION(BlueprintCallable, Category ="UWobCommonUiManager", meta=(DefaultToSelf="OwningPlayer"))
	bool PushWidgetToUiStack(UObject* OwningPlayer, const FGameplayTag Layer, TSoftClassPtr<UCommonActivatableWidget> WidgetClass, UCommonActivatableWidget*& CreatedWidget);

	/*Register Common Activatable Widget Stacks for tracking stack states.This allows this base widget to monitor the state of each of its child stacks
	and pass focus appropriately between them. */
	UFUNCTION(BlueprintCallable)
	void RegisterLayer(UCommonActivatableWidgetStack* WidgetStack, const FGameplayTag Layer, const int LayerPriority, const ECommonWidgetLayerInputMode InputMode);

	/*
		This explicitly registers which UI layer is expected to handle Gameplay Button Tap Events (button mash, precision timing etc.)
		The associated layer's widget stack must implement UWobCommonUiInterface to handle the routed execution at blueprint level.
	*/
	UFUNCTION(BlueprintCallable)
	void AssignButtonTapEventForwardingToLayer(FGameplayTag Layer);

	/*
	 Forward an in-game button tap event start request to the appropriate layer. This should be the entry point called directly by a gameplay ability
	 to initialise and synchronise the UI and ability appropriately.
	*/
	UFUNCTION(BlueprintCallable, Category = "UWobCommonUiManager")
	void StartGameplayButtonMashEvent(const FGameplayButtonTapEventData EventData);

	/*
	  Forward an in-game button tap event end request to the appropriate layer. This should only be used to abort an event early for external reasons. e.g. the instigating enemy is stunned
	  or dies during the event.
	*/
	UFUNCTION(blueprintCallable, Category = "UWobCommonUiManager")
	void EndGameplayButtonMashEvent(const FString Reason);


	/*Announce that a Gameplay Button Tap Event has started. Should be invoked by the widget layer that is handling this event once its environment is setup. */
	UFUNCTION(BlueprintCallable, Category ="ButtonTapEvent")
	void BroadcastStartButtonTapEvent(UUserWidget*& OwningWidget) { OnButtonTapEventStart.Broadcast(OwningWidget); return; };

	/*Announce that a gameplay button tap event has ended. Should be invoked by the widget layer that is handling this event once the event has ended for any reason. */
	UFUNCTION(BlueprintCallable, Category = "ButtonTapEvent")
	void BroadcastEndButtonTapEvent(const bool bSuccess) { OnButtonTapEventEnd.Broadcast(bSuccess); return; };

	UPROPERTY(BlueprintCallable)
	FOnButtonTapEventStartedDelegate OnButtonTapEventStart;

	UPROPERTY(BlueprintAssignable)
	FOnButtonTapEventEndedDelegate OnButtonTapEventEnd;

private:


	// Delegate function for ensuring Input Modes change appropriately to whatever the topmost active stack expects.
	UFUNCTION()
	void OnActiveWidgetChanged(UCommonActivatableWidget* ActiveWidget);

private:

	void RefreshSortedArray();

	// Reference to the Registered Stack that has been assigned to handle gameplay button tap events. 
	UCommonActivatableWidgetStack* ButtonTapEventLayer;

	UPROPERTY()
	TMap <FGameplayTag, FUserInterfaceWidgetStackInfo > RegisteredStacks;

	UPROPERTY()
	TArray<FUserInterfaceWidgetStackInfo> SortedPriorityStacks;

};
