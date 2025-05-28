// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "LevelInstanceUtils/Public/ActorComponent/LevelInstanceActorScriptComponent.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeLevelInstanceActorScriptComponent() {}

// Begin Cross Module References
ENGINE_API UClass* Z_Construct_UClass_UActorComponent();
LEVELINSTANCEUTILS_API UClass* Z_Construct_UClass_ULevelInstanceActorScriptComponent();
LEVELINSTANCEUTILS_API UClass* Z_Construct_UClass_ULevelInstanceActorScriptComponent_NoRegister();
UPackage* Z_Construct_UPackage__Script_LevelInstanceUtils();
// End Cross Module References

// Begin Class ULevelInstanceActorScriptComponent Function GetLevelInstanceManagerName
struct Z_Construct_UFunction_ULevelInstanceActorScriptComponent_GetLevelInstanceManagerName_Statics
{
	struct LevelInstanceActorScriptComponent_eventGetLevelInstanceManagerName_Parms
	{
		FName ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "LevelInstanceManager" },
		{ "ModuleRelativePath", "Public/ActorComponent/LevelInstanceActorScriptComponent.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FNamePropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FNamePropertyParams Z_Construct_UFunction_ULevelInstanceActorScriptComponent_GetLevelInstanceManagerName_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(LevelInstanceActorScriptComponent_eventGetLevelInstanceManagerName_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ULevelInstanceActorScriptComponent_GetLevelInstanceManagerName_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULevelInstanceActorScriptComponent_GetLevelInstanceManagerName_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ULevelInstanceActorScriptComponent_GetLevelInstanceManagerName_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ULevelInstanceActorScriptComponent_GetLevelInstanceManagerName_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ULevelInstanceActorScriptComponent, nullptr, "GetLevelInstanceManagerName", nullptr, nullptr, Z_Construct_UFunction_ULevelInstanceActorScriptComponent_GetLevelInstanceManagerName_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ULevelInstanceActorScriptComponent_GetLevelInstanceManagerName_Statics::PropPointers), sizeof(Z_Construct_UFunction_ULevelInstanceActorScriptComponent_GetLevelInstanceManagerName_Statics::LevelInstanceActorScriptComponent_eventGetLevelInstanceManagerName_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ULevelInstanceActorScriptComponent_GetLevelInstanceManagerName_Statics::Function_MetaDataParams), Z_Construct_UFunction_ULevelInstanceActorScriptComponent_GetLevelInstanceManagerName_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_ULevelInstanceActorScriptComponent_GetLevelInstanceManagerName_Statics::LevelInstanceActorScriptComponent_eventGetLevelInstanceManagerName_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ULevelInstanceActorScriptComponent_GetLevelInstanceManagerName()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ULevelInstanceActorScriptComponent_GetLevelInstanceManagerName_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ULevelInstanceActorScriptComponent::execGetLevelInstanceManagerName)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FName*)Z_Param__Result=P_THIS->GetLevelInstanceManagerName();
	P_NATIVE_END;
}
// End Class ULevelInstanceActorScriptComponent Function GetLevelInstanceManagerName

// Begin Class ULevelInstanceActorScriptComponent Function RequestScript
struct Z_Construct_UFunction_ULevelInstanceActorScriptComponent_RequestScript_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/ActorComponent/LevelInstanceActorScriptComponent.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ULevelInstanceActorScriptComponent_RequestScript_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ULevelInstanceActorScriptComponent, nullptr, "RequestScript", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00080401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ULevelInstanceActorScriptComponent_RequestScript_Statics::Function_MetaDataParams), Z_Construct_UFunction_ULevelInstanceActorScriptComponent_RequestScript_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_ULevelInstanceActorScriptComponent_RequestScript()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ULevelInstanceActorScriptComponent_RequestScript_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ULevelInstanceActorScriptComponent::execRequestScript)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->RequestScript();
	P_NATIVE_END;
}
// End Class ULevelInstanceActorScriptComponent Function RequestScript

// Begin Class ULevelInstanceActorScriptComponent
void ULevelInstanceActorScriptComponent::StaticRegisterNativesULevelInstanceActorScriptComponent()
{
	UClass* Class = ULevelInstanceActorScriptComponent::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "GetLevelInstanceManagerName", &ULevelInstanceActorScriptComponent::execGetLevelInstanceManagerName },
		{ "RequestScript", &ULevelInstanceActorScriptComponent::execRequestScript },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ULevelInstanceActorScriptComponent);
UClass* Z_Construct_UClass_ULevelInstanceActorScriptComponent_NoRegister()
{
	return ULevelInstanceActorScriptComponent::StaticClass();
}
struct Z_Construct_UClass_ULevelInstanceActorScriptComponent_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintSpawnableComponent", "" },
		{ "ClassGroupNames", "Custom" },
		{ "IncludePath", "ActorComponent/LevelInstanceActorScriptComponent.h" },
		{ "ModuleRelativePath", "Public/ActorComponent/LevelInstanceActorScriptComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ManagerName_MetaData[] = {
		{ "Category", "Settings" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "//The name of the manager actor that this component's owner should request its script from.\n" },
#endif
		{ "ModuleRelativePath", "Public/ActorComponent/LevelInstanceActorScriptComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "The name of the manager actor that this component's owner should request its script from." },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FNamePropertyParams NewProp_ManagerName;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_ULevelInstanceActorScriptComponent_GetLevelInstanceManagerName, "GetLevelInstanceManagerName" }, // 4094058370
		{ &Z_Construct_UFunction_ULevelInstanceActorScriptComponent_RequestScript, "RequestScript" }, // 3109015213
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ULevelInstanceActorScriptComponent>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FNamePropertyParams Z_Construct_UClass_ULevelInstanceActorScriptComponent_Statics::NewProp_ManagerName = { "ManagerName", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ULevelInstanceActorScriptComponent, ManagerName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ManagerName_MetaData), NewProp_ManagerName_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ULevelInstanceActorScriptComponent_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ULevelInstanceActorScriptComponent_Statics::NewProp_ManagerName,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ULevelInstanceActorScriptComponent_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_ULevelInstanceActorScriptComponent_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UActorComponent,
	(UObject* (*)())Z_Construct_UPackage__Script_LevelInstanceUtils,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ULevelInstanceActorScriptComponent_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_ULevelInstanceActorScriptComponent_Statics::ClassParams = {
	&ULevelInstanceActorScriptComponent::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_ULevelInstanceActorScriptComponent_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_ULevelInstanceActorScriptComponent_Statics::PropPointers),
	0,
	0x00B000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ULevelInstanceActorScriptComponent_Statics::Class_MetaDataParams), Z_Construct_UClass_ULevelInstanceActorScriptComponent_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_ULevelInstanceActorScriptComponent()
{
	if (!Z_Registration_Info_UClass_ULevelInstanceActorScriptComponent.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ULevelInstanceActorScriptComponent.OuterSingleton, Z_Construct_UClass_ULevelInstanceActorScriptComponent_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_ULevelInstanceActorScriptComponent.OuterSingleton;
}
template<> LEVELINSTANCEUTILS_API UClass* StaticClass<ULevelInstanceActorScriptComponent>()
{
	return ULevelInstanceActorScriptComponent::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(ULevelInstanceActorScriptComponent);
ULevelInstanceActorScriptComponent::~ULevelInstanceActorScriptComponent() {}
// End Class ULevelInstanceActorScriptComponent

// Begin Registration
struct Z_CompiledInDeferFile_FID_SourceControl_CatalystDepot_WarOfBeing_Plugins_LevelInstanceUtils_Source_LevelInstanceUtils_Public_ActorComponent_LevelInstanceActorScriptComponent_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_ULevelInstanceActorScriptComponent, ULevelInstanceActorScriptComponent::StaticClass, TEXT("ULevelInstanceActorScriptComponent"), &Z_Registration_Info_UClass_ULevelInstanceActorScriptComponent, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ULevelInstanceActorScriptComponent), 2325339122U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_SourceControl_CatalystDepot_WarOfBeing_Plugins_LevelInstanceUtils_Source_LevelInstanceUtils_Public_ActorComponent_LevelInstanceActorScriptComponent_h_3646361949(TEXT("/Script/LevelInstanceUtils"),
	Z_CompiledInDeferFile_FID_SourceControl_CatalystDepot_WarOfBeing_Plugins_LevelInstanceUtils_Source_LevelInstanceUtils_Public_ActorComponent_LevelInstanceActorScriptComponent_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_SourceControl_CatalystDepot_WarOfBeing_Plugins_LevelInstanceUtils_Source_LevelInstanceUtils_Public_ActorComponent_LevelInstanceActorScriptComponent_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
