// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "LevelInstanceUtils/Public/LevelInstanceRuntimeSubsystem.h"
#include "LevelInstanceUtils/Public/Actor/LevelInstanceActorManagerBase.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeLevelInstanceRuntimeSubsystem() {}

// Begin Cross Module References
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FGuid();
ENGINE_API UClass* Z_Construct_UClass_UWorldSubsystem();
LEVELINSTANCEUTILS_API UClass* Z_Construct_UClass_ALevelInstanceActorManagerBase_NoRegister();
LEVELINSTANCEUTILS_API UClass* Z_Construct_UClass_ULevelInstanceActorScriptComponent_NoRegister();
LEVELINSTANCEUTILS_API UClass* Z_Construct_UClass_ULevelInstanceRuntimeSubsystem();
LEVELINSTANCEUTILS_API UClass* Z_Construct_UClass_ULevelInstanceRuntimeSubsystem_NoRegister();
LEVELINSTANCEUTILS_API UScriptStruct* Z_Construct_UScriptStruct_FLevelManagerClientRequest();
UPackage* Z_Construct_UPackage__Script_LevelInstanceUtils();
// End Cross Module References

// Begin ScriptStruct FLevelManagerClientRequest
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_LevelManagerClientRequest;
class UScriptStruct* FLevelManagerClientRequest::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_LevelManagerClientRequest.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_LevelManagerClientRequest.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FLevelManagerClientRequest, (UObject*)Z_Construct_UPackage__Script_LevelInstanceUtils(), TEXT("LevelManagerClientRequest"));
	}
	return Z_Registration_Info_UScriptStruct_LevelManagerClientRequest.OuterSingleton;
}
template<> LEVELINSTANCEUTILS_API UScriptStruct* StaticStruct<FLevelManagerClientRequest>()
{
	return FLevelManagerClientRequest::StaticStruct();
}
struct Z_Construct_UScriptStruct_FLevelManagerClientRequest_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*Stored data for instances where a script component requests data before a manager is registered. Stores a ref to \n  the component that requested it and the actor Id the data is for. \n*/" },
#endif
		{ "ModuleRelativePath", "Public/LevelInstanceRuntimeSubsystem.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Stored data for instances where a script component requests data before a manager is registered. Stores a ref to\n  the component that requested it and the actor Id the data is for." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ManagerName_MetaData[] = {
		{ "ModuleRelativePath", "Public/LevelInstanceRuntimeSubsystem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ScriptComponent_MetaData[] = {
		{ "ModuleRelativePath", "Public/LevelInstanceRuntimeSubsystem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ActorId_MetaData[] = {
		{ "ModuleRelativePath", "Public/LevelInstanceRuntimeSubsystem.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FNamePropertyParams NewProp_ManagerName;
	static const UECodeGen_Private::FWeakObjectPropertyParams NewProp_ScriptComponent;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ActorId;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FLevelManagerClientRequest>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
};
const UECodeGen_Private::FNamePropertyParams Z_Construct_UScriptStruct_FLevelManagerClientRequest_Statics::NewProp_ManagerName = { "ManagerName", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FLevelManagerClientRequest, ManagerName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ManagerName_MetaData), NewProp_ManagerName_MetaData) };
const UECodeGen_Private::FWeakObjectPropertyParams Z_Construct_UScriptStruct_FLevelManagerClientRequest_Statics::NewProp_ScriptComponent = { "ScriptComponent", nullptr, (EPropertyFlags)0x0014000000080008, UECodeGen_Private::EPropertyGenFlags::WeakObject, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FLevelManagerClientRequest, ScriptComponent), Z_Construct_UClass_ULevelInstanceActorScriptComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ScriptComponent_MetaData), NewProp_ScriptComponent_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FLevelManagerClientRequest_Statics::NewProp_ActorId = { "ActorId", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FLevelManagerClientRequest, ActorId), Z_Construct_UScriptStruct_FGuid, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ActorId_MetaData), NewProp_ActorId_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FLevelManagerClientRequest_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FLevelManagerClientRequest_Statics::NewProp_ManagerName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FLevelManagerClientRequest_Statics::NewProp_ScriptComponent,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FLevelManagerClientRequest_Statics::NewProp_ActorId,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FLevelManagerClientRequest_Statics::PropPointers) < 2048);
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FLevelManagerClientRequest_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_LevelInstanceUtils,
	nullptr,
	&NewStructOps,
	"LevelManagerClientRequest",
	Z_Construct_UScriptStruct_FLevelManagerClientRequest_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FLevelManagerClientRequest_Statics::PropPointers),
	sizeof(FLevelManagerClientRequest),
	alignof(FLevelManagerClientRequest),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000005),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FLevelManagerClientRequest_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FLevelManagerClientRequest_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FLevelManagerClientRequest()
{
	if (!Z_Registration_Info_UScriptStruct_LevelManagerClientRequest.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_LevelManagerClientRequest.InnerSingleton, Z_Construct_UScriptStruct_FLevelManagerClientRequest_Statics::StructParams);
	}
	return Z_Registration_Info_UScriptStruct_LevelManagerClientRequest.InnerSingleton;
}
// End ScriptStruct FLevelManagerClientRequest

// Begin Class ULevelInstanceRuntimeSubsystem Function GetManagerByName
struct Z_Construct_UFunction_ULevelInstanceRuntimeSubsystem_GetManagerByName_Statics
{
	struct LevelInstanceRuntimeSubsystem_eventGetManagerByName_Parms
	{
		FName ManagerName;
		ALevelInstanceActorManagerBase* Manager;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "LevelInstanceSubsystem" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Get the manager class by its registered name.\n" },
#endif
		{ "ModuleRelativePath", "Public/LevelInstanceRuntimeSubsystem.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Get the manager class by its registered name." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ManagerName_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FNamePropertyParams NewProp_ManagerName;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Manager;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FNamePropertyParams Z_Construct_UFunction_ULevelInstanceRuntimeSubsystem_GetManagerByName_Statics::NewProp_ManagerName = { "ManagerName", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(LevelInstanceRuntimeSubsystem_eventGetManagerByName_Parms, ManagerName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ManagerName_MetaData), NewProp_ManagerName_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_ULevelInstanceRuntimeSubsystem_GetManagerByName_Statics::NewProp_Manager = { "Manager", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(LevelInstanceRuntimeSubsystem_eventGetManagerByName_Parms, Manager), Z_Construct_UClass_ALevelInstanceActorManagerBase_NoRegister, METADATA_PARAMS(0, nullptr) };
void Z_Construct_UFunction_ULevelInstanceRuntimeSubsystem_GetManagerByName_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((LevelInstanceRuntimeSubsystem_eventGetManagerByName_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_ULevelInstanceRuntimeSubsystem_GetManagerByName_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(LevelInstanceRuntimeSubsystem_eventGetManagerByName_Parms), &Z_Construct_UFunction_ULevelInstanceRuntimeSubsystem_GetManagerByName_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ULevelInstanceRuntimeSubsystem_GetManagerByName_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULevelInstanceRuntimeSubsystem_GetManagerByName_Statics::NewProp_ManagerName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULevelInstanceRuntimeSubsystem_GetManagerByName_Statics::NewProp_Manager,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULevelInstanceRuntimeSubsystem_GetManagerByName_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ULevelInstanceRuntimeSubsystem_GetManagerByName_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ULevelInstanceRuntimeSubsystem_GetManagerByName_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ULevelInstanceRuntimeSubsystem, nullptr, "GetManagerByName", nullptr, nullptr, Z_Construct_UFunction_ULevelInstanceRuntimeSubsystem_GetManagerByName_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ULevelInstanceRuntimeSubsystem_GetManagerByName_Statics::PropPointers), sizeof(Z_Construct_UFunction_ULevelInstanceRuntimeSubsystem_GetManagerByName_Statics::LevelInstanceRuntimeSubsystem_eventGetManagerByName_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04420401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ULevelInstanceRuntimeSubsystem_GetManagerByName_Statics::Function_MetaDataParams), Z_Construct_UFunction_ULevelInstanceRuntimeSubsystem_GetManagerByName_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_ULevelInstanceRuntimeSubsystem_GetManagerByName_Statics::LevelInstanceRuntimeSubsystem_eventGetManagerByName_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ULevelInstanceRuntimeSubsystem_GetManagerByName()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ULevelInstanceRuntimeSubsystem_GetManagerByName_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ULevelInstanceRuntimeSubsystem::execGetManagerByName)
{
	P_GET_PROPERTY(FNameProperty,Z_Param_ManagerName);
	P_GET_OBJECT_REF(ALevelInstanceActorManagerBase,Z_Param_Out_Manager);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->GetManagerByName(Z_Param_ManagerName,P_ARG_GC_BARRIER(Z_Param_Out_Manager));
	P_NATIVE_END;
}
// End Class ULevelInstanceRuntimeSubsystem Function GetManagerByName

// Begin Class ULevelInstanceRuntimeSubsystem Function RegisterManagerClass
struct Z_Construct_UFunction_ULevelInstanceRuntimeSubsystem_RegisterManagerClass_Statics
{
	struct LevelInstanceRuntimeSubsystem_eventRegisterManagerClass_Parms
	{
		FName Name;
		ALevelInstanceActorManagerBase* Actor;
		bool bOverrideExisting;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "LevelInstanceSubsystem" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Register an valid actor with the current world, under the specified name. bOverrideExisting will replace any managers with the same name.\n" },
#endif
		{ "CPP_Default_bOverrideExisting", "true" },
		{ "ModuleRelativePath", "Public/LevelInstanceRuntimeSubsystem.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Register an valid actor with the current world, under the specified name. bOverrideExisting will replace any managers with the same name." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Name_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bOverrideExisting_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FNamePropertyParams NewProp_Name;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Actor;
	static void NewProp_bOverrideExisting_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bOverrideExisting;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FNamePropertyParams Z_Construct_UFunction_ULevelInstanceRuntimeSubsystem_RegisterManagerClass_Statics::NewProp_Name = { "Name", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(LevelInstanceRuntimeSubsystem_eventRegisterManagerClass_Parms, Name), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Name_MetaData), NewProp_Name_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_ULevelInstanceRuntimeSubsystem_RegisterManagerClass_Statics::NewProp_Actor = { "Actor", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(LevelInstanceRuntimeSubsystem_eventRegisterManagerClass_Parms, Actor), Z_Construct_UClass_ALevelInstanceActorManagerBase_NoRegister, METADATA_PARAMS(0, nullptr) };
void Z_Construct_UFunction_ULevelInstanceRuntimeSubsystem_RegisterManagerClass_Statics::NewProp_bOverrideExisting_SetBit(void* Obj)
{
	((LevelInstanceRuntimeSubsystem_eventRegisterManagerClass_Parms*)Obj)->bOverrideExisting = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_ULevelInstanceRuntimeSubsystem_RegisterManagerClass_Statics::NewProp_bOverrideExisting = { "bOverrideExisting", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(LevelInstanceRuntimeSubsystem_eventRegisterManagerClass_Parms), &Z_Construct_UFunction_ULevelInstanceRuntimeSubsystem_RegisterManagerClass_Statics::NewProp_bOverrideExisting_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bOverrideExisting_MetaData), NewProp_bOverrideExisting_MetaData) };
void Z_Construct_UFunction_ULevelInstanceRuntimeSubsystem_RegisterManagerClass_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((LevelInstanceRuntimeSubsystem_eventRegisterManagerClass_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_ULevelInstanceRuntimeSubsystem_RegisterManagerClass_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(LevelInstanceRuntimeSubsystem_eventRegisterManagerClass_Parms), &Z_Construct_UFunction_ULevelInstanceRuntimeSubsystem_RegisterManagerClass_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ULevelInstanceRuntimeSubsystem_RegisterManagerClass_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULevelInstanceRuntimeSubsystem_RegisterManagerClass_Statics::NewProp_Name,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULevelInstanceRuntimeSubsystem_RegisterManagerClass_Statics::NewProp_Actor,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULevelInstanceRuntimeSubsystem_RegisterManagerClass_Statics::NewProp_bOverrideExisting,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULevelInstanceRuntimeSubsystem_RegisterManagerClass_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ULevelInstanceRuntimeSubsystem_RegisterManagerClass_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ULevelInstanceRuntimeSubsystem_RegisterManagerClass_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ULevelInstanceRuntimeSubsystem, nullptr, "RegisterManagerClass", nullptr, nullptr, Z_Construct_UFunction_ULevelInstanceRuntimeSubsystem_RegisterManagerClass_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ULevelInstanceRuntimeSubsystem_RegisterManagerClass_Statics::PropPointers), sizeof(Z_Construct_UFunction_ULevelInstanceRuntimeSubsystem_RegisterManagerClass_Statics::LevelInstanceRuntimeSubsystem_eventRegisterManagerClass_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ULevelInstanceRuntimeSubsystem_RegisterManagerClass_Statics::Function_MetaDataParams), Z_Construct_UFunction_ULevelInstanceRuntimeSubsystem_RegisterManagerClass_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_ULevelInstanceRuntimeSubsystem_RegisterManagerClass_Statics::LevelInstanceRuntimeSubsystem_eventRegisterManagerClass_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ULevelInstanceRuntimeSubsystem_RegisterManagerClass()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ULevelInstanceRuntimeSubsystem_RegisterManagerClass_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ULevelInstanceRuntimeSubsystem::execRegisterManagerClass)
{
	P_GET_PROPERTY(FNameProperty,Z_Param_Name);
	P_GET_OBJECT(ALevelInstanceActorManagerBase,Z_Param_Actor);
	P_GET_UBOOL(Z_Param_bOverrideExisting);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->RegisterManagerClass(Z_Param_Name,Z_Param_Actor,Z_Param_bOverrideExisting);
	P_NATIVE_END;
}
// End Class ULevelInstanceRuntimeSubsystem Function RegisterManagerClass

// Begin Class ULevelInstanceRuntimeSubsystem Function RequestScriptFromManager
struct Z_Construct_UFunction_ULevelInstanceRuntimeSubsystem_RequestScriptFromManager_Statics
{
	struct LevelInstanceRuntimeSubsystem_eventRequestScriptFromManager_Parms
	{
		FLevelManagerClientRequest RequestData;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "LevelInstanceSubsystem" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*Handles getting script data for a client component as soon as the manager is available. if the manager is available, it will\n\x09""call back immediately, if not it will queue the request until the manager has registered. */" },
#endif
		{ "ModuleRelativePath", "Public/LevelInstanceRuntimeSubsystem.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Handles getting script data for a client component as soon as the manager is available. if the manager is available, it will\n       call back immediately, if not it will queue the request until the manager has registered." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RequestData_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_RequestData;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_ULevelInstanceRuntimeSubsystem_RequestScriptFromManager_Statics::NewProp_RequestData = { "RequestData", nullptr, (EPropertyFlags)0x0010008000000082, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(LevelInstanceRuntimeSubsystem_eventRequestScriptFromManager_Parms, RequestData), Z_Construct_UScriptStruct_FLevelManagerClientRequest, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RequestData_MetaData), NewProp_RequestData_MetaData) }; // 2635840770
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ULevelInstanceRuntimeSubsystem_RequestScriptFromManager_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULevelInstanceRuntimeSubsystem_RequestScriptFromManager_Statics::NewProp_RequestData,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ULevelInstanceRuntimeSubsystem_RequestScriptFromManager_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ULevelInstanceRuntimeSubsystem_RequestScriptFromManager_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ULevelInstanceRuntimeSubsystem, nullptr, "RequestScriptFromManager", nullptr, nullptr, Z_Construct_UFunction_ULevelInstanceRuntimeSubsystem_RequestScriptFromManager_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ULevelInstanceRuntimeSubsystem_RequestScriptFromManager_Statics::PropPointers), sizeof(Z_Construct_UFunction_ULevelInstanceRuntimeSubsystem_RequestScriptFromManager_Statics::LevelInstanceRuntimeSubsystem_eventRequestScriptFromManager_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ULevelInstanceRuntimeSubsystem_RequestScriptFromManager_Statics::Function_MetaDataParams), Z_Construct_UFunction_ULevelInstanceRuntimeSubsystem_RequestScriptFromManager_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_ULevelInstanceRuntimeSubsystem_RequestScriptFromManager_Statics::LevelInstanceRuntimeSubsystem_eventRequestScriptFromManager_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ULevelInstanceRuntimeSubsystem_RequestScriptFromManager()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ULevelInstanceRuntimeSubsystem_RequestScriptFromManager_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ULevelInstanceRuntimeSubsystem::execRequestScriptFromManager)
{
	P_GET_STRUCT(FLevelManagerClientRequest,Z_Param_RequestData);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->RequestScriptFromManager(Z_Param_RequestData);
	P_NATIVE_END;
}
// End Class ULevelInstanceRuntimeSubsystem Function RequestScriptFromManager

// Begin Class ULevelInstanceRuntimeSubsystem
void ULevelInstanceRuntimeSubsystem::StaticRegisterNativesULevelInstanceRuntimeSubsystem()
{
	UClass* Class = ULevelInstanceRuntimeSubsystem::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "GetManagerByName", &ULevelInstanceRuntimeSubsystem::execGetManagerByName },
		{ "RegisterManagerClass", &ULevelInstanceRuntimeSubsystem::execRegisterManagerClass },
		{ "RequestScriptFromManager", &ULevelInstanceRuntimeSubsystem::execRequestScriptFromManager },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ULevelInstanceRuntimeSubsystem);
UClass* Z_Construct_UClass_ULevelInstanceRuntimeSubsystem_NoRegister()
{
	return ULevelInstanceRuntimeSubsystem::StaticClass();
}
struct Z_Construct_UClass_ULevelInstanceRuntimeSubsystem_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "IncludePath", "LevelInstanceRuntimeSubsystem.h" },
		{ "ModuleRelativePath", "Public/LevelInstanceRuntimeSubsystem.h" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_ULevelInstanceRuntimeSubsystem_GetManagerByName, "GetManagerByName" }, // 2686423397
		{ &Z_Construct_UFunction_ULevelInstanceRuntimeSubsystem_RegisterManagerClass, "RegisterManagerClass" }, // 3107902962
		{ &Z_Construct_UFunction_ULevelInstanceRuntimeSubsystem_RequestScriptFromManager, "RequestScriptFromManager" }, // 213850957
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ULevelInstanceRuntimeSubsystem>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_ULevelInstanceRuntimeSubsystem_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UWorldSubsystem,
	(UObject* (*)())Z_Construct_UPackage__Script_LevelInstanceUtils,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ULevelInstanceRuntimeSubsystem_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_ULevelInstanceRuntimeSubsystem_Statics::ClassParams = {
	&ULevelInstanceRuntimeSubsystem::StaticClass,
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
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ULevelInstanceRuntimeSubsystem_Statics::Class_MetaDataParams), Z_Construct_UClass_ULevelInstanceRuntimeSubsystem_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_ULevelInstanceRuntimeSubsystem()
{
	if (!Z_Registration_Info_UClass_ULevelInstanceRuntimeSubsystem.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ULevelInstanceRuntimeSubsystem.OuterSingleton, Z_Construct_UClass_ULevelInstanceRuntimeSubsystem_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_ULevelInstanceRuntimeSubsystem.OuterSingleton;
}
template<> LEVELINSTANCEUTILS_API UClass* StaticClass<ULevelInstanceRuntimeSubsystem>()
{
	return ULevelInstanceRuntimeSubsystem::StaticClass();
}
ULevelInstanceRuntimeSubsystem::ULevelInstanceRuntimeSubsystem() {}
DEFINE_VTABLE_PTR_HELPER_CTOR(ULevelInstanceRuntimeSubsystem);
ULevelInstanceRuntimeSubsystem::~ULevelInstanceRuntimeSubsystem() {}
// End Class ULevelInstanceRuntimeSubsystem

// Begin Registration
struct Z_CompiledInDeferFile_FID_SourceControl_CatalystDepot_WarOfBeing_Plugins_LevelInstanceUtils_Source_LevelInstanceUtils_Public_LevelInstanceRuntimeSubsystem_h_Statics
{
	static constexpr FStructRegisterCompiledInInfo ScriptStructInfo[] = {
		{ FLevelManagerClientRequest::StaticStruct, Z_Construct_UScriptStruct_FLevelManagerClientRequest_Statics::NewStructOps, TEXT("LevelManagerClientRequest"), &Z_Registration_Info_UScriptStruct_LevelManagerClientRequest, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FLevelManagerClientRequest), 2635840770U) },
	};
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_ULevelInstanceRuntimeSubsystem, ULevelInstanceRuntimeSubsystem::StaticClass, TEXT("ULevelInstanceRuntimeSubsystem"), &Z_Registration_Info_UClass_ULevelInstanceRuntimeSubsystem, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ULevelInstanceRuntimeSubsystem), 3697823668U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_SourceControl_CatalystDepot_WarOfBeing_Plugins_LevelInstanceUtils_Source_LevelInstanceUtils_Public_LevelInstanceRuntimeSubsystem_h_3357017554(TEXT("/Script/LevelInstanceUtils"),
	Z_CompiledInDeferFile_FID_SourceControl_CatalystDepot_WarOfBeing_Plugins_LevelInstanceUtils_Source_LevelInstanceUtils_Public_LevelInstanceRuntimeSubsystem_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_SourceControl_CatalystDepot_WarOfBeing_Plugins_LevelInstanceUtils_Source_LevelInstanceUtils_Public_LevelInstanceRuntimeSubsystem_h_Statics::ClassInfo),
	Z_CompiledInDeferFile_FID_SourceControl_CatalystDepot_WarOfBeing_Plugins_LevelInstanceUtils_Source_LevelInstanceUtils_Public_LevelInstanceRuntimeSubsystem_h_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_SourceControl_CatalystDepot_WarOfBeing_Plugins_LevelInstanceUtils_Source_LevelInstanceUtils_Public_LevelInstanceRuntimeSubsystem_h_Statics::ScriptStructInfo),
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
