// Copyright - DMTesseracT


#include "UMG/WobMenuButtonBase.h"
#include "Blueprint/WidgetTree.h"
#include "Components/Widget.h"
#include "CommonTextBlock.h"

void UWobMenuButtonBase::HandleFocusReceived()
{
	Super::HandleFocusReceived();

	if (!GetStyle() || !GetStyle()->GetNormalHoveredTextStyle()) return;

	TSubclassOf<UCommonTextStyle> CTextStyle = GetStyle()->GetNormalHoveredTextStyle()->GetClass();
	TArray<UCommonTextBlock*> FoundWidgets;
	GetChildTextWidgets(this, FoundWidgets);

	GetChildTextWidgets(this, FoundWidgets);

	for (auto& TextWidget : FoundWidgets)
	{
		TextWidget->SetStyle(CTextStyle);
	}
}

void UWobMenuButtonBase::HandleFocusLost()
{
	Super::HandleFocusLost();

	if (!GetStyle() || !GetStyle()->GetNormalTextStyle()) return;

	TSubclassOf<UCommonTextStyle> CTextStyle = GetStyle()->GetNormalTextStyle()->GetClass();
	TArray<UCommonTextBlock*> FoundWidgets;

	GetChildTextWidgets(this, FoundWidgets);

	for (auto& TextWidget : FoundWidgets)
	{
		TextWidget->SetStyle(CTextStyle);
	}
}

void UWobMenuButtonBase::ApplyHoverStyle()
{
	if (!GetStyle()) return;
	
	TSubclassOf<UCommonTextStyle> CTextStyle = bIsEnabled ? GetStyle()->GetNormalHoveredTextStyle()->GetClass() : GetStyle()->GetDisabledTextStyle()->GetClass();
	TArray<UCommonTextBlock*> FoundWidgets;


	GetChildTextWidgets(this, FoundWidgets);
	
	for (auto& TextWidget : FoundWidgets)
	{
		TextWidget->SetStyle(CTextStyle);
	}
}

void UWobMenuButtonBase::ApplyUnHoveredStyle()
{
	if (!GetStyle())
	{
		return;
	}
	TSubclassOf<UCommonTextStyle> CTextStyle = bIsEnabled ? GetStyle()->GetNormalTextStyle()->GetClass() : GetStyle()->GetDisabledTextStyle()->GetClass();
	TArray<UCommonTextBlock*> FoundWidgets;

	GetChildTextWidgets(this, FoundWidgets);

	for (auto& TextWidget : FoundWidgets)
	{
		TextWidget->SetStyle(CTextStyle);
	}
}

void UWobMenuButtonBase::GetChildTextWidgets(UWidget* Parent, TArray<class UCommonTextBlock*>& OutWidgets)
{
	if (!Parent)
	{
		return;
	}

	// Check if the current widget is of the desired type
	if (UCommonTextBlock* TextBlock = Cast<UCommonTextBlock>(Parent))
	{
		OutWidgets.Add(TextBlock);
	}

	
	// If it's a panel widget, iterate through its children
	if (UUserWidget* Panel = Cast<UUserWidget>(Parent))
	{
		if (!Panel->WidgetTree) return;

		TArray<UWidget*> Widgets;
		Panel->WidgetTree->GetAllWidgets(Widgets);

		for (UWidget* Widget : Widgets)
		{
			GetChildTextWidgets(Widget, OutWidgets);
		}
	}
}
