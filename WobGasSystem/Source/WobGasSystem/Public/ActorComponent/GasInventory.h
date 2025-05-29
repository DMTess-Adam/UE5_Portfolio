// Copyright - DMTesseracT

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Kismet/KismetMathLibrary.h"
#include "GasInventory.generated.h"

USTRUCT(BlueprintType)
struct FGasInventorySlot {

	GENERATED_BODY()

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FName ItemId{ NAME_None };

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int NumHeld{ 1 };

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int MaxStackSize{ 1 };

	FGasInventorySlot() {};

	FGasInventorySlot(FName _Id, int _NumHeld, int _MaxStackSize)
	{
		ItemId = _Id;
		NumHeld = _NumHeld;
		MaxStackSize = _MaxStackSize;
	}

	void Clear()
	{
		ItemId = NAME_None;
		NumHeld = 1;
		MaxStackSize = 1;
	}
};


USTRUCT(BlueprintType)
struct FGasInventoryStruct
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TArray<FGasInventorySlot> Slots;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int MaxSlots{ 4 };

	FGasInventoryStruct()
	{
		Slots = TArray<FGasInventorySlot>();
		for (int i = 0; i < MaxSlots; i++)
		{
			Slots.Add(FGasInventorySlot());
		}
	}

	FGasInventoryStruct(const TArray<FGasInventorySlot>& ExistingData)
	{
		Slots = ExistingData;
	}

	bool AddSlot(const int SlotsToAdd = 1)
	{
		Slots.Add(FGasInventorySlot());
		MaxSlots++;
		return true;
	}


	bool FirstEmptySlot(int& FreeSlotIndex)
	{
		int Index = -1;
		for (auto& slot : Slots)
		{
			Index++;
			if (slot.ItemId == NAME_None)
			{
				FreeSlotIndex = Index;
				return true;
			}
		}
		return false;
	}

	bool GetAt(const int Index, FGasInventorySlot& Item)
	{
		if (Slots.IsValidIndex(Index))
		{
			Item = Slots[Index];
			return true;
		}
		return false;
	};

	bool EmplaceAt(const int Index, const FGasInventorySlot SlotItem, FGasInventorySlot& OldSlot, bool& bSlotHadItem)
	{
		if (!Slots.IsValidIndex(Index))
		{
			return false;
		}

		FGasInventorySlot Temp = Slots[Index];
		OldSlot = Temp;
		bSlotHadItem = Slots[Index].ItemId == NAME_None ? false : true;
		Slots.EmplaceAt(Index, SlotItem);
		return true;
	}

	bool RemoveSlots(const int NumSlots = 1, const bool bEmptyOnly = true)
	{
		// if we have no slots, fail out.
		if (Slots.Num() == 0) 
		{
			return false;
		}

		int NumRemaining = NumSlots;
		if (!bEmptyOnly) 
		{
			while (NumRemaining > 0 || Slots.Num() > 0)
			{				
				Slots.RemoveAt(0);
				NumRemaining--;
			}
			return true;
		}


		TArray<int> EmptySlotIndices;
		for (int i =0; i < Slots.Num(); i++)
		{		
			if (Slots[i].ItemId == NAME_None)
			{
				EmptySlotIndices.Add(i);
			}
		}

		if (EmptySlotIndices.IsEmpty()) return false;

		for (int j = 0; j < EmptySlotIndices.Num(); j++)
		{
			Slots.RemoveAt(j);
		}
		return true;
	}

	bool FindFirstSlotWithId(const FName ItemId, FGasInventorySlot*& ItemSlot)
	{
		for (int i = 0; i < Slots.Num(); i++)
		{
			if (Slots[i].ItemId == ItemId)
			{
				ItemSlot = &Slots[i];
				return true;
			}
		}

		return false;
	};

	TArray<FGasInventorySlot*> GetAllSlotsWIthId(FName ItemId)
	{
		TArray<FGasInventorySlot*> Found;

		for (auto& Slot : Slots)
		{
			if (Slot.ItemId == ItemId)
			{
				Found.Add(&Slot);
			}
		}

		return Found;
	}

	int GetTotalNumberOfItemWithId(const FName ItemId)
	{
		int Count = 0;
		for (auto& Slot : Slots)
		{
			if (Slot.ItemId == ItemId)
			{
				Count += Slot.NumHeld;
			}
		}
		return Count;
	}

	bool RemoveItem(const FName ItemId, const int NumToRemove, int& NumRemaining, bool bAllOrNothing)
	{
		FGasInventorySlot* ExistingSlot;
		if (FindFirstSlotWithId(ItemId, ExistingSlot))
		{
			if (ExistingSlot->NumHeld < NumToRemove && bAllOrNothing)
			{
				return false;
			}

			NumRemaining = ExistingSlot->NumHeld < NumToRemove ? NumToRemove - ExistingSlot->NumHeld : 0;
			ExistingSlot->NumHeld = UKismetMathLibrary::Max(ExistingSlot->NumHeld - NumToRemove, 0);
			if (ExistingSlot->NumHeld == 0)
			{
				ExistingSlot->Clear();
			}
			return true;
		}
		return false;
	}

	bool RemoveAllMatchingId(const FName ItemId)
	{
		for (auto& Slot : Slots)
		{
			if(Slot.ItemId == ItemId) Slot.Clear();
		}
		return true;
	}

	TArray<FGasInventorySlot*> GetAllSlotsWithId(const FName ItemId)
	{
		TArray<FGasInventorySlot*> Found = TArray<FGasInventorySlot*>();
		for (auto& Slot : Slots)
		{
			if (Slot.ItemId == ItemId) Found.Add(&Slot);
		}
		return Found;
	}

	// simulate whether there's enough space in the inventory to cater for the given item stack.
	bool CanFit(const FName ItemId, const int StackSize, const int StackLimit)
	{
		int EmptySlots = NumEmptySlots();
		int EmptySlotsNeeded =UKismetMathLibrary::FCeil(StackSize / StackLimit);
		
		if (EmptySlots >= EmptySlotsNeeded)
		{
			return true;
		}

		int RemainingRequired = StackSize;
		RemainingRequired -= StackLimit * EmptySlots;
		TArray<FGasInventorySlot*> ItemSlots = GetAllSlotsWIthId(ItemId);
		for (auto& Slot : ItemSlots)
		{
			int SpaceAvailable = Slot->MaxStackSize - Slot->NumHeld;
			RemainingRequired -= SpaceAvailable;
			if (RemainingRequired <= 0) break;
		}

		return RemainingRequired <= 0;
	}

	// try to add an item to the 
	bool AddItem(const FName ItemId, const int StackSize, const int MaxStackSize, int& Remainder, bool bFullStackOnly = true)
	{
		// if we must cater for the entire stack size, we need to check that we can fit before we start changing values.
		if (bFullStackOnly)
		{
			if (!CanFit(ItemId, StackSize, MaxStackSize)) return false;
		}

		// try to fill existing slots first
		TArray<FGasInventorySlot*> ExistingSlots;

		int Remaining = StackSize;
		ExistingSlots = GetAllSlotsWithId(ItemId);
		for (auto& Slot : ExistingSlots)
		{
			while (Remaining > 0 && Slot->NumHeld < Slot->MaxStackSize)
			{
				Slot->NumHeld++;
				Remaining--;
			}
		}

		// if we still have stacks left, start filling empty slots
		if (Remaining > 0)
		{
			TArray<FGasInventorySlot*> EmptySlots = GetAllSlotsWIthId(NAME_None);
			for (auto& EmptySlot : EmptySlots)
			{
				if (Remaining == 0) break;

				EmptySlot->ItemId = ItemId;
				EmptySlot->MaxStackSize = MaxStackSize;
				EmptySlot->NumHeld = 0;
				
				while (Remaining > 0 && EmptySlot->NumHeld < EmptySlot->MaxStackSize)
				{
					EmptySlot->NumHeld++;
					Remaining--;
				}
			}

			Remainder = Remaining;
		}

		return true;
	};

	int NumEmptySlots()
	{
		int Count = 0;
		for (auto& Slot : Slots)
		{
			if(Slot.ItemId == NAME_None) Count++;
		}
		return Count;
	}

	bool SwapIndices(const int First, const int Second)
	{
		if (Slots.IsValidIndex(First) && Slots.IsValidIndex(Second))
		{
			FGasInventorySlot Temp = Slots[First];
			Slots[First] = Slots[Second];
			Slots[Second] = Temp;
			return true;
		}
		return false;
	}
};


USTRUCT(BlueprintType)
struct FCurrencyContainer
{
	GENERATED_BODY()

	// byte that can represent and ID or enum from external systems. 
	UPROPERTY()
	uint8 Id{ 0 };

	// user friendly label for this currency
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FText Label;

	// current amount held of this value
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int CurrentHolding{ 0 };

	// maximum amount that can be held.
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int MaxHolding{ 10 };

	FCurrencyContainer() {};
	FCurrencyContainer(FString _Label, int _Current = 0, int _Max = 100) 
	{

		Label = FText::FromString(_Label);
		CurrentHolding = _Current;
		MaxHolding = _Max;
	};

public:

	int SetMaxHold(const int NewMax) { MaxHolding = NewMax; return MaxHolding; };

	// add to current holding. returns whether full value fit.
	bool Add(const int AmountToAdd, int& Remainder)
	{
		
		if (CurrentHolding + AmountToAdd > MaxHolding)
		{
			Remainder = FMath::Abs(CurrentHolding + AmountToAdd - MaxHolding);
			CurrentHolding = MaxHolding;
			return false;
		}

		CurrentHolding += AmountToAdd;
		return true;
	};

	bool Subtract(const int AmountToRemove, const bool bFullAmountOnly, int& Remainder)
	{
		if (bFullAmountOnly && !HasAtLeast(AmountToRemove)) 
			return false;

		Remainder = 0;
		if (CurrentHolding < AmountToRemove)
		{
			Remainder = FMath::Abs(CurrentHolding - AmountToRemove);
			CurrentHolding = FMath::Clamp(CurrentHolding - AmountToRemove, 0, MaxHolding);
			return true;
		}

		CurrentHolding -= AmountToRemove;
		return true;
	}

	bool HasAtLeast(const int MinimumAmount)
	{
		return CurrentHolding >= MinimumAmount;
	}
};

/* Progressable currency allows for fractional gains to mount up to a single unit of Currency.Similar to a level / xp system,
	values added should be fractional, when fraction reaches 1.0, a full unit is added to the total and the fraction resets to 0, carrying over any excess. */
USTRUCT(BlueprintType)
struct FProgressableCurrency
{
	GENERATED_BODY()

	// should be a unique name. Used when searching for a currency by name when the index is unknown.
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FName CurrencyName;

	UPROPERTY(BlueprintReadOnly)
	int TotalHeld{ 0 };

	UPROPERTY(BlueprintReadOnly)
	float FractionHeld{ 0.f };

	UPROPERTY(BlueprintReadOnly)
	float ValuePerWhole{ 1.0f };

	UPROPERTY(BlueprintReadOnly)
	int MaxHoldable{ 10 };

	bool operator ==(FName Comparator)
	{
		return CurrencyName.IsEqual(Comparator);
	};

	bool IsEqual(const FName Comparator) const
	{
		return CurrencyName.IsEqual(Comparator);
	};

	FProgressableCurrency() {};

	FProgressableCurrency(const int StartAmount, const float StartFraction, const float RequiredForWhole, const int MaximumHoldable)
	{
		TotalHeld = StartAmount;
		FractionHeld = StartFraction;
		ValuePerWhole = RequiredForWhole;
		MaxHoldable = MaximumHoldable;
	};

	bool AddFraction(const float AmountToAdd)
	{
		double Remainder; 
		int WholeUnits = UKismetMathLibrary::FMod(AmountToAdd, ValuePerWhole, Remainder);

		FractionHeld += Remainder;
		TotalHeld = FMath::Clamp(TotalHeld + WholeUnits, 0, MaxHoldable);

		if (UKismetMathLibrary::NearlyEqual_FloatFloat(FractionHeld, TotalHeld, 1.0E-6) || FractionHeld >= ValuePerWhole && TotalHeld < MaxHoldable)
		{
			FractionHeld = FractionHeld - ValuePerWhole;
			TotalHeld = FMath::Clamp(TotalHeld + 1, 0, MaxHoldable);
		}

		FractionHeld = FMath::Clamp(FractionHeld, 0.f, ValuePerWhole);
		return true;
	};

	bool SubtractUnit(const int NumUnits, const bool bExactOnly, int& NumRemoved)
	{
		//if exact only is specified and total held can't cater for the NumUnits then don't proceed.
		if (bExactOnly && NumUnits > TotalHeld) return false;

		//NumRemoved can't exceed total held.
		NumRemoved = FMath::Clamp(NumUnits, 0, TotalHeld);
		TotalHeld = FMath::Clamp(TotalHeld - NumRemoved, 0, MaxHoldable); // for good measure
		return true;
	};

};

USTRUCT(BlueprintType)
struct FCodexInventory 
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadOnly)
	TArray<FName> CollectedCodex;

	bool Contains(const FName Codex) const
	{
		return CollectedCodex.Contains(Codex);
	};

	bool Add(const FName Codex)
	{
		return CollectedCodex.AddUnique(Codex) >= 0;
	};

};


DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnInventoryChanged);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnNewCodexCollected);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class WOBGASSYSTEM_API UGasInventory : public UActorComponent
{
	GENERATED_BODY()

public:	

	// Sets default values for this component's properties
	UGasInventory();

	UPROPERTY(BlueprintAssignable, BlueprintCallable, Category ="Events")
	FOnNewCodexCollected OnNewCodexCollected;

	UFUNCTION(BlueprintCallable, Category = "Inventory")
	bool HasCodex(const FName Codex)
	{
		return CollectedCodex.Contains(Codex);
	};

	UFUNCTION(BlueprintCallable, Category = "Inventory")
	bool AddCodex(const FName Codex)
	{
		if (CollectedCodex.Add(Codex))
		{
			OnNewCodexCollected.Broadcast();
			return true;
		}
		return false;
	};

	UFUNCTION(BlueprintCallable, Category = "Inventory")
	TArray<FName> GetCodexCollection()
	{
		return CollectedCodex.CollectedCodex;
	}

	/* Delegate for tracking when the inventory is modified. This is invoked whenever a REQUEST is made to modify the inventory.
	Even if conditions fail, resulting in the inventory not actually being modified. */
	UPROPERTY(BlueprintCallable, BlueprintAssignable, Category ="Inventory")
	FOnInventoryChanged OnInventoryChanged;

	/*Add an item to the inventory. if FullStackOnly is flagged, then adding will fail if not all StackSize can fit in the inventory. Otherwise, only the amount that fits will be added, and the amount that
	couldn't fit will be returned as Remainder. */
	UFUNCTION(BlueprintCallable, Category ="Inventory")
	bool AddItemById(const FName ItemId, const int StackSize, const int MaxStackSize, int& Remainder, bool bFullStackOnly = true);

	/*Slot struct version of AddItemById. See AddItemById for parameter breakdown.*/
	UFUNCTION(BlueprintCallable, Category = "Inventory")
	bool AddItemAsSlot(const FGasInventorySlot SlotItem, int& Remainder, bool bFullStackOnly = true);

	/*Remove stacks of the specified item ID from the inventory. if AllOrNothing is flagged, nothing will be removed if the inventory doesn't contain at least the 
	Num specified. if AllOrNothing is false, and the total number couldn't be removed, the deficit will be returned as Remainder.*/
	UFUNCTION(BlueprintCallable, Category = "Inventory")
	bool ReduceItemById(const FName ItemId, const int Num, int& Remainder, bool bAllOrNothing);
	
	/*FGasInventorySlot struct version of ReduceItemById. See ReduceItemById for parameter breakdown. */
	UFUNCTION(BlueprintCallable, Category = "Inventory")
	bool ReduceItemBySlot(const FGasInventorySlot SlotItem, int& Remainder, bool bAllOrNothing);

	/*Get the total number held of the given item id. */
	UFUNCTION(BlueprintCallable, Category ="Inventory")
	int GetCountByItemId(const FName ItemId);

	/*FGasInventorySlot struct version of GetCountByItemId. */
	UFUNCTION(BlueprintCallable, Category = "Inventory")
	int GetCountOfBySlot(const FGasInventorySlot SlotItem);

	/*Completely remove all instances of the given ItemId from the inventory. */
	UFUNCTION(BlueprintCallable, Category ="Inventory")
	bool RemoveAllInstancesOfId(const FName ItemId);

	/*FGasInventorySlot struct version of RemoveAllInstancedOfId. */
	UFUNCTION(BlueprintCallable, Category="Inventory")
	bool RemoveAllInstancesOfSlot(const FGasInventorySlot SlotItem);

	/*Get a copy of all slots that hold the given ID. Modifying the data in these slots will not reflect unless you
	emplace the modified item back into the inventory slot it came from. */
	UFUNCTION(BlueprintCallable, Category ="Inventory")
	TArray<FGasInventorySlot> GetAllItemsById(const FName ItemId);

	/*FGasInventorySlot struct version of GetAllItemsById. Modifying the data in these slots will not reflect unless you
	emplace the modified item back into the inventory slot it came from.*/
	UFUNCTION(BlueprintCallable, Category = "Inventory")
	TArray<FGasInventorySlot> GetAllItemsBySlot(const FGasInventorySlot SlotItem);

	/*Swap two slots positions in the inventory. */
	UFUNCTION(BlueprintCallable, Category = "Inventory")
	bool SwapIndices(const int FirstIndex, const int SecondIndex);

	UFUNCTION(BlueprintCallable, Category = "Inventory")
	TArray<FGasInventorySlot> GetAllSlots() { return Inventory.Slots; };

	//Increase the current holding of the specified currency by the given amount. 
	UFUNCTION(BlueprintCallable, Category = "Currency")
	bool AddCurrencyByIndex(const int CurrencyIndex, const int AmountToAdd, int& Remainder)
	{
		if (!Currencies.IsValidIndex(CurrencyIndex)) return false;
		return Currencies[CurrencyIndex].Add(AmountToAdd, Remainder);
	};

	UFUNCTION(BlueprintCallable, Category ="Currency")
	bool SubtractCurrencyByIndex(const int CurrencyIndex, const int AmountToRemove, const bool bFullAmountOnly, int& Remainder)
	{
		if (!Currencies.IsValidIndex(CurrencyIndex)) return false;
		return Currencies[CurrencyIndex].Subtract(AmountToRemove, bFullAmountOnly, Remainder);
	}

	UFUNCTION(BlueprintCallable, Category = "Progressable Currency")
	bool AddProgressableCurrencyFractionByIndex(const int CurrencyIndex, const float Fraction)
	{
		if (!ProgressableCurrencies.IsValidIndex(CurrencyIndex)) return false;
		return ProgressableCurrencies[CurrencyIndex].AddFraction(Fraction);
	}

	UFUNCTION(BlueprintCallable, Category = "Progressable Currency")
	bool AddProgressableCurrencyFractionByName(const FName CurrencyName, const float Fraction)
	{
		int Index = IndexOfProgressableCurrency(CurrencyName);
		return AddProgressableCurrencyFractionByIndex(Index, Fraction);
	}

	UFUNCTION(BlueprintCallable, Category = "Progressable Currency")
	bool SubtractProgressableCurrencyUnitsByIndex(const int CurrencyIndex, const int UnitsToSubtract, const bool bExactOnly, int& NumRemoved)
	{
		if (!ProgressableCurrencies.IsValidIndex(CurrencyIndex)) return false;
		return ProgressableCurrencies[CurrencyIndex].SubtractUnit(UnitsToSubtract, bExactOnly, NumRemoved);
	}

	UFUNCTION(BlueprintCallable, Category = "Progressable Currency")
	bool SubtractProgressableCurrencyUnitsByName(const FName CurrencyName, const int UnitsToSubtract, const bool bExactOnly, int& NumRemoved)
	{
		int Index = IndexOfProgressableCurrency(CurrencyName);
		return SubtractProgressableCurrencyUnitsByIndex(Index, UnitsToSubtract, bExactOnly, NumRemoved);
	}

	UFUNCTION(BlueprintCallable, Category = "Progressable Currency")
	bool GetTotalProgressableCurrencyUnitsHeldByIndex(const int CurrencyIndex, int& NumHeld, float& FractionHeld)
	{
		if (!ProgressableCurrencies.IsValidIndex(CurrencyIndex)) return false;
		NumHeld = ProgressableCurrencies[CurrencyIndex].TotalHeld;
		FractionHeld = ProgressableCurrencies[CurrencyIndex].FractionHeld;
		return true;
	}


protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	UPROPERTY(SaveGame, BlueprintReadWrite, EditAnywhere, Category ="Codex")
	FCodexInventory CollectedCodex;

	// main inventory. Holds any items by an ItemID and supports stacking
	UPROPERTY(SaveGame, BlueprintReadWrite, EditAnywhere, Category="Inventory")
	FGasInventoryStruct Inventory{FGasInventoryStruct()};

	//Integer based currencies that don't support fractions. Only supports Integer add/subtract.
	UPROPERTY(SaveGame, BlueprintReadWrite, EditAnywhere, Category="Currency")
	TArray<FCurrencyContainer> Currencies;

	// Fractional based currencies. Values are added as fractions that convert to whole units when reaching the threshold.
	// Fractions cannot be reduced directly, but can be increased.  Whole units cannot be increased directly, but can be reduced.
	UPROPERTY(SaveGame, BlueprintReadWrite, EditAnywhere, Category = "Progressable Currency")
	TArray<FProgressableCurrency> ProgressableCurrencies;


private :

	int BaseMaxCurrency{ 100 };

	int IndexOfProgressableCurrency(const FName CurrencyName);
public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
};
