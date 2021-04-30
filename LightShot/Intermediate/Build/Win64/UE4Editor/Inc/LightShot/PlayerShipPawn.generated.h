// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef LIGHTSHOT_PlayerShipPawn_generated_h
#error "PlayerShipPawn.generated.h already included, missing '#pragma once' in PlayerShipPawn.h"
#endif
#define LIGHTSHOT_PlayerShipPawn_generated_h

#define LightShot_Source_LightShot_PlayerShipPawn_h_20_SPARSE_DATA
#define LightShot_Source_LightShot_PlayerShipPawn_h_20_RPC_WRAPPERS
#define LightShot_Source_LightShot_PlayerShipPawn_h_20_RPC_WRAPPERS_NO_PURE_DECLS
#define LightShot_Source_LightShot_PlayerShipPawn_h_20_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAPlayerShipPawn(); \
	friend struct Z_Construct_UClass_APlayerShipPawn_Statics; \
public: \
	DECLARE_CLASS(APlayerShipPawn, AShipPawnBase, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/LightShot"), NO_API) \
	DECLARE_SERIALIZER(APlayerShipPawn)


#define LightShot_Source_LightShot_PlayerShipPawn_h_20_INCLASS \
private: \
	static void StaticRegisterNativesAPlayerShipPawn(); \
	friend struct Z_Construct_UClass_APlayerShipPawn_Statics; \
public: \
	DECLARE_CLASS(APlayerShipPawn, AShipPawnBase, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/LightShot"), NO_API) \
	DECLARE_SERIALIZER(APlayerShipPawn)


#define LightShot_Source_LightShot_PlayerShipPawn_h_20_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API APlayerShipPawn(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(APlayerShipPawn) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, APlayerShipPawn); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(APlayerShipPawn); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API APlayerShipPawn(APlayerShipPawn&&); \
	NO_API APlayerShipPawn(const APlayerShipPawn&); \
public:


#define LightShot_Source_LightShot_PlayerShipPawn_h_20_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API APlayerShipPawn(APlayerShipPawn&&); \
	NO_API APlayerShipPawn(const APlayerShipPawn&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, APlayerShipPawn); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(APlayerShipPawn); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(APlayerShipPawn)


#define LightShot_Source_LightShot_PlayerShipPawn_h_20_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__CameraComponent() { return STRUCT_OFFSET(APlayerShipPawn, CameraComponent); } \
	FORCEINLINE static uint32 __PPO__MoveActorComponent() { return STRUCT_OFFSET(APlayerShipPawn, MoveActorComponent); } \
	FORCEINLINE static uint32 __PPO__RotateActorComponent() { return STRUCT_OFFSET(APlayerShipPawn, RotateActorComponent); } \
	FORCEINLINE static uint32 __PPO__CameraBoom() { return STRUCT_OFFSET(APlayerShipPawn, CameraBoom); } \
	FORCEINLINE static uint32 __PPO__ProjectileClass() { return STRUCT_OFFSET(APlayerShipPawn, ProjectileClass); }


#define LightShot_Source_LightShot_PlayerShipPawn_h_17_PROLOG
#define LightShot_Source_LightShot_PlayerShipPawn_h_20_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	LightShot_Source_LightShot_PlayerShipPawn_h_20_PRIVATE_PROPERTY_OFFSET \
	LightShot_Source_LightShot_PlayerShipPawn_h_20_SPARSE_DATA \
	LightShot_Source_LightShot_PlayerShipPawn_h_20_RPC_WRAPPERS \
	LightShot_Source_LightShot_PlayerShipPawn_h_20_INCLASS \
	LightShot_Source_LightShot_PlayerShipPawn_h_20_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define LightShot_Source_LightShot_PlayerShipPawn_h_20_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	LightShot_Source_LightShot_PlayerShipPawn_h_20_PRIVATE_PROPERTY_OFFSET \
	LightShot_Source_LightShot_PlayerShipPawn_h_20_SPARSE_DATA \
	LightShot_Source_LightShot_PlayerShipPawn_h_20_RPC_WRAPPERS_NO_PURE_DECLS \
	LightShot_Source_LightShot_PlayerShipPawn_h_20_INCLASS_NO_PURE_DECLS \
	LightShot_Source_LightShot_PlayerShipPawn_h_20_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> LIGHTSHOT_API UClass* StaticClass<class APlayerShipPawn>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID LightShot_Source_LightShot_PlayerShipPawn_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
