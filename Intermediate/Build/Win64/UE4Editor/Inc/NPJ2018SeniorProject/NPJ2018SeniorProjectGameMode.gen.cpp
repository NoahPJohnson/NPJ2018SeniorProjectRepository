// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "GeneratedCppIncludes.h"
#include "NPJ2018SeniorProjectGameMode.h"
PRAGMA_DISABLE_OPTIMIZATION
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeNPJ2018SeniorProjectGameMode() {}
// Cross Module References
	NPJ2018SENIORPROJECT_API UEnum* Z_Construct_UEnum_NPJ2018SeniorProject_EProjectPlayState();
	UPackage* Z_Construct_UPackage__Script_NPJ2018SeniorProject();
	NPJ2018SENIORPROJECT_API UFunction* Z_Construct_UFunction_ANPJ2018SeniorProjectGameMode_GetCurrentState();
	NPJ2018SENIORPROJECT_API UClass* Z_Construct_UClass_ANPJ2018SeniorProjectGameMode();
	NPJ2018SENIORPROJECT_API UFunction* Z_Construct_UFunction_ANPJ2018SeniorProjectGameMode_GetPowerToWin();
	NPJ2018SENIORPROJECT_API UClass* Z_Construct_UClass_ANPJ2018SeniorProjectGameMode_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_AGameModeBase();
	UMG_API UClass* Z_Construct_UClass_UUserWidget_NoRegister();
	COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
// End Cross Module References
static UEnum* EProjectPlayState_StaticEnum()
{
	static UEnum* Singleton = nullptr;
	if (!Singleton)
	{
		Singleton = GetStaticEnum(Z_Construct_UEnum_NPJ2018SeniorProject_EProjectPlayState, Z_Construct_UPackage__Script_NPJ2018SeniorProject(), TEXT("EProjectPlayState"));
	}
	return Singleton;
}
static FCompiledInDeferEnum Z_CompiledInDeferEnum_UEnum_EProjectPlayState(EProjectPlayState_StaticEnum, TEXT("/Script/NPJ2018SeniorProject"), TEXT("EProjectPlayState"), false, nullptr, nullptr);
	UEnum* Z_Construct_UEnum_NPJ2018SeniorProject_EProjectPlayState()
	{
		UPackage* Outer = Z_Construct_UPackage__Script_NPJ2018SeniorProject();
		extern uint32 Get_Z_Construct_UEnum_NPJ2018SeniorProject_EProjectPlayState_CRC();
		static UEnum* ReturnEnum = FindExistingEnumIfHotReloadOrDynamic(Outer, TEXT("EProjectPlayState"), 0, Get_Z_Construct_UEnum_NPJ2018SeniorProject_EProjectPlayState_CRC(), false);
		if (!ReturnEnum)
		{
			ReturnEnum = new(EC_InternalUseOnlyConstructor, Outer, TEXT("EProjectPlayState"), RF_Public|RF_Transient|RF_MarkAsNative) UEnum(FObjectInitializer());
			TArray<TPair<FName, int64>> EnumNames;
			EnumNames.Emplace(TEXT("EProjectPlayState::EPlaying"), 0);
			EnumNames.Emplace(TEXT("EProjectPlayState::EGameOver"), 1);
			EnumNames.Emplace(TEXT("EProjectPlayState::EWon"), 2);
			EnumNames.Emplace(TEXT("EProjectPlayState::EUnknown"), 3);
			EnumNames.Emplace(TEXT("EProjectPlayState::EProjectPlayState_MAX"), 4);
			ReturnEnum->SetEnums(EnumNames, UEnum::ECppForm::EnumClass);
			ReturnEnum->CppType = TEXT("EProjectPlayState");
#if WITH_METADATA
			UMetaData* MetaData = ReturnEnum->GetOutermost()->GetMetaData();
			MetaData->SetValue(ReturnEnum, TEXT("BlueprintType"), TEXT("true"));
			MetaData->SetValue(ReturnEnum, TEXT("ModuleRelativePath"), TEXT("NPJ2018SeniorProjectGameMode.h"));
			MetaData->SetValue(ReturnEnum, TEXT("ToolTip"), TEXT("enum to store the current state of gameplay"));
#endif
		}
		return ReturnEnum;
	}
	uint32 Get_Z_Construct_UEnum_NPJ2018SeniorProject_EProjectPlayState_CRC() { return 3218961748U; }
	void ANPJ2018SeniorProjectGameMode::StaticRegisterNativesANPJ2018SeniorProjectGameMode()
	{
		UClass* Class = ANPJ2018SeniorProjectGameMode::StaticClass();
		static const TNameNativePtrPair<ANSICHAR> AnsiFuncs[] = {
			{ "GetCurrentState", (Native)&ANPJ2018SeniorProjectGameMode::execGetCurrentState },
			{ "GetPowerToWin", (Native)&ANPJ2018SeniorProjectGameMode::execGetPowerToWin },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, AnsiFuncs, ARRAY_COUNT(AnsiFuncs));
	}
	UFunction* Z_Construct_UFunction_ANPJ2018SeniorProjectGameMode_GetCurrentState()
	{
		struct NPJ2018SeniorProjectGameMode_eventGetCurrentState_Parms
		{
			EProjectPlayState ReturnValue;
		};
		UObject* Outer = Z_Construct_UClass_ANPJ2018SeniorProjectGameMode();
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			ReturnFunction = new(EC_InternalUseOnlyConstructor, Outer, TEXT("GetCurrentState"), RF_Public|RF_Transient|RF_MarkAsNative) UFunction(FObjectInitializer(), nullptr, (EFunctionFlags)0x54020401, 65535, sizeof(NPJ2018SeniorProjectGameMode_eventGetCurrentState_Parms));
			UProperty* NewProp_ReturnValue = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("ReturnValue"), RF_Public|RF_Transient|RF_MarkAsNative) UEnumProperty(CPP_PROPERTY_BASE(ReturnValue, NPJ2018SeniorProjectGameMode_eventGetCurrentState_Parms), 0x0010000000000580, Z_Construct_UEnum_NPJ2018SeniorProject_EProjectPlayState());
			UProperty* NewProp_ReturnValue_Underlying = new(EC_InternalUseOnlyConstructor, NewProp_ReturnValue, TEXT("UnderlyingType"), RF_Public|RF_Transient|RF_MarkAsNative) UByteProperty(FObjectInitializer(), EC_CppProperty, 0, 0x0000000000000000);
			ReturnFunction->Bind();
			ReturnFunction->StaticLink();
#if WITH_METADATA
			UMetaData* MetaData = ReturnFunction->GetOutermost()->GetMetaData();
			MetaData->SetValue(ReturnFunction, TEXT("Category"), TEXT("Power"));
			MetaData->SetValue(ReturnFunction, TEXT("ModuleRelativePath"), TEXT("NPJ2018SeniorProjectGameMode.h"));
			MetaData->SetValue(ReturnFunction, TEXT("ToolTip"), TEXT("Returns the current state"));
#endif
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_ANPJ2018SeniorProjectGameMode_GetPowerToWin()
	{
		struct NPJ2018SeniorProjectGameMode_eventGetPowerToWin_Parms
		{
			float ReturnValue;
		};
		UObject* Outer = Z_Construct_UClass_ANPJ2018SeniorProjectGameMode();
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			ReturnFunction = new(EC_InternalUseOnlyConstructor, Outer, TEXT("GetPowerToWin"), RF_Public|RF_Transient|RF_MarkAsNative) UFunction(FObjectInitializer(), nullptr, (EFunctionFlags)0x54020401, 65535, sizeof(NPJ2018SeniorProjectGameMode_eventGetPowerToWin_Parms));
			UProperty* NewProp_ReturnValue = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("ReturnValue"), RF_Public|RF_Transient|RF_MarkAsNative) UFloatProperty(CPP_PROPERTY_BASE(ReturnValue, NPJ2018SeniorProjectGameMode_eventGetPowerToWin_Parms), 0x0010000000000580);
			ReturnFunction->Bind();
			ReturnFunction->StaticLink();
#if WITH_METADATA
			UMetaData* MetaData = ReturnFunction->GetOutermost()->GetMetaData();
			MetaData->SetValue(ReturnFunction, TEXT("Category"), TEXT("Power"));
			MetaData->SetValue(ReturnFunction, TEXT("ModuleRelativePath"), TEXT("NPJ2018SeniorProjectGameMode.h"));
			MetaData->SetValue(ReturnFunction, TEXT("ToolTip"), TEXT("Returns power needed to win for the hud"));
#endif
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_ANPJ2018SeniorProjectGameMode_NoRegister()
	{
		return ANPJ2018SeniorProjectGameMode::StaticClass();
	}
	UClass* Z_Construct_UClass_ANPJ2018SeniorProjectGameMode()
	{
		static UClass* OuterClass = NULL;
		if (!OuterClass)
		{
			Z_Construct_UClass_AGameModeBase();
			Z_Construct_UPackage__Script_NPJ2018SeniorProject();
			OuterClass = ANPJ2018SeniorProjectGameMode::StaticClass();
			if (!(OuterClass->ClassFlags & CLASS_Constructed))
			{
				UObjectForceRegistration(OuterClass);
				OuterClass->ClassFlags |= (EClassFlags)0x20880288u;

				OuterClass->LinkChild(Z_Construct_UFunction_ANPJ2018SeniorProjectGameMode_GetCurrentState());
				OuterClass->LinkChild(Z_Construct_UFunction_ANPJ2018SeniorProjectGameMode_GetPowerToWin());

				UProperty* NewProp_CurrentWidget = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("CurrentWidget"), RF_Public|RF_Transient|RF_MarkAsNative) UObjectProperty(CPP_PROPERTY_BASE(CurrentWidget, ANPJ2018SeniorProjectGameMode), 0x0020080000080008, Z_Construct_UClass_UUserWidget_NoRegister());
				UProperty* NewProp_HUDWidgetClass = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("HUDWidgetClass"), RF_Public|RF_Transient|RF_MarkAsNative) UClassProperty(CPP_PROPERTY_BASE(HUDWidgetClass, ANPJ2018SeniorProjectGameMode), 0x0024080000010005, Z_Construct_UClass_UUserWidget_NoRegister(), Z_Construct_UClass_UClass());
				UProperty* NewProp_powerToWin = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("powerToWin"), RF_Public|RF_Transient|RF_MarkAsNative) UFloatProperty(CPP_PROPERTY_BASE(powerToWin, ANPJ2018SeniorProjectGameMode), 0x0020080000010005);
				UProperty* NewProp_decayRate = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("decayRate"), RF_Public|RF_Transient|RF_MarkAsNative) UFloatProperty(CPP_PROPERTY_BASE(decayRate, ANPJ2018SeniorProjectGameMode), 0x0020080000010005);
				OuterClass->AddFunctionToFunctionMapWithOverriddenName(Z_Construct_UFunction_ANPJ2018SeniorProjectGameMode_GetCurrentState(), "GetCurrentState"); // 956361597
				OuterClass->AddFunctionToFunctionMapWithOverriddenName(Z_Construct_UFunction_ANPJ2018SeniorProjectGameMode_GetPowerToWin(), "GetPowerToWin"); // 1414110336
				static TCppClassTypeInfo<TCppClassTypeTraits<ANPJ2018SeniorProjectGameMode> > StaticCppClassTypeInfo;
				OuterClass->SetCppTypeInfo(&StaticCppClassTypeInfo);
				OuterClass->StaticLink();
#if WITH_METADATA
				UMetaData* MetaData = OuterClass->GetOutermost()->GetMetaData();
				MetaData->SetValue(OuterClass, TEXT("HideCategories"), TEXT("Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering Utilities|Transformation"));
				MetaData->SetValue(OuterClass, TEXT("IncludePath"), TEXT("NPJ2018SeniorProjectGameMode.h"));
				MetaData->SetValue(OuterClass, TEXT("ModuleRelativePath"), TEXT("NPJ2018SeniorProjectGameMode.h"));
				MetaData->SetValue(OuterClass, TEXT("ShowCategories"), TEXT("Input|MouseInput Input|TouchInput"));
				MetaData->SetValue(NewProp_CurrentWidget, TEXT("EditInline"), TEXT("true"));
				MetaData->SetValue(NewProp_CurrentWidget, TEXT("ModuleRelativePath"), TEXT("NPJ2018SeniorProjectGameMode.h"));
				MetaData->SetValue(NewProp_CurrentWidget, TEXT("ToolTip"), TEXT("The instance of the hud"));
				MetaData->SetValue(NewProp_HUDWidgetClass, TEXT("BlueprintProtected"), TEXT("true"));
				MetaData->SetValue(NewProp_HUDWidgetClass, TEXT("Category"), TEXT("Power"));
				MetaData->SetValue(NewProp_HUDWidgetClass, TEXT("ModuleRelativePath"), TEXT("NPJ2018SeniorProjectGameMode.h"));
				MetaData->SetValue(NewProp_HUDWidgetClass, TEXT("ToolTip"), TEXT("The widget class to use for the hud screen"));
				MetaData->SetValue(NewProp_powerToWin, TEXT("BlueprintProtected"), TEXT("true"));
				MetaData->SetValue(NewProp_powerToWin, TEXT("Category"), TEXT("Power"));
				MetaData->SetValue(NewProp_powerToWin, TEXT("ModuleRelativePath"), TEXT("NPJ2018SeniorProjectGameMode.h"));
				MetaData->SetValue(NewProp_powerToWin, TEXT("ToolTip"), TEXT("The power needed to win the game"));
				MetaData->SetValue(NewProp_decayRate, TEXT("BlueprintProtected"), TEXT("true"));
				MetaData->SetValue(NewProp_decayRate, TEXT("Category"), TEXT("Power"));
				MetaData->SetValue(NewProp_decayRate, TEXT("ModuleRelativePath"), TEXT("NPJ2018SeniorProjectGameMode.h"));
				MetaData->SetValue(NewProp_decayRate, TEXT("ToolTip"), TEXT("Rate at which character loses power"));
#endif
			}
		}
		check(OuterClass->GetClass());
		return OuterClass;
	}
	IMPLEMENT_CLASS(ANPJ2018SeniorProjectGameMode, 833651869);
	static FCompiledInDefer Z_CompiledInDefer_UClass_ANPJ2018SeniorProjectGameMode(Z_Construct_UClass_ANPJ2018SeniorProjectGameMode, &ANPJ2018SeniorProjectGameMode::StaticClass, TEXT("/Script/NPJ2018SeniorProject"), TEXT("ANPJ2018SeniorProjectGameMode"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(ANPJ2018SeniorProjectGameMode);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
PRAGMA_ENABLE_OPTIMIZATION
