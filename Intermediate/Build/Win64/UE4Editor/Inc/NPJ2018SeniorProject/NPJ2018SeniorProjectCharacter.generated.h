// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "ObjectMacros.h"
#include "ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef NPJ2018SENIORPROJECT_NPJ2018SeniorProjectCharacter_generated_h
#error "NPJ2018SeniorProjectCharacter.generated.h already included, missing '#pragma once' in NPJ2018SeniorProjectCharacter.h"
#endif
#define NPJ2018SENIORPROJECT_NPJ2018SeniorProjectCharacter_generated_h

#define NPJ2018SeniorProject_Source_NPJ2018SeniorProject_NPJ2018SeniorProjectCharacter_h_12_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execCameraLockOn) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->CameraLockOn(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execStopCrouch_Slide_Glide) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->StopCrouch_Slide_Glide(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execCrouch_Slide_Glide) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->Crouch_Slide_Glide(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execStopFly) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->StopFly(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execFly) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->Fly(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSprint) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->Sprint(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execCollectPickups) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->CollectPickups(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execUpdateCharacterPower) \
	{ \
		P_GET_PROPERTY(UFloatProperty,Z_Param_powerChange); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->UpdateCharacterPower(Z_Param_powerChange); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetCurrentPower) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(float*)Z_Param__Result=this->GetCurrentPower(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetInitialPower) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(float*)Z_Param__Result=this->GetInitialPower(); \
		P_NATIVE_END; \
	}


#define NPJ2018SeniorProject_Source_NPJ2018SeniorProject_NPJ2018SeniorProjectCharacter_h_12_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execCameraLockOn) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->CameraLockOn(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execStopCrouch_Slide_Glide) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->StopCrouch_Slide_Glide(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execCrouch_Slide_Glide) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->Crouch_Slide_Glide(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execStopFly) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->StopFly(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execFly) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->Fly(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSprint) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->Sprint(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execCollectPickups) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->CollectPickups(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execUpdateCharacterPower) \
	{ \
		P_GET_PROPERTY(UFloatProperty,Z_Param_powerChange); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->UpdateCharacterPower(Z_Param_powerChange); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetCurrentPower) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(float*)Z_Param__Result=this->GetCurrentPower(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetInitialPower) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(float*)Z_Param__Result=this->GetInitialPower(); \
		P_NATIVE_END; \
	}


#define NPJ2018SeniorProject_Source_NPJ2018SeniorProject_NPJ2018SeniorProjectCharacter_h_12_EVENT_PARMS
#define NPJ2018SeniorProject_Source_NPJ2018SeniorProject_NPJ2018SeniorProjectCharacter_h_12_CALLBACK_WRAPPERS
#define NPJ2018SeniorProject_Source_NPJ2018SeniorProject_NPJ2018SeniorProjectCharacter_h_12_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesANPJ2018SeniorProjectCharacter(); \
	friend NPJ2018SENIORPROJECT_API class UClass* Z_Construct_UClass_ANPJ2018SeniorProjectCharacter(); \
public: \
	DECLARE_CLASS(ANPJ2018SeniorProjectCharacter, ACharacter, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/NPJ2018SeniorProject"), NO_API) \
	DECLARE_SERIALIZER(ANPJ2018SeniorProjectCharacter) \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define NPJ2018SeniorProject_Source_NPJ2018SeniorProject_NPJ2018SeniorProjectCharacter_h_12_INCLASS \
private: \
	static void StaticRegisterNativesANPJ2018SeniorProjectCharacter(); \
	friend NPJ2018SENIORPROJECT_API class UClass* Z_Construct_UClass_ANPJ2018SeniorProjectCharacter(); \
public: \
	DECLARE_CLASS(ANPJ2018SeniorProjectCharacter, ACharacter, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/NPJ2018SeniorProject"), NO_API) \
	DECLARE_SERIALIZER(ANPJ2018SeniorProjectCharacter) \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define NPJ2018SeniorProject_Source_NPJ2018SeniorProject_NPJ2018SeniorProjectCharacter_h_12_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ANPJ2018SeniorProjectCharacter(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ANPJ2018SeniorProjectCharacter) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ANPJ2018SeniorProjectCharacter); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ANPJ2018SeniorProjectCharacter); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ANPJ2018SeniorProjectCharacter(ANPJ2018SeniorProjectCharacter&&); \
	NO_API ANPJ2018SeniorProjectCharacter(const ANPJ2018SeniorProjectCharacter&); \
public:


#define NPJ2018SeniorProject_Source_NPJ2018SeniorProject_NPJ2018SeniorProjectCharacter_h_12_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ANPJ2018SeniorProjectCharacter(ANPJ2018SeniorProjectCharacter&&); \
	NO_API ANPJ2018SeniorProjectCharacter(const ANPJ2018SeniorProjectCharacter&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ANPJ2018SeniorProjectCharacter); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ANPJ2018SeniorProjectCharacter); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(ANPJ2018SeniorProjectCharacter)


#define NPJ2018SeniorProject_Source_NPJ2018SeniorProject_NPJ2018SeniorProjectCharacter_h_12_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__CameraBoom() { return STRUCT_OFFSET(ANPJ2018SeniorProjectCharacter, CameraBoom); } \
	FORCEINLINE static uint32 __PPO__FollowCamera() { return STRUCT_OFFSET(ANPJ2018SeniorProjectCharacter, FollowCamera); } \
	FORCEINLINE static uint32 __PPO__CollectionSphere() { return STRUCT_OFFSET(ANPJ2018SeniorProjectCharacter, CollectionSphere); } \
	FORCEINLINE static uint32 __PPO__initialPower() { return STRUCT_OFFSET(ANPJ2018SeniorProjectCharacter, initialPower); } \
	FORCEINLINE static uint32 __PPO__baseSpeed() { return STRUCT_OFFSET(ANPJ2018SeniorProjectCharacter, baseSpeed); } \
	FORCEINLINE static uint32 __PPO__baseMinSpeed() { return STRUCT_OFFSET(ANPJ2018SeniorProjectCharacter, baseMinSpeed); } \
	FORCEINLINE static uint32 __PPO__sprintSpeedBonus() { return STRUCT_OFFSET(ANPJ2018SeniorProjectCharacter, sprintSpeedBonus); } \
	FORCEINLINE static uint32 __PPO__sprintBoostBonus() { return STRUCT_OFFSET(ANPJ2018SeniorProjectCharacter, sprintBoostBonus); } \
	FORCEINLINE static uint32 __PPO__sprintBoostBase() { return STRUCT_OFFSET(ANPJ2018SeniorProjectCharacter, sprintBoostBase); } \
	FORCEINLINE static uint32 __PPO__sprintBoostAcceleration() { return STRUCT_OFFSET(ANPJ2018SeniorProjectCharacter, sprintBoostAcceleration); } \
	FORCEINLINE static uint32 __PPO__sprintBoostLimit() { return STRUCT_OFFSET(ANPJ2018SeniorProjectCharacter, sprintBoostLimit); } \
	FORCEINLINE static uint32 __PPO__isSprinting() { return STRUCT_OFFSET(ANPJ2018SeniorProjectCharacter, isSprinting); } \
	FORCEINLINE static uint32 __PPO__isFlying() { return STRUCT_OFFSET(ANPJ2018SeniorProjectCharacter, isFlying); } \
	FORCEINLINE static uint32 __PPO__defaultAirControl() { return STRUCT_OFFSET(ANPJ2018SeniorProjectCharacter, defaultAirControl); } \
	FORCEINLINE static uint32 __PPO__flightSpeedBonus() { return STRUCT_OFFSET(ANPJ2018SeniorProjectCharacter, flightSpeedBonus); } \
	FORCEINLINE static uint32 __PPO__flightSpeedBonusAcceleration() { return STRUCT_OFFSET(ANPJ2018SeniorProjectCharacter, flightSpeedBonusAcceleration); } \
	FORCEINLINE static uint32 __PPO__flightSpeedLimit() { return STRUCT_OFFSET(ANPJ2018SeniorProjectCharacter, flightSpeedLimit); } \
	FORCEINLINE static uint32 __PPO__isCrouching() { return STRUCT_OFFSET(ANPJ2018SeniorProjectCharacter, isCrouching); } \
	FORCEINLINE static uint32 __PPO__isSliding() { return STRUCT_OFFSET(ANPJ2018SeniorProjectCharacter, isSliding); } \
	FORCEINLINE static uint32 __PPO__buildUpSpeed() { return STRUCT_OFFSET(ANPJ2018SeniorProjectCharacter, buildUpSpeed); } \
	FORCEINLINE static uint32 __PPO__buildUpSpeedIncrease() { return STRUCT_OFFSET(ANPJ2018SeniorProjectCharacter, buildUpSpeedIncrease); } \
	FORCEINLINE static uint32 __PPO__isGliding() { return STRUCT_OFFSET(ANPJ2018SeniorProjectCharacter, isGliding); } \
	FORCEINLINE static uint32 __PPO__isLockingOn() { return STRUCT_OFFSET(ANPJ2018SeniorProjectCharacter, isLockingOn); } \
	FORCEINLINE static uint32 __PPO__nearestEnemyLocation() { return STRUCT_OFFSET(ANPJ2018SeniorProjectCharacter, nearestEnemyLocation); } \
	FORCEINLINE static uint32 __PPO__nearestEnemy() { return STRUCT_OFFSET(ANPJ2018SeniorProjectCharacter, nearestEnemy); } \
	FORCEINLINE static uint32 __PPO__startingCameraLocation() { return STRUCT_OFFSET(ANPJ2018SeniorProjectCharacter, startingCameraLocation); } \
	FORCEINLINE static uint32 __PPO__lockOnCameraLocation() { return STRUCT_OFFSET(ANPJ2018SeniorProjectCharacter, lockOnCameraLocation); } \
	FORCEINLINE static uint32 __PPO__characterPower() { return STRUCT_OFFSET(ANPJ2018SeniorProjectCharacter, characterPower); }


#define NPJ2018SeniorProject_Source_NPJ2018SeniorProject_NPJ2018SeniorProjectCharacter_h_9_PROLOG \
	NPJ2018SeniorProject_Source_NPJ2018SeniorProject_NPJ2018SeniorProjectCharacter_h_12_EVENT_PARMS


#define NPJ2018SeniorProject_Source_NPJ2018SeniorProject_NPJ2018SeniorProjectCharacter_h_12_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	NPJ2018SeniorProject_Source_NPJ2018SeniorProject_NPJ2018SeniorProjectCharacter_h_12_PRIVATE_PROPERTY_OFFSET \
	NPJ2018SeniorProject_Source_NPJ2018SeniorProject_NPJ2018SeniorProjectCharacter_h_12_RPC_WRAPPERS \
	NPJ2018SeniorProject_Source_NPJ2018SeniorProject_NPJ2018SeniorProjectCharacter_h_12_CALLBACK_WRAPPERS \
	NPJ2018SeniorProject_Source_NPJ2018SeniorProject_NPJ2018SeniorProjectCharacter_h_12_INCLASS \
	NPJ2018SeniorProject_Source_NPJ2018SeniorProject_NPJ2018SeniorProjectCharacter_h_12_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define NPJ2018SeniorProject_Source_NPJ2018SeniorProject_NPJ2018SeniorProjectCharacter_h_12_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	NPJ2018SeniorProject_Source_NPJ2018SeniorProject_NPJ2018SeniorProjectCharacter_h_12_PRIVATE_PROPERTY_OFFSET \
	NPJ2018SeniorProject_Source_NPJ2018SeniorProject_NPJ2018SeniorProjectCharacter_h_12_RPC_WRAPPERS_NO_PURE_DECLS \
	NPJ2018SeniorProject_Source_NPJ2018SeniorProject_NPJ2018SeniorProjectCharacter_h_12_CALLBACK_WRAPPERS \
	NPJ2018SeniorProject_Source_NPJ2018SeniorProject_NPJ2018SeniorProjectCharacter_h_12_INCLASS_NO_PURE_DECLS \
	NPJ2018SeniorProject_Source_NPJ2018SeniorProject_NPJ2018SeniorProjectCharacter_h_12_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID NPJ2018SeniorProject_Source_NPJ2018SeniorProject_NPJ2018SeniorProjectCharacter_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
