// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "ObjectMacros.h"
#include "ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef NPJ2018SENIORPROJECT_Pickup_generated_h
#error "Pickup.generated.h already included, missing '#pragma once' in Pickup.h"
#endif
#define NPJ2018SENIORPROJECT_Pickup_generated_h

#define NPJ2018SeniorProject_Source_NPJ2018SeniorProject_C__Classes_Pickup_h_12_RPC_WRAPPERS \
	virtual void Collect_Implementation(); \
 \
	DECLARE_FUNCTION(execCollect) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->Collect_Implementation(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetActive) \
	{ \
		P_GET_UBOOL(Z_Param_newPickupState); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->SetActive(Z_Param_newPickupState); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetActive) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=this->GetActive(); \
		P_NATIVE_END; \
	}


#define NPJ2018SeniorProject_Source_NPJ2018SeniorProject_C__Classes_Pickup_h_12_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execCollect) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->Collect_Implementation(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetActive) \
	{ \
		P_GET_UBOOL(Z_Param_newPickupState); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->SetActive(Z_Param_newPickupState); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetActive) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=this->GetActive(); \
		P_NATIVE_END; \
	}


#define NPJ2018SeniorProject_Source_NPJ2018SeniorProject_C__Classes_Pickup_h_12_EVENT_PARMS
#define NPJ2018SeniorProject_Source_NPJ2018SeniorProject_C__Classes_Pickup_h_12_CALLBACK_WRAPPERS
#define NPJ2018SeniorProject_Source_NPJ2018SeniorProject_C__Classes_Pickup_h_12_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAPickup(); \
	friend NPJ2018SENIORPROJECT_API class UClass* Z_Construct_UClass_APickup(); \
public: \
	DECLARE_CLASS(APickup, AActor, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/NPJ2018SeniorProject"), NO_API) \
	DECLARE_SERIALIZER(APickup) \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define NPJ2018SeniorProject_Source_NPJ2018SeniorProject_C__Classes_Pickup_h_12_INCLASS \
private: \
	static void StaticRegisterNativesAPickup(); \
	friend NPJ2018SENIORPROJECT_API class UClass* Z_Construct_UClass_APickup(); \
public: \
	DECLARE_CLASS(APickup, AActor, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/NPJ2018SeniorProject"), NO_API) \
	DECLARE_SERIALIZER(APickup) \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define NPJ2018SeniorProject_Source_NPJ2018SeniorProject_C__Classes_Pickup_h_12_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API APickup(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(APickup) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, APickup); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(APickup); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API APickup(APickup&&); \
	NO_API APickup(const APickup&); \
public:


#define NPJ2018SeniorProject_Source_NPJ2018SeniorProject_C__Classes_Pickup_h_12_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API APickup(APickup&&); \
	NO_API APickup(const APickup&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, APickup); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(APickup); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(APickup)


#define NPJ2018SeniorProject_Source_NPJ2018SeniorProject_C__Classes_Pickup_h_12_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__PickupMesh() { return STRUCT_OFFSET(APickup, PickupMesh); }


#define NPJ2018SeniorProject_Source_NPJ2018SeniorProject_C__Classes_Pickup_h_9_PROLOG \
	NPJ2018SeniorProject_Source_NPJ2018SeniorProject_C__Classes_Pickup_h_12_EVENT_PARMS


#define NPJ2018SeniorProject_Source_NPJ2018SeniorProject_C__Classes_Pickup_h_12_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	NPJ2018SeniorProject_Source_NPJ2018SeniorProject_C__Classes_Pickup_h_12_PRIVATE_PROPERTY_OFFSET \
	NPJ2018SeniorProject_Source_NPJ2018SeniorProject_C__Classes_Pickup_h_12_RPC_WRAPPERS \
	NPJ2018SeniorProject_Source_NPJ2018SeniorProject_C__Classes_Pickup_h_12_CALLBACK_WRAPPERS \
	NPJ2018SeniorProject_Source_NPJ2018SeniorProject_C__Classes_Pickup_h_12_INCLASS \
	NPJ2018SeniorProject_Source_NPJ2018SeniorProject_C__Classes_Pickup_h_12_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define NPJ2018SeniorProject_Source_NPJ2018SeniorProject_C__Classes_Pickup_h_12_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	NPJ2018SeniorProject_Source_NPJ2018SeniorProject_C__Classes_Pickup_h_12_PRIVATE_PROPERTY_OFFSET \
	NPJ2018SeniorProject_Source_NPJ2018SeniorProject_C__Classes_Pickup_h_12_RPC_WRAPPERS_NO_PURE_DECLS \
	NPJ2018SeniorProject_Source_NPJ2018SeniorProject_C__Classes_Pickup_h_12_CALLBACK_WRAPPERS \
	NPJ2018SeniorProject_Source_NPJ2018SeniorProject_C__Classes_Pickup_h_12_INCLASS_NO_PURE_DECLS \
	NPJ2018SeniorProject_Source_NPJ2018SeniorProject_C__Classes_Pickup_h_12_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID NPJ2018SeniorProject_Source_NPJ2018SeniorProject_C__Classes_Pickup_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
