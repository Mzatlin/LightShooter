// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "LightShot/ShipPawnBase.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeShipPawnBase() {}
// Cross Module References
	LIGHTSHOT_API UClass* Z_Construct_UClass_AShipPawnBase_NoRegister();
	LIGHTSHOT_API UClass* Z_Construct_UClass_AShipPawnBase();
	ENGINE_API UClass* Z_Construct_UClass_APawn();
	UPackage* Z_Construct_UPackage__Script_LightShot();
// End Cross Module References
	void AShipPawnBase::StaticRegisterNativesAShipPawnBase()
	{
	}
	UClass* Z_Construct_UClass_AShipPawnBase_NoRegister()
	{
		return AShipPawnBase::StaticClass();
	}
	struct Z_Construct_UClass_AShipPawnBase_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AShipPawnBase_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_APawn,
		(UObject* (*)())Z_Construct_UPackage__Script_LightShot,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AShipPawnBase_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Navigation" },
		{ "IncludePath", "ShipPawnBase.h" },
		{ "ModuleRelativePath", "ShipPawnBase.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_AShipPawnBase_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AShipPawnBase>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AShipPawnBase_Statics::ClassParams = {
		&AShipPawnBase::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x009000A4u,
		METADATA_PARAMS(Z_Construct_UClass_AShipPawnBase_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AShipPawnBase_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AShipPawnBase()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AShipPawnBase_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AShipPawnBase, 170505623);
	template<> LIGHTSHOT_API UClass* StaticClass<AShipPawnBase>()
	{
		return AShipPawnBase::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AShipPawnBase(Z_Construct_UClass_AShipPawnBase, &AShipPawnBase::StaticClass, TEXT("/Script/LightShot"), TEXT("AShipPawnBase"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AShipPawnBase);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
