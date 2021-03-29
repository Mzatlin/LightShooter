// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "LightShot/LightShotGameMode.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeLightShotGameMode() {}
// Cross Module References
	LIGHTSHOT_API UClass* Z_Construct_UClass_ALightShotGameMode_NoRegister();
	LIGHTSHOT_API UClass* Z_Construct_UClass_ALightShotGameMode();
	ENGINE_API UClass* Z_Construct_UClass_AGameModeBase();
	UPackage* Z_Construct_UPackage__Script_LightShot();
// End Cross Module References
	void ALightShotGameMode::StaticRegisterNativesALightShotGameMode()
	{
	}
	UClass* Z_Construct_UClass_ALightShotGameMode_NoRegister()
	{
		return ALightShotGameMode::StaticClass();
	}
	struct Z_Construct_UClass_ALightShotGameMode_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ALightShotGameMode_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AGameModeBase,
		(UObject* (*)())Z_Construct_UPackage__Script_LightShot,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ALightShotGameMode_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering Utilities|Transformation" },
		{ "IncludePath", "LightShotGameMode.h" },
		{ "ModuleRelativePath", "LightShotGameMode.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_ALightShotGameMode_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ALightShotGameMode>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_ALightShotGameMode_Statics::ClassParams = {
		&ALightShotGameMode::StaticClass,
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
		0x008802ACu,
		METADATA_PARAMS(Z_Construct_UClass_ALightShotGameMode_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_ALightShotGameMode_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_ALightShotGameMode()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_ALightShotGameMode_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(ALightShotGameMode, 3981671609);
	template<> LIGHTSHOT_API UClass* StaticClass<ALightShotGameMode>()
	{
		return ALightShotGameMode::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_ALightShotGameMode(Z_Construct_UClass_ALightShotGameMode, &ALightShotGameMode::StaticClass, TEXT("/Script/LightShot"), TEXT("ALightShotGameMode"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(ALightShotGameMode);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
