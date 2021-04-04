// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "LightShot/MovePlayerShip.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeMovePlayerShip() {}
// Cross Module References
	LIGHTSHOT_API UClass* Z_Construct_UClass_UMovePlayerShip_NoRegister();
	LIGHTSHOT_API UClass* Z_Construct_UClass_UMovePlayerShip();
	LIGHTSHOT_API UClass* Z_Construct_UClass_UMoveActorBase();
	UPackage* Z_Construct_UPackage__Script_LightShot();
// End Cross Module References
	void UMovePlayerShip::StaticRegisterNativesUMovePlayerShip()
	{
	}
	UClass* Z_Construct_UClass_UMovePlayerShip_NoRegister()
	{
		return UMovePlayerShip::StaticClass();
	}
	struct Z_Construct_UClass_UMovePlayerShip_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UMovePlayerShip_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UMoveActorBase,
		(UObject* (*)())Z_Construct_UPackage__Script_LightShot,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UMovePlayerShip_Statics::Class_MetaDataParams[] = {
		{ "BlueprintSpawnableComponent", "" },
		{ "ClassGroupNames", "Custom" },
		{ "IncludePath", "MovePlayerShip.h" },
		{ "ModuleRelativePath", "MovePlayerShip.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UMovePlayerShip_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UMovePlayerShip>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UMovePlayerShip_Statics::ClassParams = {
		&UMovePlayerShip::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x00B000A4u,
		METADATA_PARAMS(Z_Construct_UClass_UMovePlayerShip_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UMovePlayerShip_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UMovePlayerShip()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UMovePlayerShip_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UMovePlayerShip, 2260915055);
	template<> LIGHTSHOT_API UClass* StaticClass<UMovePlayerShip>()
	{
		return UMovePlayerShip::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UMovePlayerShip(Z_Construct_UClass_UMovePlayerShip, &UMovePlayerShip::StaticClass, TEXT("/Script/LightShot"), TEXT("UMovePlayerShip"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UMovePlayerShip);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
