// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"


UENUM(Blueprintable)
enum class EActionEventTypes : uint8
{
	Sequence,
	ButtonMash,
	Precision
};