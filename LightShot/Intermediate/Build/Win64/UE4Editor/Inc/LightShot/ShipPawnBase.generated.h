// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef LIGHTSHOT_ShipPawnBase_generated_h
#error "ShipPawnBase.generated.h already included, missing '#pragma once' in ShipPawnBase.h"
#endif
#define LIGHTSHOT_ShipPawnBase_generated_h

#define LightShot_Source_LightShot_ShipPawnBase_h_15_SPARSE_DATA
#define LightShot_Source_LightShot_ShipPawnBase_h_15_RPC_WRAPPERS
#define LightShot_Source_LightShot_ShipPawnBase_h_15_RPC_WRAPPERS_NO_PURE_DECLS
#define LightShot_Source_LightShot_ShipPawnBase_h_15_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAShipPawnBase(); \
	friend struct Z_Construct_UClass_AShipPawnBase_Statics; \
public: \
	DECLARE_CLASS(AShipPawnBase, APawn, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/LightShot"), NO_API) \
	DECLARE_SERIALIZER(AShipPawnBase)


#define LightShot_Source_LightShot_ShipPawnBase_h_15_INCLASS \
private: \
	static void StaticRegisterNativesAShipPawnBase(); \
	friend struct Z_Construct_UClass_AShipPawnBase_Statics; \
public: \
	DECLARE_CLASS(AShipPawnBase, APawn, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/LightShot"), NO_API) \
	DECLARE_SERIALIZER(AShipPawnBase)


#define LightShot_Source_LightShot_ShipPawnBase_h_15_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AShipPawnBase(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AShipPawnBase) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AShipPawnBase); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AShipPawnBase); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AShipPawnBase(AShipPawnBase&&); \
	NO_API AShipPawnBase(const AShipPawnBase&); \
public:


#define LightShot_Source_LightShot_ShipPawnBase_h_15_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AShipPawnBase(AShipPawnBase&&); \
	NO_API AShipPawnBase(const AShipPawnBase&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AShipPawnBase); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AShipPawnBase); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AShipPawnBase)


#define LightShot_Source_LightShot_ShipPawnBase_h_15_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__ShipMesh() { return STRUCT_OFFSET(AShipPawnBase, ShipMesh); } \
	FORCEINLINE static uint32 __PPO__CollisionComponent() { return STRUCT_OFFSET(AShipPawnBase, CollisionComponent); } \
	FORCEINLINE static uint32 __PPO__FireSpawnPoint() { return STRUCT_OFFSET(AShipPawnBase, FireSpawnPoint); }


#define LightShot_Source_LightShot_ShipPawnBase_h_12_PROLOG
#define LightShot_Source_LightShot_ShipPawnBase_h_15_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	LightShot_Source_LightShot_ShipPawnBase_h_15_PRIVATE_PROPERTY_OFFSET \
	LightShot_Source_LightShot_ShipPawnBase_h_15_SPARSE_DATA \
	LightShot_Source_LightShot_ShipPawnBase_h_15_RPC_WRAPPERS \
	LightShot_Source_LightShot_ShipPawnBase_h_15_INCLASS \
	LightShot_Source_LightShot_ShipPawnBase_h_15_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define LightShot_Source_LightShot_ShipPawnBase_h_15_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	LightShot_Source_LightShot_ShipPawnBase_h_15_PRIVATE_PROPERTY_OFFSET \
	LightShot_Source_LightShot_ShipPawnBase_h_15_SPARSE_DATA \
	LightShot_Source_LightShot_ShipPawnBase_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
	LightShot_Source_LightShot_ShipPawnBase_h_15_INCLASS_NO_PURE_DECLS \
	LightShot_Source_LightShot_ShipPawnBase_h_15_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> LIGHTSHOT_API UClass* StaticClass<class AShipPawnBase>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID LightShot_Source_LightShot_ShipPawnBase_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
