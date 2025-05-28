// Copyright - DMTesseracT


#include "Subsystem/WobCommonUiManager.h"
#include "Blueprint/UserWidget.h"
#include "CommonInputSubsystem.h"
#include "Input/CommonUIActionRouterBase.h"
#include "CommonActivatableWidget.h"
#include "Interface/WobCommonUiInterface.h"
#include "Widgets/CommonActivatableWidgetContainer.h"



bool UWobCommonUiManager::PushWidgetToUiStack(UObject* OwningPlayer, const FGameplayTag Layer, TSoftClassPtr<UCommonActivatableWidget> WidgetClass, UCommonActivatableWidget*& CreatedWidget)
{
	if (!RegisteredStacks.Contains(Layer))
	{
		UE_LOG(LogClass, Display, TEXT("Layer not found"));
		return false;
	}


	FUserInterfaceWidgetStackInfo Info = *RegisteredStacks.Find(Layer);
	UCommonActivatableWidgetStack* Stack = Info.StackWidget;
	if (!Stack)
	{
		UE_LOG(LogClass, Display, TEXT("Stack not found"));
		return false;
	}
	UCommonActivatableWidget* NewWidget = Stack->AddWidget<UCommonActivatableWidget>(WidgetClass.LoadSynchronous());
	if (!NewWidget)
	{
		UE_LOG(LogClass, Display, TEXT("Failed to create widget."));
		return false;
	}

	// NewWidget->ActivateWidget();
	UE_LOG(LogClass, Display, TEXT("Widget pushed"));
	CreatedWidget = NewWidget;
	NewWidget->SetFocus();
	return true;
}

void UWobCommonUiManager::RegisterLayer(UCommonActivatableWidgetStack* WidgetStack, const FGameplayTag Layer, const int LayerPriority, const ECommonWidgetLayerInputMode InputMode)
{
	if (!WidgetStack) return;

	RegisteredStacks.Add(Layer, FUserInterfaceWidgetStackInfo(WidgetStack, LayerPriority, InputMode));

	WidgetStack->OnDisplayedWidgetChanged().AddUFunction(this, "OnActiveWidgetChanged");

	RefreshSortedArray();
	UE_LOG(LogClass, Display, TEXT("Widget Registered"));
}

void UWobCommonUiManager::AssignButtonTapEventForwardingToLayer(FGameplayTag Layer)
{
	if (RegisteredStacks.Contains(Layer))
	{
		ButtonTapEventLayer = RegisteredStacks.Find(Layer)->StackWidget;
	}
}

void UWobCommonUiManager::StartGameplayButtonMashEvent(const FGameplayButtonTapEventData EventData)
{
	if (!ButtonTapEventLayer || !ButtonTapEventLayer->Implements<UWobCommonUiInterface>())
	{
		UE_LOG(LogClass, Warning, TEXT("Attempted to forward Gameplay button Tap Event Start to widget, but the appropriate Layer is not assigned or invalid."));
		return;
	}

	IWobCommonUiInterface::Execute_GameplayButtonEventStarted(ButtonTapEventLayer, EventData);

}

void UWobCommonUiManager::EndGameplayButtonMashEvent(const FString Reason)
{
	if (!ButtonTapEventLayer || !ButtonTapEventLayer->Implements<UWobCommonUiInterface>())
	{
		UE_LOG(LogClass, Warning, TEXT("Attempted to forward Gameplay button Tap Event End to widget, but the appropriate Layer is not assigned or invalid."));
		return;
	}

	IWobCommonUiInterface::Execute_GameplayButtonEventEnded(ButtonTapEventLayer, Reason);
}


void UWobCommonUiManager::OnActiveWidgetChanged(UCommonActivatableWidget* ActiveWidget)
{

	// if there's an active widget on this layer explicitly focus its desired target. This is a workaround for some focus issue we're getting using defaults.
	if (ActiveWidget)
	{
		UE_LOG(LogClass, Verbose, TEXT("The current layer has an active widget"));
		if (ActiveWidget->GetDesiredFocusTarget())
		{
			ActiveWidget->GetDesiredFocusTarget()->SetFocus();
		}
		return;
	}

	UE_LOG(LogClass, Verbose, TEXT("The current layer does not have an active widget"));
	ULocalPlayer* LocalPlayer = GetOuterULocalPlayer();
	if (!LocalPlayer) return;

	APlayerController* LocalController = LocalPlayer->GetPlayerController(GetWorld());
	if (!LocalController) return;


	UCommonUIActionRouterBase* Router = LocalPlayer->GetSubsystem<UCommonUIActionRouterBase>();

	for (int i = SortedPriorityStacks.Num() - 1; i >= 0; i--)
	{
		FUserInterfaceWidgetStackInfo Info = SortedPriorityStacks[i];
		UCommonActivatableWidgetStack* Stack = Info.StackWidget;
		if (Stack && Stack->GetActiveWidget())
		{
			UE_LOG(LogClass, Verbose, TEXT("Focused widget: %s"), *Stack->GetActiveWidget()->GetName());
			Stack->GetActiveWidget()->ActivateWidget();
			break;
		}
	}
}

void UWobCommonUiManager::RefreshSortedArray()
{
	RegisteredStacks.GenerateValueArray(SortedPriorityStacks);
	SortedPriorityStacks.Sort();
}




