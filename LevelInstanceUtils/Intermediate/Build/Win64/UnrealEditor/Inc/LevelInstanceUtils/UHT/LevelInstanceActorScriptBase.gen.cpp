// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "LevelInstanceUtils/Public/Object/LevelInstanceActorScriptBase.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeLevelInstanceActorScriptBase() {}

// Begin Cross Module References
COREUOBJECT_API UClass* Z_Construct_UClass_UObject();
ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
LEVELINSTANCEUTILS_API UClass* Z_Construct_UClass_ULevelInstanceActorScriptBase();
LEVELINSTANCEUTILS_API UClass* Z_Construct_UClass_ULevelInstanceActorScriptBase_NoRegister();
UPackage* Z_Construct_UPackage__Script_LevelInstanceUtils();
// End Cross Module References

// Begin Class ULevelInstanceActorScriptBase Function Execute
struct LevelInstanceActorScriptBase_eventExecute_Parms
{
	AActor* Target;
};
static const FName NAME_ULevelInstanceActorScriptBase_Execute = FName(TEXT("Execute"));
void ULevelInstanceActorScriptBase::Execute(AActor* Target)
{
	LevelInstanceActorScriptBase_eventExecute_Parms Parms;
	Parms.Target=Target;
	UFunction* Func = FindFunctionChecked(NAME_ULevelInstanceActorScriptBase_Execute);
	ProcessEvent(Func,&Parms);
}
struct Z_Construct_UFunction_ULevelInstanceActorScriptBase_Execute_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "ActorScript" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "//execute the script\n" },
#endif
		{ "ModuleRelativePath", "Public/Object/LevelInstanceActorScriptBase.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "execute the script" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Target;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_ULevelInstanceActorScriptBase_Execute_Statics::NewProp_Target = { "Target", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(LevelInstanceActorScriptBase_eventExecute_Parms, Target), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ULevelInstanceActorScriptBase_Execute_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULevelInstanceActorScriptBase_Execute_Statics::NewProp_Target,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ULevelInstanceActorScriptBase_Execute_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ULevelInstanceActorScriptBase_Execute_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ULevelInstanceActorScriptBase, nullptr, "Execute", nullptr, nullptr, Z_Construct_UFunction_ULevelInstanceActorScriptBase_Execute_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ULevelInstanceActorScriptBase_Execute_Statics::PropPointers), sizeof(LevelInstanceActorScriptBase_eventExecute_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x0C020800, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ULevelInstanceActorScriptBase_Execute_Statics::Function_MetaDataParams), Z_Construct_UFunction_ULevelInstanceActorScriptBase_Execute_Statics::Function_MetaDataParams) };
static_assert(sizeof(LevelInstanceActorScriptBase_eventExecute_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ULevelInstanceActorScriptBase_Execute()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ULevelInstanceActorScriptBase_Execute_Statics::FuncParams);
	}
	return ReturnFunction;
}
// End Class ULevelInstanceActorScriptBase Function Execute

// Begin Class ULevelInstanceActorScriptBase
void ULevelInstanceActorScriptBase::StaticRegisterNativesULevelInstanceActorScriptBase()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ULevelInstanceActorScriptBase);
UClass* Z_Construct_UClass_ULevelInstanceActorScriptBase_NoRegister()
{
	return ULevelInstanceActorScriptBase::StaticClass();
}
struct Z_Construct_UClass_ULevelInstanceActorScriptBase_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "IncludePath", "Object/LevelInstanceActorScriptBase.h" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Public/Object/LevelInstanceActorScriptBase.h" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_ULevelInstanceActorScriptBase_Execute, "Execute" }, // 608847858
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ULevelInstanceActorScriptBase>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_ULevelInstanceActorScriptBase_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UObject,
	(UObject* (*)())Z_Construct_UPackage__Script_LevelInstanceUtils,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ULevelInstanceActorScriptBase_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_ULevelInstanceActorScriptBase_Statics::ClassParams = {
	&ULevelInstanceActorScriptBase::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	nullptr,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	0,
	0,
	0x001000A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ULevelInstanceActorScriptBase_Statics::Class_MetaDataParams), Z_Construct_UClass_ULevelInstanceActorScriptBase_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_ULevelInstanceActorScriptBase()
{
	if (!Z_Registration_Info_UClass_ULevelInstanceActorScriptBase.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ULevelInstanceActorScriptBase.OuterSingleton, Z_Construct_UClass_ULevelInstanceActorScriptBase_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_ULevelInstanceActorScriptBase.OuterSingleton;
}
template<> LEVELINSTANCEUTILS_API UClass* StaticClass<ULevelInstanceActorScriptBase>()
{
	return ULevelInstanceActorScriptBase::StaticClass();
}
ULevelInstanceActorScriptBase::ULevelInstanceActorScriptBase(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR(ULevelInstanceActorScriptBase);
ULevelInstanceActorScriptBase::~ULevelInstanceActorScriptBase() {}
// End Class ULevelInstanceActorScriptBase

// Begin Registration
struct Z_CompiledInDeferFile_FID_SourceControl_CatalystDepot_WarOfBeing_Plugins_LevelInstanceUtils_Source_LevelInstanceUtils_Public_Object_LevelInstanceActorScriptBase_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_ULevelInstanceActorScriptBase, ULevelInstanceActorScriptBase::StaticClass, TEXT("ULevelInstanceActorScriptBase"), &Z_Registration_Info_UClass_ULevelInstanceActorScriptBase, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ULevelInstanceActorScriptBase), 1444833412U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_SourceControl_CatalystDepot_WarOfBeing_Plugins_LevelInstanceUtils_Source_LevelInstanceUtils_Public_Object_LevelInstanceActorScriptBase_h_1125552996(TEXT("/Script/LevelInstanceUtils"),
	Z_CompiledInDeferFile_FID_SourceControl_CatalystDepot_WarOfBeing_Plugins_LevelInstanceUtils_Source_LevelInstanceUtils_Public_Object_LevelInstanceActorScriptBase_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_SourceControl_CatalystDepot_WarOfBeing_Plugins_LevelInstanceUtils_Source_LevelInstanceUtils_Public_Object_LevelInstanceActorScriptBase_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
