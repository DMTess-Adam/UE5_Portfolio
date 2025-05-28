// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "LevelInstanceRuntimeSubsystem.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class ALevelInstanceActorManagerBase;
struct FLevelManagerClientRequest;
#ifdef LEVELINSTANCEUTILS_LevelInstanceRuntimeSubsystem_generated_h
#error "LevelInstanceRuntimeSubsystem.generated.h already included, missing '#pragma once' in LevelInstanceRuntimeSubsystem.h"
#endif
#define LEVELINSTANCEUTILS_LevelInstanceRuntimeSubsystem_generated_h

#define FID_SourceControl_CatalystDepot_WarOfBeing_Plugins_LevelInstanceUtils_Source_LevelInstanceUtils_Public_LevelInstanceRuntimeSubsystem_h_34_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FLevelManagerClientRequest_Statics; \
	LEVELINSTANCEUTILS_API static class UScriptStruct* StaticStruct();


template<> LEVELINSTANCEUTILS_API UScriptStruct* StaticStruct<struct FLevelManagerClientRequest>();

#define FID_SourceControl_CatalystDepot_WarOfBeing_Plugins_LevelInstanceUtils_Source_LevelInstanceUtils_Public_LevelInstanceRuntimeSubsystem_h_60_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execRequestScriptFromManager); \
	DECLARE_FUNCTION(execGetManagerByName); \
	DECLARE_FUNCTION(execRegisterManagerClass);


#define FID_SourceControl_CatalystDepot_WarOfBeing_Plugins_LevelInstanceUtils_Source_LevelInstanceUtils_Public_LevelInstanceRuntimeSubsystem_h_60_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesULevelInstanceRuntimeSubsystem(); \
	friend struct Z_Construct_UClass_ULevelInstanceRuntimeSubsystem_Statics; \
public: \
	DECLARE_CLASS(ULevelInstanceRuntimeSubsystem, UWorldSubsystem, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/LevelInstanceUtils"), NO_API) \
	DECLARE_SERIALIZER(ULevelInstanceRuntimeSubsystem)


#define FID_SourceControl_CatalystDepot_WarOfBeing_Plugins_LevelInstanceUtils_Source_LevelInstanceUtils_Public_LevelInstanceRuntimeSubsystem_h_60_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ULevelInstanceRuntimeSubsystem(); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	ULevelInstanceRuntimeSubsystem(ULevelInstanceRuntimeSubsystem&&); \
	ULevelInstanceRuntimeSubsystem(const ULevelInstanceRuntimeSubsystem&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ULevelInstanceRuntimeSubsystem); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ULevelInstanceRuntimeSubsystem); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(ULevelInstanceRuntimeSubsystem) \
	NO_API virtual ~ULevelInstanceRuntimeSubsystem();


#define FID_SourceControl_CatalystDepot_WarOfBeing_Plugins_LevelInstanceUtils_Source_LevelInstanceUtils_Public_LevelInstanceRuntimeSubsystem_h_57_PROLOG
#define FID_SourceControl_CatalystDepot_WarOfBeing_Plugins_LevelInstanceUtils_Source_LevelInstanceUtils_Public_LevelInstanceRuntimeSubsystem_h_60_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_SourceControl_CatalystDepot_WarOfBeing_Plugins_LevelInstanceUtils_Source_LevelInstanceUtils_Public_LevelInstanceRuntimeSubsystem_h_60_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_SourceControl_CatalystDepot_WarOfBeing_Plugins_LevelInstanceUtils_Source_LevelInstanceUtils_Public_LevelInstanceRuntimeSubsystem_h_60_INCLASS_NO_PURE_DECLS \
	FID_SourceControl_CatalystDepot_WarOfBeing_Plugins_LevelInstanceUtils_Source_LevelInstanceUtils_Public_LevelInstanceRuntimeSubsystem_h_60_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> LEVELINSTANCEUTILS_API UClass* StaticClass<class ULevelInstanceRuntimeSubsystem>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_SourceControl_CatalystDepot_WarOfBeing_Plugins_LevelInstanceUtils_Source_LevelInstanceUtils_Public_LevelInstanceRuntimeSubsystem_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
