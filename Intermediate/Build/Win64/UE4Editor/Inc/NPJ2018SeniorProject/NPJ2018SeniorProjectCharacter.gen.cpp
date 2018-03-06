// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "GeneratedCppIncludes.h"
#include "NPJ2018SeniorProjectCharacter.h"
PRAGMA_DISABLE_OPTIMIZATION
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeNPJ2018SeniorProjectCharacter() {}
// Cross Module References
	NPJ2018SENIORPROJECT_API UFunction* Z_Construct_UFunction_ANPJ2018SeniorProjectCharacter_CollectPickups();
	NPJ2018SENIORPROJECT_API UClass* Z_Construct_UClass_ANPJ2018SeniorProjectCharacter();
	NPJ2018SENIORPROJECT_API UFunction* Z_Construct_UFunction_ANPJ2018SeniorProjectCharacter_GetCurrentPower();
	NPJ2018SENIORPROJECT_API UFunction* Z_Construct_UFunction_ANPJ2018SeniorProjectCharacter_GetInitialPower();
	NPJ2018SENIORPROJECT_API UFunction* Z_Construct_UFunction_ANPJ2018SeniorProjectCharacter_PowerChangeEffect();
	NPJ2018SENIORPROJECT_API UFunction* Z_Construct_UFunction_ANPJ2018SeniorProjectCharacter_UpdateCharacterPower();
	NPJ2018SENIORPROJECT_API UClass* Z_Construct_UClass_ANPJ2018SeniorProjectCharacter_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_ACharacter();
	UPackage* Z_Construct_UPackage__Script_NPJ2018SeniorProject();
	ENGINE_API UClass* Z_Construct_UClass_USphereComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UCameraComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_USpringArmComponent_NoRegister();
// End Cross Module References
	static FName NAME_ANPJ2018SeniorProjectCharacter_PowerChangeEffect = FName(TEXT("PowerChangeEffect"));
	void ANPJ2018SeniorProjectCharacter::PowerChangeEffect()
	{
		ProcessEvent(FindFunctionChecked(NAME_ANPJ2018SeniorProjectCharacter_PowerChangeEffect),NULL);
	}
	void ANPJ2018SeniorProjectCharacter::StaticRegisterNativesANPJ2018SeniorProjectCharacter()
	{
		UClass* Class = ANPJ2018SeniorProjectCharacter::StaticClass();
		static const TNameNativePtrPair<ANSICHAR> AnsiFuncs[] = {
			{ "CollectPickups", (Native)&ANPJ2018SeniorProjectCharacter::execCollectPickups },
			{ "GetCurrentPower", (Native)&ANPJ2018SeniorProjectCharacter::execGetCurrentPower },
			{ "GetInitialPower", (Native)&ANPJ2018SeniorProjectCharacter::execGetInitialPower },
			{ "UpdateCharacterPower", (Native)&ANPJ2018SeniorProjectCharacter::execUpdateCharacterPower },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, AnsiFuncs, ARRAY_COUNT(AnsiFuncs));
	}
	UFunction* Z_Construct_UFunction_ANPJ2018SeniorProjectCharacter_CollectPickups()
	{
		UObject* Outer = Z_Construct_UClass_ANPJ2018SeniorProjectCharacter();
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			ReturnFunction = new(EC_InternalUseOnlyConstructor, Outer, TEXT("CollectPickups"), RF_Public|RF_Transient|RF_MarkAsNative) UFunction(FObjectInitializer(), nullptr, (EFunctionFlags)0x04080401, 65535);
			ReturnFunction->Bind();
			ReturnFunction->StaticLink();
#if WITH_METADATA
			UMetaData* MetaData = ReturnFunction->GetOutermost()->GetMetaData();
			MetaData->SetValue(ReturnFunction, TEXT("Category"), TEXT("Pickups"));
			MetaData->SetValue(ReturnFunction, TEXT("ModuleRelativePath"), TEXT("NPJ2018SeniorProjectCharacter.h"));
			MetaData->SetValue(ReturnFunction, TEXT("ToolTip"), TEXT("Called when we press a key to collect any pickups inside the CollectionSphere"));
#endif
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_ANPJ2018SeniorProjectCharacter_GetCurrentPower()
	{
		struct NPJ2018SeniorProjectCharacter_eventGetCurrentPower_Parms
		{
			float ReturnValue;
		};
		UObject* Outer = Z_Construct_UClass_ANPJ2018SeniorProjectCharacter();
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			ReturnFunction = new(EC_InternalUseOnlyConstructor, Outer, TEXT("GetCurrentPower"), RF_Public|RF_Transient|RF_MarkAsNative) UFunction(FObjectInitializer(), nullptr, (EFunctionFlags)0x14020401, 65535, sizeof(NPJ2018SeniorProjectCharacter_eventGetCurrentPower_Parms));
			UProperty* NewProp_ReturnValue = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("ReturnValue"), RF_Public|RF_Transient|RF_MarkAsNative) UFloatProperty(CPP_PROPERTY_BASE(ReturnValue, NPJ2018SeniorProjectCharacter_eventGetCurrentPower_Parms), 0x0010000000000580);
			ReturnFunction->Bind();
			ReturnFunction->StaticLink();
#if WITH_METADATA
			UMetaData* MetaData = ReturnFunction->GetOutermost()->GetMetaData();
			MetaData->SetValue(ReturnFunction, TEXT("Category"), TEXT("Power"));
			MetaData->SetValue(ReturnFunction, TEXT("ModuleRelativePath"), TEXT("NPJ2018SeniorProjectCharacter.h"));
#endif
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_ANPJ2018SeniorProjectCharacter_GetInitialPower()
	{
		struct NPJ2018SeniorProjectCharacter_eventGetInitialPower_Parms
		{
			float ReturnValue;
		};
		UObject* Outer = Z_Construct_UClass_ANPJ2018SeniorProjectCharacter();
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			ReturnFunction = new(EC_InternalUseOnlyConstructor, Outer, TEXT("GetInitialPower"), RF_Public|RF_Transient|RF_MarkAsNative) UFunction(FObjectInitializer(), nullptr, (EFunctionFlags)0x14020401, 65535, sizeof(NPJ2018SeniorProjectCharacter_eventGetInitialPower_Parms));
			UProperty* NewProp_ReturnValue = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("ReturnValue"), RF_Public|RF_Transient|RF_MarkAsNative) UFloatProperty(CPP_PROPERTY_BASE(ReturnValue, NPJ2018SeniorProjectCharacter_eventGetInitialPower_Parms), 0x0010000000000580);
			ReturnFunction->Bind();
			ReturnFunction->StaticLink();
#if WITH_METADATA
			UMetaData* MetaData = ReturnFunction->GetOutermost()->GetMetaData();
			MetaData->SetValue(ReturnFunction, TEXT("Category"), TEXT("Power"));
			MetaData->SetValue(ReturnFunction, TEXT("ModuleRelativePath"), TEXT("NPJ2018SeniorProjectCharacter.h"));
			MetaData->SetValue(ReturnFunction, TEXT("ToolTip"), TEXT("Accessor for initial power"));
#endif
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_ANPJ2018SeniorProjectCharacter_PowerChangeEffect()
	{
		UObject* Outer = Z_Construct_UClass_ANPJ2018SeniorProjectCharacter();
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			ReturnFunction = new(EC_InternalUseOnlyConstructor, Outer, TEXT("PowerChangeEffect"), RF_Public|RF_Transient|RF_MarkAsNative) UFunction(FObjectInitializer(), nullptr, (EFunctionFlags)0x08080800, 65535);
			ReturnFunction->Bind();
			ReturnFunction->StaticLink();
#if WITH_METADATA
			UMetaData* MetaData = ReturnFunction->GetOutermost()->GetMetaData();
			MetaData->SetValue(ReturnFunction, TEXT("Category"), TEXT("Power"));
			MetaData->SetValue(ReturnFunction, TEXT("ModuleRelativePath"), TEXT("NPJ2018SeniorProjectCharacter.h"));
#endif
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_ANPJ2018SeniorProjectCharacter_UpdateCharacterPower()
	{
		struct NPJ2018SeniorProjectCharacter_eventUpdateCharacterPower_Parms
		{
			float powerChange;
		};
		UObject* Outer = Z_Construct_UClass_ANPJ2018SeniorProjectCharacter();
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			ReturnFunction = new(EC_InternalUseOnlyConstructor, Outer, TEXT("UpdateCharacterPower"), RF_Public|RF_Transient|RF_MarkAsNative) UFunction(FObjectInitializer(), nullptr, (EFunctionFlags)0x04020401, 65535, sizeof(NPJ2018SeniorProjectCharacter_eventUpdateCharacterPower_Parms));
			UProperty* NewProp_powerChange = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("powerChange"), RF_Public|RF_Transient|RF_MarkAsNative) UFloatProperty(CPP_PROPERTY_BASE(powerChange, NPJ2018SeniorProjectCharacter_eventUpdateCharacterPower_Parms), 0x0010000000000080);
			ReturnFunction->Bind();
			ReturnFunction->StaticLink();
#if WITH_METADATA
			UMetaData* MetaData = ReturnFunction->GetOutermost()->GetMetaData();
			MetaData->SetValue(ReturnFunction, TEXT("Category"), TEXT("Power"));
			MetaData->SetValue(ReturnFunction, TEXT("ModuleRelativePath"), TEXT("NPJ2018SeniorProjectCharacter.h"));
			MetaData->SetValue(ReturnFunction, TEXT("ToolTip"), TEXT("Function to update the character's power\n@param powerChange This is the amount to change the power by, positive or negative"));
#endif
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_ANPJ2018SeniorProjectCharacter_NoRegister()
	{
		return ANPJ2018SeniorProjectCharacter::StaticClass();
	}
	UClass* Z_Construct_UClass_ANPJ2018SeniorProjectCharacter()
	{
		static UClass* OuterClass = NULL;
		if (!OuterClass)
		{
			Z_Construct_UClass_ACharacter();
			Z_Construct_UPackage__Script_NPJ2018SeniorProject();
			OuterClass = ANPJ2018SeniorProjectCharacter::StaticClass();
			if (!(OuterClass->ClassFlags & CLASS_Constructed))
			{
				UObjectForceRegistration(OuterClass);
				OuterClass->ClassFlags |= (EClassFlags)0x20800080u;

				OuterClass->LinkChild(Z_Construct_UFunction_ANPJ2018SeniorProjectCharacter_CollectPickups());
				OuterClass->LinkChild(Z_Construct_UFunction_ANPJ2018SeniorProjectCharacter_GetCurrentPower());
				OuterClass->LinkChild(Z_Construct_UFunction_ANPJ2018SeniorProjectCharacter_GetInitialPower());
				OuterClass->LinkChild(Z_Construct_UFunction_ANPJ2018SeniorProjectCharacter_PowerChangeEffect());
				OuterClass->LinkChild(Z_Construct_UFunction_ANPJ2018SeniorProjectCharacter_UpdateCharacterPower());

				UProperty* NewProp_characterPower = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("characterPower"), RF_Public|RF_Transient|RF_MarkAsNative) UFloatProperty(CPP_PROPERTY_BASE(characterPower, ANPJ2018SeniorProjectCharacter), 0x0040000000020001);
				UProperty* NewProp_baseSpeed = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("baseSpeed"), RF_Public|RF_Transient|RF_MarkAsNative) UFloatProperty(CPP_PROPERTY_BASE(baseSpeed, ANPJ2018SeniorProjectCharacter), 0x0020080000000005);
				UProperty* NewProp_speedFactor = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("speedFactor"), RF_Public|RF_Transient|RF_MarkAsNative) UFloatProperty(CPP_PROPERTY_BASE(speedFactor, ANPJ2018SeniorProjectCharacter), 0x0020080000000005);
				UProperty* NewProp_initialPower = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("initialPower"), RF_Public|RF_Transient|RF_MarkAsNative) UFloatProperty(CPP_PROPERTY_BASE(initialPower, ANPJ2018SeniorProjectCharacter), 0x0020080000000005);
				UProperty* NewProp_BaseLookUpRate = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("BaseLookUpRate"), RF_Public|RF_Transient|RF_MarkAsNative) UFloatProperty(CPP_PROPERTY_BASE(BaseLookUpRate, ANPJ2018SeniorProjectCharacter), 0x0010000000020015);
				UProperty* NewProp_BaseTurnRate = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("BaseTurnRate"), RF_Public|RF_Transient|RF_MarkAsNative) UFloatProperty(CPP_PROPERTY_BASE(BaseTurnRate, ANPJ2018SeniorProjectCharacter), 0x0010000000020015);
				UProperty* NewProp_CollectionSphere = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("CollectionSphere"), RF_Public|RF_Transient|RF_MarkAsNative) UObjectProperty(CPP_PROPERTY_BASE(CollectionSphere, ANPJ2018SeniorProjectCharacter), 0x00400000000a001d, Z_Construct_UClass_USphereComponent_NoRegister());
				UProperty* NewProp_FollowCamera = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("FollowCamera"), RF_Public|RF_Transient|RF_MarkAsNative) UObjectProperty(CPP_PROPERTY_BASE(FollowCamera, ANPJ2018SeniorProjectCharacter), 0x00400000000a001d, Z_Construct_UClass_UCameraComponent_NoRegister());
				UProperty* NewProp_CameraBoom = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("CameraBoom"), RF_Public|RF_Transient|RF_MarkAsNative) UObjectProperty(CPP_PROPERTY_BASE(CameraBoom, ANPJ2018SeniorProjectCharacter), 0x00400000000a001d, Z_Construct_UClass_USpringArmComponent_NoRegister());
				OuterClass->AddFunctionToFunctionMapWithOverriddenName(Z_Construct_UFunction_ANPJ2018SeniorProjectCharacter_CollectPickups(), "CollectPickups"); // 2624987453
				OuterClass->AddFunctionToFunctionMapWithOverriddenName(Z_Construct_UFunction_ANPJ2018SeniorProjectCharacter_GetCurrentPower(), "GetCurrentPower"); // 2235971854
				OuterClass->AddFunctionToFunctionMapWithOverriddenName(Z_Construct_UFunction_ANPJ2018SeniorProjectCharacter_GetInitialPower(), "GetInitialPower"); // 2632555715
				OuterClass->AddFunctionToFunctionMapWithOverriddenName(Z_Construct_UFunction_ANPJ2018SeniorProjectCharacter_PowerChangeEffect(), "PowerChangeEffect"); // 3018423847
				OuterClass->AddFunctionToFunctionMapWithOverriddenName(Z_Construct_UFunction_ANPJ2018SeniorProjectCharacter_UpdateCharacterPower(), "UpdateCharacterPower"); // 3659131815
				OuterClass->ClassConfigName = FName(TEXT("Game"));
				static TCppClassTypeInfo<TCppClassTypeTraits<ANPJ2018SeniorProjectCharacter> > StaticCppClassTypeInfo;
				OuterClass->SetCppTypeInfo(&StaticCppClassTypeInfo);
				OuterClass->StaticLink();
#if WITH_METADATA
				UMetaData* MetaData = OuterClass->GetOutermost()->GetMetaData();
				MetaData->SetValue(OuterClass, TEXT("HideCategories"), TEXT("Navigation"));
				MetaData->SetValue(OuterClass, TEXT("IncludePath"), TEXT("NPJ2018SeniorProjectCharacter.h"));
				MetaData->SetValue(OuterClass, TEXT("ModuleRelativePath"), TEXT("NPJ2018SeniorProjectCharacter.h"));
				MetaData->SetValue(NewProp_characterPower, TEXT("Category"), TEXT("Power"));
				MetaData->SetValue(NewProp_characterPower, TEXT("ModuleRelativePath"), TEXT("NPJ2018SeniorProjectCharacter.h"));
				MetaData->SetValue(NewProp_characterPower, TEXT("ToolTip"), TEXT("Current power level of our character"));
				MetaData->SetValue(NewProp_baseSpeed, TEXT("BluePrintProtected"), TEXT("TRUE"));
				MetaData->SetValue(NewProp_baseSpeed, TEXT("Category"), TEXT("Power"));
				MetaData->SetValue(NewProp_baseSpeed, TEXT("ModuleRelativePath"), TEXT("NPJ2018SeniorProjectCharacter.h"));
				MetaData->SetValue(NewProp_baseSpeed, TEXT("ToolTip"), TEXT("Speed when power level = 0"));
				MetaData->SetValue(NewProp_speedFactor, TEXT("BluePrintProtected"), TEXT("TRUE"));
				MetaData->SetValue(NewProp_speedFactor, TEXT("Category"), TEXT("Power"));
				MetaData->SetValue(NewProp_speedFactor, TEXT("ModuleRelativePath"), TEXT("NPJ2018SeniorProjectCharacter.h"));
				MetaData->SetValue(NewProp_speedFactor, TEXT("ToolTip"), TEXT("Multiplier for  character speed"));
				MetaData->SetValue(NewProp_initialPower, TEXT("BluePrintProtected"), TEXT("TRUE"));
				MetaData->SetValue(NewProp_initialPower, TEXT("Category"), TEXT("Power"));
				MetaData->SetValue(NewProp_initialPower, TEXT("ModuleRelativePath"), TEXT("NPJ2018SeniorProjectCharacter.h"));
				MetaData->SetValue(NewProp_initialPower, TEXT("ToolTip"), TEXT("The starting power level of our character"));
				MetaData->SetValue(NewProp_BaseLookUpRate, TEXT("Category"), TEXT("Camera"));
				MetaData->SetValue(NewProp_BaseLookUpRate, TEXT("ModuleRelativePath"), TEXT("NPJ2018SeniorProjectCharacter.h"));
				MetaData->SetValue(NewProp_BaseLookUpRate, TEXT("ToolTip"), TEXT("Base look up/down rate, in deg/sec. Other scaling may affect final rate."));
				MetaData->SetValue(NewProp_BaseTurnRate, TEXT("Category"), TEXT("Camera"));
				MetaData->SetValue(NewProp_BaseTurnRate, TEXT("ModuleRelativePath"), TEXT("NPJ2018SeniorProjectCharacter.h"));
				MetaData->SetValue(NewProp_BaseTurnRate, TEXT("ToolTip"), TEXT("Base turn rate, in deg/sec. Other scaling may affect final turn rate."));
				MetaData->SetValue(NewProp_CollectionSphere, TEXT("AllowPrivateAccess"), TEXT("true"));
				MetaData->SetValue(NewProp_CollectionSphere, TEXT("Category"), TEXT("Camera"));
				MetaData->SetValue(NewProp_CollectionSphere, TEXT("EditInline"), TEXT("true"));
				MetaData->SetValue(NewProp_CollectionSphere, TEXT("ModuleRelativePath"), TEXT("NPJ2018SeniorProjectCharacter.h"));
				MetaData->SetValue(NewProp_CollectionSphere, TEXT("ToolTip"), TEXT("Collection Sphere"));
				MetaData->SetValue(NewProp_FollowCamera, TEXT("AllowPrivateAccess"), TEXT("true"));
				MetaData->SetValue(NewProp_FollowCamera, TEXT("Category"), TEXT("Camera"));
				MetaData->SetValue(NewProp_FollowCamera, TEXT("EditInline"), TEXT("true"));
				MetaData->SetValue(NewProp_FollowCamera, TEXT("ModuleRelativePath"), TEXT("NPJ2018SeniorProjectCharacter.h"));
				MetaData->SetValue(NewProp_FollowCamera, TEXT("ToolTip"), TEXT("Follow camera"));
				MetaData->SetValue(NewProp_CameraBoom, TEXT("AllowPrivateAccess"), TEXT("true"));
				MetaData->SetValue(NewProp_CameraBoom, TEXT("Category"), TEXT("Camera"));
				MetaData->SetValue(NewProp_CameraBoom, TEXT("EditInline"), TEXT("true"));
				MetaData->SetValue(NewProp_CameraBoom, TEXT("ModuleRelativePath"), TEXT("NPJ2018SeniorProjectCharacter.h"));
				MetaData->SetValue(NewProp_CameraBoom, TEXT("ToolTip"), TEXT("Camera boom positioning the camera behind the character"));
#endif
			}
		}
		check(OuterClass->GetClass());
		return OuterClass;
	}
	IMPLEMENT_CLASS(ANPJ2018SeniorProjectCharacter, 1426514873);
	static FCompiledInDefer Z_CompiledInDefer_UClass_ANPJ2018SeniorProjectCharacter(Z_Construct_UClass_ANPJ2018SeniorProjectCharacter, &ANPJ2018SeniorProjectCharacter::StaticClass, TEXT("/Script/NPJ2018SeniorProject"), TEXT("ANPJ2018SeniorProjectCharacter"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(ANPJ2018SeniorProjectCharacter);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
PRAGMA_ENABLE_OPTIMIZATION
