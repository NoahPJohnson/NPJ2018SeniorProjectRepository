// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "GeneratedCppIncludes.h"
#include "C++Classes/SpawnVolume.h"
PRAGMA_DISABLE_OPTIMIZATION
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeSpawnVolume() {}
// Cross Module References
	NPJ2018SENIORPROJECT_API UFunction* Z_Construct_UFunction_ASpawnVolume_GetRandomPointInVolume();
	NPJ2018SENIORPROJECT_API UClass* Z_Construct_UClass_ASpawnVolume();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
	NPJ2018SENIORPROJECT_API UFunction* Z_Construct_UFunction_ASpawnVolume_SetSpawningActive();
	NPJ2018SENIORPROJECT_API UClass* Z_Construct_UClass_ASpawnVolume_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	UPackage* Z_Construct_UPackage__Script_NPJ2018SeniorProject();
	ENGINE_API UClass* Z_Construct_UClass_UBoxComponent_NoRegister();
	NPJ2018SENIORPROJECT_API UClass* Z_Construct_UClass_APickup_NoRegister();
	COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
// End Cross Module References
	void ASpawnVolume::StaticRegisterNativesASpawnVolume()
	{
		UClass* Class = ASpawnVolume::StaticClass();
		static const TNameNativePtrPair<ANSICHAR> AnsiFuncs[] = {
			{ "GetRandomPointInVolume", (Native)&ASpawnVolume::execGetRandomPointInVolume },
			{ "SetSpawningActive", (Native)&ASpawnVolume::execSetSpawningActive },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, AnsiFuncs, ARRAY_COUNT(AnsiFuncs));
	}
	UFunction* Z_Construct_UFunction_ASpawnVolume_GetRandomPointInVolume()
	{
		struct SpawnVolume_eventGetRandomPointInVolume_Parms
		{
			FVector ReturnValue;
		};
		UObject* Outer = Z_Construct_UClass_ASpawnVolume();
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			ReturnFunction = new(EC_InternalUseOnlyConstructor, Outer, TEXT("GetRandomPointInVolume"), RF_Public|RF_Transient|RF_MarkAsNative) UFunction(FObjectInitializer(), nullptr, (EFunctionFlags)0x14820401, 65535, sizeof(SpawnVolume_eventGetRandomPointInVolume_Parms));
			UProperty* NewProp_ReturnValue = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("ReturnValue"), RF_Public|RF_Transient|RF_MarkAsNative) UStructProperty(CPP_PROPERTY_BASE(ReturnValue, SpawnVolume_eventGetRandomPointInVolume_Parms), 0x0010000000000580, Z_Construct_UScriptStruct_FVector());
			ReturnFunction->Bind();
			ReturnFunction->StaticLink();
#if WITH_METADATA
			UMetaData* MetaData = ReturnFunction->GetOutermost()->GetMetaData();
			MetaData->SetValue(ReturnFunction, TEXT("Category"), TEXT("Spawning"));
			MetaData->SetValue(ReturnFunction, TEXT("ModuleRelativePath"), TEXT("C++Classes/SpawnVolume.h"));
			MetaData->SetValue(ReturnFunction, TEXT("ToolTip"), TEXT("Find a random point within the BoxComponent"));
#endif
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_ASpawnVolume_SetSpawningActive()
	{
		struct SpawnVolume_eventSetSpawningActive_Parms
		{
			bool bShouldSpawn;
		};
		UObject* Outer = Z_Construct_UClass_ASpawnVolume();
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			ReturnFunction = new(EC_InternalUseOnlyConstructor, Outer, TEXT("SetSpawningActive"), RF_Public|RF_Transient|RF_MarkAsNative) UFunction(FObjectInitializer(), nullptr, (EFunctionFlags)0x04020401, 65535, sizeof(SpawnVolume_eventSetSpawningActive_Parms));
			CPP_BOOL_PROPERTY_BITMASK_STRUCT(bShouldSpawn, SpawnVolume_eventSetSpawningActive_Parms);
			UProperty* NewProp_bShouldSpawn = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("bShouldSpawn"), RF_Public|RF_Transient|RF_MarkAsNative) UBoolProperty(FObjectInitializer(), EC_CppProperty, CPP_BOOL_PROPERTY_OFFSET(bShouldSpawn, SpawnVolume_eventSetSpawningActive_Parms), 0x0010000000000080, CPP_BOOL_PROPERTY_BITMASK(bShouldSpawn, SpawnVolume_eventSetSpawningActive_Parms), sizeof(bool), true);
			ReturnFunction->Bind();
			ReturnFunction->StaticLink();
#if WITH_METADATA
			UMetaData* MetaData = ReturnFunction->GetOutermost()->GetMetaData();
			MetaData->SetValue(ReturnFunction, TEXT("Category"), TEXT("Spawning"));
			MetaData->SetValue(ReturnFunction, TEXT("ModuleRelativePath"), TEXT("C++Classes/SpawnVolume.h"));
			MetaData->SetValue(ReturnFunction, TEXT("ToolTip"), TEXT("This function toggles whether or not the spawn volumes should spawn pickups"));
#endif
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_ASpawnVolume_NoRegister()
	{
		return ASpawnVolume::StaticClass();
	}
	UClass* Z_Construct_UClass_ASpawnVolume()
	{
		static UClass* OuterClass = NULL;
		if (!OuterClass)
		{
			Z_Construct_UClass_AActor();
			Z_Construct_UPackage__Script_NPJ2018SeniorProject();
			OuterClass = ASpawnVolume::StaticClass();
			if (!(OuterClass->ClassFlags & CLASS_Constructed))
			{
				UObjectForceRegistration(OuterClass);
				OuterClass->ClassFlags |= (EClassFlags)0x20900080u;

				OuterClass->LinkChild(Z_Construct_UFunction_ASpawnVolume_GetRandomPointInVolume());
				OuterClass->LinkChild(Z_Construct_UFunction_ASpawnVolume_SetSpawningActive());

				UProperty* NewProp_whereToSpawn = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("whereToSpawn"), RF_Public|RF_Transient|RF_MarkAsNative) UObjectProperty(CPP_PROPERTY_BASE(whereToSpawn, ASpawnVolume), 0x00400000000a001d, Z_Construct_UClass_UBoxComponent_NoRegister());
				UProperty* NewProp_SpawnDelayRangeHigh = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("SpawnDelayRangeHigh"), RF_Public|RF_Transient|RF_MarkAsNative) UFloatProperty(CPP_PROPERTY_BASE(SpawnDelayRangeHigh, ASpawnVolume), 0x0020080000000005);
				UProperty* NewProp_SpawnDelayRangeLow = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("SpawnDelayRangeLow"), RF_Public|RF_Transient|RF_MarkAsNative) UFloatProperty(CPP_PROPERTY_BASE(SpawnDelayRangeLow, ASpawnVolume), 0x0020080000000005);
				UProperty* NewProp_whatToSpawn = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("whatToSpawn"), RF_Public|RF_Transient|RF_MarkAsNative) UClassProperty(CPP_PROPERTY_BASE(whatToSpawn, ASpawnVolume), 0x0024080000000001, Z_Construct_UClass_APickup_NoRegister(), Z_Construct_UClass_UClass());
				OuterClass->AddFunctionToFunctionMapWithOverriddenName(Z_Construct_UFunction_ASpawnVolume_GetRandomPointInVolume(), "GetRandomPointInVolume"); // 78667960
				OuterClass->AddFunctionToFunctionMapWithOverriddenName(Z_Construct_UFunction_ASpawnVolume_SetSpawningActive(), "SetSpawningActive"); // 2350484355
				static TCppClassTypeInfo<TCppClassTypeTraits<ASpawnVolume> > StaticCppClassTypeInfo;
				OuterClass->SetCppTypeInfo(&StaticCppClassTypeInfo);
				OuterClass->StaticLink();
#if WITH_METADATA
				UMetaData* MetaData = OuterClass->GetOutermost()->GetMetaData();
				MetaData->SetValue(OuterClass, TEXT("IncludePath"), TEXT("C++Classes/SpawnVolume.h"));
				MetaData->SetValue(OuterClass, TEXT("ModuleRelativePath"), TEXT("C++Classes/SpawnVolume.h"));
				MetaData->SetValue(NewProp_whereToSpawn, TEXT("AllowPrivateAccess"), TEXT("TRUE"));
				MetaData->SetValue(NewProp_whereToSpawn, TEXT("Category"), TEXT("Spawning"));
				MetaData->SetValue(NewProp_whereToSpawn, TEXT("EditInline"), TEXT("true"));
				MetaData->SetValue(NewProp_whereToSpawn, TEXT("ModuleRelativePath"), TEXT("C++Classes/SpawnVolume.h"));
				MetaData->SetValue(NewProp_whereToSpawn, TEXT("ToolTip"), TEXT("Box Component to specify where pickups should be spawned"));
				MetaData->SetValue(NewProp_SpawnDelayRangeHigh, TEXT("Category"), TEXT("Spawning"));
				MetaData->SetValue(NewProp_SpawnDelayRangeHigh, TEXT("ModuleRelativePath"), TEXT("C++Classes/SpawnVolume.h"));
				MetaData->SetValue(NewProp_SpawnDelayRangeHigh, TEXT("ToolTip"), TEXT("Maximum spawn delay"));
				MetaData->SetValue(NewProp_SpawnDelayRangeLow, TEXT("Category"), TEXT("Spawning"));
				MetaData->SetValue(NewProp_SpawnDelayRangeLow, TEXT("ModuleRelativePath"), TEXT("C++Classes/SpawnVolume.h"));
				MetaData->SetValue(NewProp_SpawnDelayRangeLow, TEXT("ToolTip"), TEXT("Minimum spawn delay"));
				MetaData->SetValue(NewProp_whatToSpawn, TEXT("Category"), TEXT("Spawning"));
				MetaData->SetValue(NewProp_whatToSpawn, TEXT("ModuleRelativePath"), TEXT("C++Classes/SpawnVolume.h"));
				MetaData->SetValue(NewProp_whatToSpawn, TEXT("ToolTip"), TEXT("The pickup to spawn"));
#endif
			}
		}
		check(OuterClass->GetClass());
		return OuterClass;
	}
	IMPLEMENT_CLASS(ASpawnVolume, 723163931);
	static FCompiledInDefer Z_CompiledInDefer_UClass_ASpawnVolume(Z_Construct_UClass_ASpawnVolume, &ASpawnVolume::StaticClass, TEXT("/Script/NPJ2018SeniorProject"), TEXT("ASpawnVolume"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(ASpawnVolume);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
PRAGMA_ENABLE_OPTIMIZATION
