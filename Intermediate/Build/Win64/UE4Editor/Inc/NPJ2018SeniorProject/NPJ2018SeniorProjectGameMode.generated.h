// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "ObjectMacros.h"
#include "ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
enum class EProjectPlayState : uint8;
#ifdef NPJ2018SENIORPROJECT_NPJ2018SeniorProjectGameMode_generated_h
#error "NPJ2018SeniorProjectGameMode.generated.h already included, missing '#pragma once' in NPJ2018SeniorProjectGameMode.h"
#endif
#define NPJ2018SENIORPROJECT_NPJ2018SeniorProjectGameMode_generated_h

#define NPJ2018SeniorProject_Source_NPJ2018SeniorProject_NPJ2018SeniorProjectGameMode_h_23_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execGetCurrentState) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(EProjectPlayState*)Z_Param__Result=this->GetCurrentState(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetPowerToWin) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(float*)Z_Param__Result=this->GetPowerToWin(); \
		P_NATIVE_END; \
	}


#define NPJ2018SeniorProject_Source_NPJ2018SeniorProject_NPJ2018SeniorProjectGameMode_h_23_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execGetCurrentState) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(EProjectPlayState*)Z_Param__Result=this->GetCurrentState(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetPowerToWin) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(float*)Z_Param__Result=this->GetPowerToWin(); \
		P_NATIVE_END; \
	}


#define NPJ2018SeniorProject_Source_NPJ2018SeniorProject_NPJ2018SeniorProjectGameMode_h_23_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesANPJ2018SeniorProjectGameMode(); \
	friend NPJ2018SENIORPROJECT_API class UClass* Z_Construct_UClass_ANPJ2018SeniorProjectGameMode(); \
public: \
	DECLARE_CLASS(ANPJ2018SeniorProjectGameMode, AGameModeBase, COMPILED_IN_FLAGS(0 | CLASS_Transient), 0, TEXT("/Script/NPJ2018SeniorProject"), NPJ2018SENIORPROJECT_API) \
	DECLARE_SERIALIZER(ANPJ2018SeniorProjectGameMode) \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define NPJ2018SeniorProject_Source_NPJ2018SeniorProject_NPJ2018SeniorProjectGameMode_h_23_INCLASS \
private: \
	static void StaticRegisterNativesANPJ2018SeniorProjectGameMode(); \
	friend NPJ2018SENIORPROJECT_API class UClass* Z_Construct_UClass_ANPJ2018SeniorProjectGameMode(); \
public: \
	DECLARE_CLASS(ANPJ2018SeniorProjectGameMode, AGameModeBase, COMPILED_IN_FLAGS(0 | CLASS_Transient), 0, TEXT("/Script/NPJ2018SeniorProject"), NPJ2018SENIORPROJECT_API) \
	DECLARE_SERIALIZER(ANPJ2018SeniorProjectGameMode) \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define NPJ2018SeniorProject_Source_NPJ2018SeniorProject_NPJ2018SeniorProjectGameMode_h_23_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NPJ2018SENIORPROJECT_API ANPJ2018SeniorProjectGameMode(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ANPJ2018SeniorProjectGameMode) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NPJ2018SENIORPROJECT_API, ANPJ2018SeniorProjectGameMode); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ANPJ2018SeniorProjectGameMode); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NPJ2018SENIORPROJECT_API ANPJ2018SeniorProjectGameMode(ANPJ2018SeniorProjectGameMode&&); \
	NPJ2018SENIORPROJECT_API ANPJ2018SeniorProjectGameMode(const ANPJ2018SeniorProjectGameMode&); \
public:


#define NPJ2018SeniorProject_Source_NPJ2018SeniorProject_NPJ2018SeniorProjectGameMode_h_23_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NPJ2018SENIORPROJECT_API ANPJ2018SeniorProjectGameMode(ANPJ2018SeniorProjectGameMode&&); \
	NPJ2018SENIORPROJECT_API ANPJ2018SeniorProjectGameMode(const ANPJ2018SeniorProjectGameMode&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NPJ2018SENIORPROJECT_API, ANPJ2018SeniorProjectGameMode); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ANPJ2018SeniorProjectGameMode); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(ANPJ2018SeniorProjectGameMode)


#define NPJ2018SeniorProject_Source_NPJ2018SeniorProject_NPJ2018SeniorProjectGameMode_h_23_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__decayRate() { return STRUCT_OFFSET(ANPJ2018SeniorProjectGameMode, decayRate); } \
	FORCEINLINE static uint32 __PPO__powerToWin() { return STRUCT_OFFSET(ANPJ2018SeniorProjectGameMode, powerToWin); } \
	FORCEINLINE static uint32 __PPO__HUDWidgetClass() { return STRUCT_OFFSET(ANPJ2018SeniorProjectGameMode, HUDWidgetClass); } \
	FORCEINLINE static uint32 __PPO__CurrentWidget() { return STRUCT_OFFSET(ANPJ2018SeniorProjectGameMode, CurrentWidget); }


#define NPJ2018SeniorProject_Source_NPJ2018SeniorProject_NPJ2018SeniorProjectGameMode_h_20_PROLOG
#define NPJ2018SeniorProject_Source_NPJ2018SeniorProject_NPJ2018SeniorProjectGameMode_h_23_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	NPJ2018SeniorProject_Source_NPJ2018SeniorProject_NPJ2018SeniorProjectGameMode_h_23_PRIVATE_PROPERTY_OFFSET \
	NPJ2018SeniorProject_Source_NPJ2018SeniorProject_NPJ2018SeniorProjectGameMode_h_23_RPC_WRAPPERS \
	NPJ2018SeniorProject_Source_NPJ2018SeniorProject_NPJ2018SeniorProjectGameMode_h_23_INCLASS \
	NPJ2018SeniorProject_Source_NPJ2018SeniorProject_NPJ2018SeniorProjectGameMode_h_23_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define NPJ2018SeniorProject_Source_NPJ2018SeniorProject_NPJ2018SeniorProjectGameMode_h_23_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	NPJ2018SeniorProject_Source_NPJ2018SeniorProject_NPJ2018SeniorProjectGameMode_h_23_PRIVATE_PROPERTY_OFFSET \
	NPJ2018SeniorProject_Source_NPJ2018SeniorProject_NPJ2018SeniorProjectGameMode_h_23_RPC_WRAPPERS_NO_PURE_DECLS \
	NPJ2018SeniorProject_Source_NPJ2018SeniorProject_NPJ2018SeniorProjectGameMode_h_23_INCLASS_NO_PURE_DECLS \
	NPJ2018SeniorProject_Source_NPJ2018SeniorProject_NPJ2018SeniorProjectGameMode_h_23_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID NPJ2018SeniorProject_Source_NPJ2018SeniorProject_NPJ2018SeniorProjectGameMode_h


#define FOREACH_ENUM_EPROJECTPLAYSTATE(op) \
	op(EProjectPlayState::EPlaying) \
	op(EProjectPlayState::EGameOver) \
	op(EProjectPlayState::EWon) \
	op(EProjectPlayState::EUnknown) 
PRAGMA_ENABLE_DEPRECATION_WARNINGS
