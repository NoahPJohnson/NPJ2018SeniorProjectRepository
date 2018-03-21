// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "GeneratedCppIncludes.h"
#include "C++Classes/BaseEnemy.h"
PRAGMA_DISABLE_OPTIMIZATION
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeBaseEnemy() {}
// Cross Module References
	NPJ2018SENIORPROJECT_API UClass* Z_Construct_UClass_ABaseEnemy_NoRegister();
	NPJ2018SENIORPROJECT_API UClass* Z_Construct_UClass_ABaseEnemy();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	UPackage* Z_Construct_UPackage__Script_NPJ2018SeniorProject();
	ENGINE_API UClass* Z_Construct_UClass_UStaticMeshComponent_NoRegister();
// End Cross Module References
	void ABaseEnemy::StaticRegisterNativesABaseEnemy()
	{
	}
	UClass* Z_Construct_UClass_ABaseEnemy_NoRegister()
	{
		return ABaseEnemy::StaticClass();
	}
	UClass* Z_Construct_UClass_ABaseEnemy()
	{
		static UClass* OuterClass = NULL;
		if (!OuterClass)
		{
			Z_Construct_UClass_AActor();
			Z_Construct_UPackage__Script_NPJ2018SeniorProject();
			OuterClass = ABaseEnemy::StaticClass();
			if (!(OuterClass->ClassFlags & CLASS_Constructed))
			{
				UObjectForceRegistration(OuterClass);
				OuterClass->ClassFlags |= (EClassFlags)0x20900080u;


				UProperty* NewProp_EnemyMesh = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("EnemyMesh"), RF_Public|RF_Transient|RF_MarkAsNative) UObjectProperty(CPP_PROPERTY_BASE(EnemyMesh, ABaseEnemy), 0x00400000000a001d, Z_Construct_UClass_UStaticMeshComponent_NoRegister());
				static TCppClassTypeInfo<TCppClassTypeTraits<ABaseEnemy> > StaticCppClassTypeInfo;
				OuterClass->SetCppTypeInfo(&StaticCppClassTypeInfo);
				OuterClass->StaticLink();
#if WITH_METADATA
				UMetaData* MetaData = OuterClass->GetOutermost()->GetMetaData();
				MetaData->SetValue(OuterClass, TEXT("IncludePath"), TEXT("C++Classes/BaseEnemy.h"));
				MetaData->SetValue(OuterClass, TEXT("ModuleRelativePath"), TEXT("C++Classes/BaseEnemy.h"));
				MetaData->SetValue(NewProp_EnemyMesh, TEXT("AllowPrivateAccess"), TEXT("TRUE"));
				MetaData->SetValue(NewProp_EnemyMesh, TEXT("Category"), TEXT("Enemy"));
				MetaData->SetValue(NewProp_EnemyMesh, TEXT("EditInline"), TEXT("true"));
				MetaData->SetValue(NewProp_EnemyMesh, TEXT("ModuleRelativePath"), TEXT("C++Classes/BaseEnemy.h"));
#endif
			}
		}
		check(OuterClass->GetClass());
		return OuterClass;
	}
	IMPLEMENT_CLASS(ABaseEnemy, 4216629857);
	static FCompiledInDefer Z_CompiledInDefer_UClass_ABaseEnemy(Z_Construct_UClass_ABaseEnemy, &ABaseEnemy::StaticClass, TEXT("/Script/NPJ2018SeniorProject"), TEXT("ABaseEnemy"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(ABaseEnemy);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
PRAGMA_ENABLE_OPTIMIZATION
