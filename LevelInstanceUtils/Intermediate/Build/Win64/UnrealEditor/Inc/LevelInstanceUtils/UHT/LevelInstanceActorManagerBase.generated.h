// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Actor/LevelInstanceActorManagerBase.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class ULevelInstanceActorScriptBase;
struct FGuid;
#ifdef LEVELINSTANCEUTILS_LevelInstanceActorManagerBase_generated_h
#error "LevelInstanceActorManagerBase.generated.h already included, missing '#pragma once' in LevelInstanceActorManagerBase.h"
#endif
#define LEVELINSTANCEUTILS_LevelInstanceActorManagerBase_generated_h

#define FID_SourceControl_CatalystDepot_WarOfBeing_Plugins_LevelInstanceUtils_Source_LevelInstanceUtils_Public_Actor_LevelInstanceActorManagerBase_h_34_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FLevelInstanceManagerClientData_Statics; \
	LEVELINSTANCEUTILS_API static class UScriptStruct* StaticStruct();


template<> LEVELINSTANCEUTILS_API UScriptStruct* StaticStruct<struct FLevelInstanceManagerClientData>();

#define FID_SourceControl_CatalystDepot_WarOfBeing_Plugins_LevelInstanceUtils_Source_LevelInstanceUtils_Public_Actor_LevelInstanceActorManagerBase_h_56_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execRequestScript);


#if WITH_EDITOR
#define FID_SourceControl_CatalystDepot_WarOfBeing_Plugins_LevelInstanceUtils_Source_LevelInstanceUtils_Public_Actor_LevelInstanceActorManagerBase_h_56_RPC_WRAPPERS_NO_PURE_DECLS_EOD \
	DECLARE_FUNCTION(execApplyInEditor); \
	DECLARE_FUNCTION(execClaimGuidsFromLevel);
#else // WITH_EDITOR
#define FID_SourceControl_CatalystDepot_WarOfBeing_Plugins_LevelInstanceUtils_Source_LevelInstanceUtils_Public_Actor_LevelInstanceActorManagerBase_h_56_RPC_WRAPPERS_NO_PURE_DECLS_EOD
#endif // WITH_EDITOR


#define FID_SourceControl_CatalystDepot_WarOfBeing_Plugins_LevelInstanceUtils_Source_LevelInstanceUtils_Public_Actor_LevelInstanceActorManagerBase_h_56_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesALevelInstanceActorManagerBase(); \
	friend struct Z_Construct_UClass_ALevelInstanceActorManagerBase_Statics; \
public: \
	DECLARE_CLASS(ALevelInstanceActorManagerBase, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/LevelInstanceUtils"), NO_API) \
	DECLARE_SERIALIZER(ALevelInstanceActorManagerBase)


#define FID_SourceControl_CatalystDepot_WarOfBeing_Plugins_LevelInstanceUtils_Source_LevelInstanceUtils_Public_Actor_LevelInstanceActorManagerBase_h_56_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	ALevelInstanceActorManagerBase(ALevelInstanceActorManagerBase&&); \
	ALevelInstanceActorManagerBase(const ALevelInstanceActorManagerBase&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ALevelInstanceActorManagerBase); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ALevelInstanceActorManagerBase); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(ALevelInstanceActorManagerBase) \
	NO_API virtual ~ALevelInstanceActorManagerBase();


#define FID_SourceControl_CatalystDepot_WarOfBeing_Plugins_LevelInstanceUtils_Source_LevelInstanceUtils_Public_Actor_LevelInstanceActorManagerBase_h_53_PROLOG
#define FID_SourceControl_CatalystDepot_WarOfBeing_Plugins_LevelInstanceUtils_Source_LevelInstanceUtils_Public_Actor_LevelInstanceActorManagerBase_h_56_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_SourceControl_CatalystDepot_WarOfBeing_Plugins_LevelInstanceUtils_Source_LevelInstanceUtils_Public_Actor_LevelInstanceActorManagerBase_h_56_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_SourceControl_CatalystDepot_WarOfBeing_Plugins_LevelInstanceUtils_Source_LevelInstanceUtils_Public_Actor_LevelInstanceActorManagerBase_h_56_RPC_WRAPPERS_NO_PURE_DECLS_EOD \
	FID_SourceControl_CatalystDepot_WarOfBeing_Plugins_LevelInstanceUtils_Source_LevelInstanceUtils_Public_Actor_LevelInstanceActorManagerBase_h_56_INCLASS_NO_PURE_DECLS \
	FID_SourceControl_CatalystDepot_WarOfBeing_Plugins_LevelInstanceUtils_Source_LevelInstanceUtils_Public_Actor_LevelInstanceActorManagerBase_h_56_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> LEVELINSTANCEUTILS_API UClass* StaticClass<class ALevelInstanceActorManagerBase>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_SourceControl_CatalystDepot_WarOfBeing_Plugins_LevelInstanceUtils_Source_LevelInstanceUtils_Public_Actor_LevelInstanceActorManagerBase_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
