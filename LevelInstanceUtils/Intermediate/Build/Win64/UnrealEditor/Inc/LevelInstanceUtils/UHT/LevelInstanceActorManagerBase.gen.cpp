// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "LevelInstanceUtils/Public/Actor/LevelInstanceActorManagerBase.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeLevelInstanceActorManagerBase() {}

// Begin Cross Module References
COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FGuid();
ENGINE_API UClass* Z_Construct_UClass_AActor();
ENGINE_API UClass* Z_Construct_UClass_ALevelInstance_NoRegister();
LEVELINSTANCEUTILS_API UClass* Z_Construct_UClass_ALevelInstanceActorManagerBase();
LEVELINSTANCEUTILS_API UClass* Z_Construct_UClass_ALevelInstanceActorManagerBase_NoRegister();
LEVELINSTANCEUTILS_API UClass* Z_Construct_UClass_ULevelInstanceActorScriptBase_NoRegister();
LEVELINSTANCEUTILS_API UScriptStruct* Z_Construct_UScriptStruct_FLevelInstanceManagerClientData();
UPackage* Z_Construct_UPackage__Script_LevelInstanceUtils();
// End Cross Module References

// Begin ScriptStruct FLevelInstanceManagerClientData
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_LevelInstanceManagerClientData;
class UScriptStruct* FLevelInstanceManagerClientData::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_LevelInstanceManagerClientData.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_LevelInstanceManagerClientData.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FLevelInstanceManagerClientData, (UObject*)Z_Construct_UPackage__Script_LevelInstanceUtils(), TEXT("LevelInstanceManagerClientData"));
	}
	return Z_Registration_Info_UScriptStruct_LevelInstanceManagerClientData.OuterSingleton;
}
template<> LEVELINSTANCEUTILS_API UScriptStruct* StaticStruct<FLevelInstanceManagerClientData>()
{
	return FLevelInstanceManagerClientData::StaticStruct();
}
struct Z_Construct_UScriptStruct_FLevelInstanceManagerClientData_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/Actor/LevelInstanceActorManagerBase.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OwningLevelInstance_MetaData[] = {
		{ "Category", "Instance" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "//For reference only. The name of the Level instance this actor is part of. Populated when using the editor macro.\n" },
#endif
		{ "ModuleRelativePath", "Public/Actor/LevelInstanceActorManagerBase.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "For reference only. The name of the Level instance this actor is part of. Populated when using the editor macro." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ActorName_MetaData[] = {
		{ "Category", "Actor" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "//For Reference only. The FName of the associated actor. This is the shared name of the actor that is identical in every instance. Populated when using the editor macro.\n" },
#endif
		{ "ModuleRelativePath", "Public/Actor/LevelInstanceActorManagerBase.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "For Reference only. The FName of the associated actor. This is the shared name of the actor that is identical in every instance. Populated when using the editor macro." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_FriendlyName_MetaData[] = {
		{ "Category", "Friendly Name" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "//A user friendly name to help designers identify this actor in the editor.\n" },
#endif
		{ "ModuleRelativePath", "Public/Actor/LevelInstanceActorManagerBase.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "A user friendly name to help designers identify this actor in the editor." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ScriptClass_MetaData[] = {
		{ "Category", "Script" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "//The script class that should be handed to the key actor on request\n" },
#endif
		{ "ModuleRelativePath", "Public/Actor/LevelInstanceActorManagerBase.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "The script class that should be handed to the key actor on request" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FNamePropertyParams NewProp_OwningLevelInstance;
	static const UECodeGen_Private::FNamePropertyParams NewProp_ActorName;
	static const UECodeGen_Private::FNamePropertyParams NewProp_FriendlyName;
	static const UECodeGen_Private::FClassPropertyParams NewProp_ScriptClass;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FLevelInstanceManagerClientData>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
};
const UECodeGen_Private::FNamePropertyParams Z_Construct_UScriptStruct_FLevelInstanceManagerClientData_Statics::NewProp_OwningLevelInstance = { "OwningLevelInstance", nullptr, (EPropertyFlags)0x0010000000020015, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FLevelInstanceManagerClientData, OwningLevelInstance), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OwningLevelInstance_MetaData), NewProp_OwningLevelInstance_MetaData) };
const UECodeGen_Private::FNamePropertyParams Z_Construct_UScriptStruct_FLevelInstanceManagerClientData_Statics::NewProp_ActorName = { "ActorName", nullptr, (EPropertyFlags)0x0010000000020015, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FLevelInstanceManagerClientData, ActorName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ActorName_MetaData), NewProp_ActorName_MetaData) };
const UECodeGen_Private::FNamePropertyParams Z_Construct_UScriptStruct_FLevelInstanceManagerClientData_Statics::NewProp_FriendlyName = { "FriendlyName", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FLevelInstanceManagerClientData, FriendlyName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FriendlyName_MetaData), NewProp_FriendlyName_MetaData) };
const UECodeGen_Private::FClassPropertyParams Z_Construct_UScriptStruct_FLevelInstanceManagerClientData_Statics::NewProp_ScriptClass = { "ScriptClass", nullptr, (EPropertyFlags)0x0014000000000005, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FLevelInstanceManagerClientData, ScriptClass), Z_Construct_UClass_UClass, Z_Construct_UClass_ULevelInstanceActorScriptBase_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ScriptClass_MetaData), NewProp_ScriptClass_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FLevelInstanceManagerClientData_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FLevelInstanceManagerClientData_Statics::NewProp_OwningLevelInstance,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FLevelInstanceManagerClientData_Statics::NewProp_ActorName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FLevelInstanceManagerClientData_Statics::NewProp_FriendlyName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FLevelInstanceManagerClientData_Statics::NewProp_ScriptClass,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FLevelInstanceManagerClientData_Statics::PropPointers) < 2048);
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FLevelInstanceManagerClientData_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_LevelInstanceUtils,
	nullptr,
	&NewStructOps,
	"LevelInstanceManagerClientData",
	Z_Construct_UScriptStruct_FLevelInstanceManagerClientData_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FLevelInstanceManagerClientData_Statics::PropPointers),
	sizeof(FLevelInstanceManagerClientData),
	alignof(FLevelInstanceManagerClientData),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FLevelInstanceManagerClientData_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FLevelInstanceManagerClientData_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FLevelInstanceManagerClientData()
{
	if (!Z_Registration_Info_UScriptStruct_LevelInstanceManagerClientData.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_LevelInstanceManagerClientData.InnerSingleton, Z_Construct_UScriptStruct_FLevelInstanceManagerClientData_Statics::StructParams);
	}
	return Z_Registration_Info_UScriptStruct_LevelInstanceManagerClientData.InnerSingleton;
}
// End ScriptStruct FLevelInstanceManagerClientData

// Begin Class ALevelInstanceActorManagerBase Function ApplyInEditor
#if WITH_EDITOR
struct Z_Construct_UFunction_ALevelInstanceActorManagerBase_ApplyInEditor_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "CallInEditor", "true" },
		{ "Category", "Editor" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/* Apply the scripts at design time. This is for previewing only and script executions will not persist in map save state.\n\x09   This will only apply to actors that were discovered using ClaimGuidsFromLevel.\n\x09*/" },
#endif
		{ "ModuleRelativePath", "Public/Actor/LevelInstanceActorManagerBase.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Apply the scripts at design time. This is for previewing only and script executions will not persist in map save state.\n         This will only apply to actors that were discovered using ClaimGuidsFromLevel." },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ALevelInstanceActorManagerBase_ApplyInEditor_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ALevelInstanceActorManagerBase, nullptr, "ApplyInEditor", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x24020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ALevelInstanceActorManagerBase_ApplyInEditor_Statics::Function_MetaDataParams), Z_Construct_UFunction_ALevelInstanceActorManagerBase_ApplyInEditor_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_ALevelInstanceActorManagerBase_ApplyInEditor()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ALevelInstanceActorManagerBase_ApplyInEditor_Statics::FuncParams);
	}
	return ReturnFunction;
}
#endif // WITH_EDITOR
#if WITH_EDITOR
DEFINE_FUNCTION(ALevelInstanceActorManagerBase::execApplyInEditor)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->ApplyInEditor();
	P_NATIVE_END;
}
#endif // WITH_EDITOR
// End Class ALevelInstanceActorManagerBase Function ApplyInEditor

// Begin Class ALevelInstanceActorManagerBase Function ClaimGuidsFromLevel
#if WITH_EDITOR
struct Z_Construct_UFunction_ALevelInstanceActorManagerBase_ClaimGuidsFromLevel_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "CallInEditor", "true" },
		{ "Category", "Editor" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*Automatically create Map Keys from Guids in the specified Level Instance.Helper function to speed up populating this managers clients.\n\x09This is the prefered method for populating clients and is necessary for previewing changes in editor using ApplyInEditor();\n\x09*/" },
#endif
		{ "ModuleRelativePath", "Public/Actor/LevelInstanceActorManagerBase.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Automatically create Map Keys from Guids in the specified Level Instance.Helper function to speed up populating this managers clients.\n       This is the prefered method for populating clients and is necessary for previewing changes in editor using ApplyInEditor();" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ALevelInstanceActorManagerBase_ClaimGuidsFromLevel_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ALevelInstanceActorManagerBase, nullptr, "ClaimGuidsFromLevel", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x24020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ALevelInstanceActorManagerBase_ClaimGuidsFromLevel_Statics::Function_MetaDataParams), Z_Construct_UFunction_ALevelInstanceActorManagerBase_ClaimGuidsFromLevel_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_ALevelInstanceActorManagerBase_ClaimGuidsFromLevel()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ALevelInstanceActorManagerBase_ClaimGuidsFromLevel_Statics::FuncParams);
	}
	return ReturnFunction;
}
#endif // WITH_EDITOR
#if WITH_EDITOR
DEFINE_FUNCTION(ALevelInstanceActorManagerBase::execClaimGuidsFromLevel)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->ClaimGuidsFromLevel();
	P_NATIVE_END;
}
#endif // WITH_EDITOR
// End Class ALevelInstanceActorManagerBase Function ClaimGuidsFromLevel

// Begin Class ALevelInstanceActorManagerBase Function RequestScript
struct Z_Construct_UFunction_ALevelInstanceActorManagerBase_RequestScript_Statics
{
	struct LevelInstanceActorManagerBase_eventRequestScript_Parms
	{
		FGuid Guid;
		TSubclassOf<ULevelInstanceActorScriptBase> ScriptClass;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "LevelInstanceManager" },
		{ "ModuleRelativePath", "Public/Actor/LevelInstanceActorManagerBase.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_Guid;
	static const UECodeGen_Private::FClassPropertyParams NewProp_ScriptClass;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_ALevelInstanceActorManagerBase_RequestScript_Statics::NewProp_Guid = { "Guid", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(LevelInstanceActorManagerBase_eventRequestScript_Parms, Guid), Z_Construct_UScriptStruct_FGuid, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FClassPropertyParams Z_Construct_UFunction_ALevelInstanceActorManagerBase_RequestScript_Statics::NewProp_ScriptClass = { "ScriptClass", nullptr, (EPropertyFlags)0x0014000000000180, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(LevelInstanceActorManagerBase_eventRequestScript_Parms, ScriptClass), Z_Construct_UClass_UClass, Z_Construct_UClass_ULevelInstanceActorScriptBase_NoRegister, METADATA_PARAMS(0, nullptr) };
void Z_Construct_UFunction_ALevelInstanceActorManagerBase_RequestScript_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((LevelInstanceActorManagerBase_eventRequestScript_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_ALevelInstanceActorManagerBase_RequestScript_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(LevelInstanceActorManagerBase_eventRequestScript_Parms), &Z_Construct_UFunction_ALevelInstanceActorManagerBase_RequestScript_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ALevelInstanceActorManagerBase_RequestScript_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ALevelInstanceActorManagerBase_RequestScript_Statics::NewProp_Guid,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ALevelInstanceActorManagerBase_RequestScript_Statics::NewProp_ScriptClass,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ALevelInstanceActorManagerBase_RequestScript_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ALevelInstanceActorManagerBase_RequestScript_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ALevelInstanceActorManagerBase_RequestScript_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ALevelInstanceActorManagerBase, nullptr, "RequestScript", nullptr, nullptr, Z_Construct_UFunction_ALevelInstanceActorManagerBase_RequestScript_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ALevelInstanceActorManagerBase_RequestScript_Statics::PropPointers), sizeof(Z_Construct_UFunction_ALevelInstanceActorManagerBase_RequestScript_Statics::LevelInstanceActorManagerBase_eventRequestScript_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04C20401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ALevelInstanceActorManagerBase_RequestScript_Statics::Function_MetaDataParams), Z_Construct_UFunction_ALevelInstanceActorManagerBase_RequestScript_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_ALevelInstanceActorManagerBase_RequestScript_Statics::LevelInstanceActorManagerBase_eventRequestScript_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ALevelInstanceActorManagerBase_RequestScript()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ALevelInstanceActorManagerBase_RequestScript_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ALevelInstanceActorManagerBase::execRequestScript)
{
	P_GET_STRUCT(FGuid,Z_Param_Guid);
	P_GET_OBJECT_REF_NO_PTR(TSubclassOf<ULevelInstanceActorScriptBase>,Z_Param_Out_ScriptClass);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->RequestScript(Z_Param_Guid,Z_Param_Out_ScriptClass);
	P_NATIVE_END;
}
// End Class ALevelInstanceActorManagerBase Function RequestScript

// Begin Class ALevelInstanceActorManagerBase
void ALevelInstanceActorManagerBase::StaticRegisterNativesALevelInstanceActorManagerBase()
{
	UClass* Class = ALevelInstanceActorManagerBase::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
#if WITH_EDITOR
		{ "ApplyInEditor", &ALevelInstanceActorManagerBase::execApplyInEditor },
		{ "ClaimGuidsFromLevel", &ALevelInstanceActorManagerBase::execClaimGuidsFromLevel },
#endif // WITH_EDITOR
		{ "RequestScript", &ALevelInstanceActorManagerBase::execRequestScript },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ALevelInstanceActorManagerBase);
UClass* Z_Construct_UClass_ALevelInstanceActorManagerBase_NoRegister()
{
	return ALevelInstanceActorManagerBase::StaticClass();
}
struct Z_Construct_UClass_ALevelInstanceActorManagerBase_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "IncludePath", "Actor/LevelInstanceActorManagerBase.h" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Public/Actor/LevelInstanceActorManagerBase.h" },
	};
#if WITH_EDITORONLY_DATA
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_LevelInstanceToQuery_MetaData[] = {
		{ "Category", "Editor" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "//When set, ClaimGuidsFromLevel will use the specified Level Instance to build its FGuid Map.\n" },
#endif
		{ "ModuleRelativePath", "Public/Actor/LevelInstanceActorManagerBase.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "When set, ClaimGuidsFromLevel will use the specified Level Instance to build its FGuid Map." },
#endif
	};
#endif // WITH_EDITORONLY_DATA
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ManagerName_MetaData[] = {
		{ "Category", "Manager Settings" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "//The name to register this instance under. This is the name actors will use to lookup its manager in the Subsystem.\n" },
#endif
		{ "ModuleRelativePath", "Public/Actor/LevelInstanceActorManagerBase.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "The name to register this instance under. This is the name actors will use to lookup its manager in the Subsystem." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_GuidScripts_MetaData[] = {
		{ "Category", "Actor Scripts" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Map of scripts associated with an actor Instance Guid. Use the utility to get the appropriate Guid for an actor.\n" },
#endif
		{ "ModuleRelativePath", "Public/Actor/LevelInstanceActorManagerBase.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Map of scripts associated with an actor Instance Guid. Use the utility to get the appropriate Guid for an actor." },
#endif
	};
#endif // WITH_METADATA
#if WITH_EDITORONLY_DATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_LevelInstanceToQuery;
#endif // WITH_EDITORONLY_DATA
	static const UECodeGen_Private::FNamePropertyParams NewProp_ManagerName;
	static const UECodeGen_Private::FStructPropertyParams NewProp_GuidScripts_ValueProp;
	static const UECodeGen_Private::FStructPropertyParams NewProp_GuidScripts_Key_KeyProp;
	static const UECodeGen_Private::FMapPropertyParams NewProp_GuidScripts;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
#if WITH_EDITOR
		{ &Z_Construct_UFunction_ALevelInstanceActorManagerBase_ApplyInEditor, "ApplyInEditor" }, // 2969719036
		{ &Z_Construct_UFunction_ALevelInstanceActorManagerBase_ClaimGuidsFromLevel, "ClaimGuidsFromLevel" }, // 4247855891
#endif // WITH_EDITOR
		{ &Z_Construct_UFunction_ALevelInstanceActorManagerBase_RequestScript, "RequestScript" }, // 2192678812
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ALevelInstanceActorManagerBase>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
#if WITH_EDITORONLY_DATA
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ALevelInstanceActorManagerBase_Statics::NewProp_LevelInstanceToQuery = { "LevelInstanceToQuery", nullptr, (EPropertyFlags)0x0010000800000005, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ALevelInstanceActorManagerBase, LevelInstanceToQuery), Z_Construct_UClass_ALevelInstance_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_LevelInstanceToQuery_MetaData), NewProp_LevelInstanceToQuery_MetaData) };
#endif // WITH_EDITORONLY_DATA
const UECodeGen_Private::FNamePropertyParams Z_Construct_UClass_ALevelInstanceActorManagerBase_Statics::NewProp_ManagerName = { "ManagerName", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ALevelInstanceActorManagerBase, ManagerName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ManagerName_MetaData), NewProp_ManagerName_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_ALevelInstanceActorManagerBase_Statics::NewProp_GuidScripts_ValueProp = { "GuidScripts", nullptr, (EPropertyFlags)0x0000000000000001, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 1, Z_Construct_UScriptStruct_FLevelInstanceManagerClientData, METADATA_PARAMS(0, nullptr) }; // 1269281236
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_ALevelInstanceActorManagerBase_Statics::NewProp_GuidScripts_Key_KeyProp = { "GuidScripts_Key", nullptr, (EPropertyFlags)0x0000000000000001, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FGuid, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FMapPropertyParams Z_Construct_UClass_ALevelInstanceActorManagerBase_Statics::NewProp_GuidScripts = { "GuidScripts", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Map, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ALevelInstanceActorManagerBase, GuidScripts), EMapPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_GuidScripts_MetaData), NewProp_GuidScripts_MetaData) }; // 1269281236
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ALevelInstanceActorManagerBase_Statics::PropPointers[] = {
#if WITH_EDITORONLY_DATA
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ALevelInstanceActorManagerBase_Statics::NewProp_LevelInstanceToQuery,
#endif // WITH_EDITORONLY_DATA
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ALevelInstanceActorManagerBase_Statics::NewProp_ManagerName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ALevelInstanceActorManagerBase_Statics::NewProp_GuidScripts_ValueProp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ALevelInstanceActorManagerBase_Statics::NewProp_GuidScripts_Key_KeyProp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ALevelInstanceActorManagerBase_Statics::NewProp_GuidScripts,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ALevelInstanceActorManagerBase_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_ALevelInstanceActorManagerBase_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AActor,
	(UObject* (*)())Z_Construct_UPackage__Script_LevelInstanceUtils,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ALevelInstanceActorManagerBase_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_ALevelInstanceActorManagerBase_Statics::ClassParams = {
	&ALevelInstanceActorManagerBase::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_ALevelInstanceActorManagerBase_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_ALevelInstanceActorManagerBase_Statics::PropPointers),
	0,
	0x009000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ALevelInstanceActorManagerBase_Statics::Class_MetaDataParams), Z_Construct_UClass_ALevelInstanceActorManagerBase_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_ALevelInstanceActorManagerBase()
{
	if (!Z_Registration_Info_UClass_ALevelInstanceActorManagerBase.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ALevelInstanceActorManagerBase.OuterSingleton, Z_Construct_UClass_ALevelInstanceActorManagerBase_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_ALevelInstanceActorManagerBase.OuterSingleton;
}
template<> LEVELINSTANCEUTILS_API UClass* StaticClass<ALevelInstanceActorManagerBase>()
{
	return ALevelInstanceActorManagerBase::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(ALevelInstanceActorManagerBase);
ALevelInstanceActorManagerBase::~ALevelInstanceActorManagerBase() {}
// End Class ALevelInstanceActorManagerBase

// Begin Registration
struct Z_CompiledInDeferFile_FID_SourceControl_CatalystDepot_WarOfBeing_Plugins_LevelInstanceUtils_Source_LevelInstanceUtils_Public_Actor_LevelInstanceActorManagerBase_h_Statics
{
	static constexpr FStructRegisterCompiledInInfo ScriptStructInfo[] = {
		{ FLevelInstanceManagerClientData::StaticStruct, Z_Construct_UScriptStruct_FLevelInstanceManagerClientData_Statics::NewStructOps, TEXT("LevelInstanceManagerClientData"), &Z_Registration_Info_UScriptStruct_LevelInstanceManagerClientData, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FLevelInstanceManagerClientData), 1269281236U) },
	};
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_ALevelInstanceActorManagerBase, ALevelInstanceActorManagerBase::StaticClass, TEXT("ALevelInstanceActorManagerBase"), &Z_Registration_Info_UClass_ALevelInstanceActorManagerBase, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ALevelInstanceActorManagerBase), 3491243831U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_SourceControl_CatalystDepot_WarOfBeing_Plugins_LevelInstanceUtils_Source_LevelInstanceUtils_Public_Actor_LevelInstanceActorManagerBase_h_3966735421(TEXT("/Script/LevelInstanceUtils"),
	Z_CompiledInDeferFile_FID_SourceControl_CatalystDepot_WarOfBeing_Plugins_LevelInstanceUtils_Source_LevelInstanceUtils_Public_Actor_LevelInstanceActorManagerBase_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_SourceControl_CatalystDepot_WarOfBeing_Plugins_LevelInstanceUtils_Source_LevelInstanceUtils_Public_Actor_LevelInstanceActorManagerBase_h_Statics::ClassInfo),
	Z_CompiledInDeferFile_FID_SourceControl_CatalystDepot_WarOfBeing_Plugins_LevelInstanceUtils_Source_LevelInstanceUtils_Public_Actor_LevelInstanceActorManagerBase_h_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_SourceControl_CatalystDepot_WarOfBeing_Plugins_LevelInstanceUtils_Source_LevelInstanceUtils_Public_Actor_LevelInstanceActorManagerBase_h_Statics::ScriptStructInfo),
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
