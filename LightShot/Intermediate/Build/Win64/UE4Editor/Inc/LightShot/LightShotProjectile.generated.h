// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UPrimitiveComponent;
class AActor;
struct FVector;
struct FHitResult;
#ifdef LIGHTSHOT_LightShotProjectile_generated_h
#error "LightShotProjectile.generated.h already included, missing '#pragma once' in LightShotProjectile.h"
#endif
#define LIGHTSHOT_LightShotProjectile_generated_h

#define LightShot_Source_LightShot_LightShotProjectile_h_15_SPARSE_DATA
#define LightShot_Source_LightShot_LightShotProjectile_h_15_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execOnHit);


#define LightShot_Source_LightShot_LightShotProjectile_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execOnHit);


#define LightShot_Source_LightShot_LightShotProjectile_h_15_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesALightShotProjectile(); \
	friend struct Z_Construct_UClass_ALightShotProjectile_Statics; \
public: \
	DECLARE_CLASS(ALightShotProjectile, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/LightShot"), NO_API) \
	DECLARE_SERIALIZER(ALightShotProjectile) \
	static const TCHAR* StaticConfigName() {return TEXT("Game");} \



#define LightShot_Source_LightShot_LightShotProjectile_h_15_INCLASS \
private: \
	static void StaticRegisterNativesALightShotProjectile(); \
	friend struct Z_Construct_UClass_ALightShotProjectile_Statics; \
public: \
	DECLARE_CLASS(ALightShotProjectile, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/LightShot"), NO_API) \
	DECLARE_SERIALIZER(ALightShotProjectile) \
	static const TCHAR* StaticConfigName() {return TEXT("Game");} \



#define LightShot_Source_LightShot_LightShotProjectile_h_15_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ALightShotProjectile(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ALightShotProjectile) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ALightShotProjectile); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ALightShotProjectile); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ALightShotProjectile(ALightShotProjectile&&); \
	NO_API ALightShotProjectile(const ALightShotProjectile&); \
public:


#define LightShot_Source_LightShot_LightShotProjectile_h_15_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ALightShotProjectile(ALightShotProjectile&&); \
	NO_API ALightShotProjectile(const ALightShotProjectile&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ALightShotProjectile); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ALightShotProjectile); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(ALightShotProjectile)


#define LightShot_Source_LightShot_LightShotProjectile_h_15_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__ProjectileMesh() { return STRUCT_OFFSET(ALightShotProjectile, ProjectileMesh); } \
	FORCEINLINE static uint32 __PPO__ProjectileMovement() { return STRUCT_OFFSET(ALightShotProjectile, ProjectileMovement); } \
	FORCEINLINE static uint32 __PPO__Damage() { return STRUCT_OFFSET(ALightShotProjectile, Damage); } \
	FORCEINLINE static uint32 __PPO__DamageType() { return STRUCT_OFFSET(ALightShotProjectile, DamageType); }


#define LightShot_Source_LightShot_LightShotProjectile_h_12_PROLOG
#define LightShot_Source_LightShot_LightShotProjectile_h_15_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	LightShot_Source_LightShot_LightShotProjectile_h_15_PRIVATE_PROPERTY_OFFSET \
	LightShot_Source_LightShot_LightShotProjectile_h_15_SPARSE_DATA \
	LightShot_Source_LightShot_LightShotProjectile_h_15_RPC_WRAPPERS \
	LightShot_Source_LightShot_LightShotProjectile_h_15_INCLASS \
	LightShot_Source_LightShot_LightShotProjectile_h_15_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define LightShot_Source_LightShot_LightShotProjectile_h_15_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	LightShot_Source_LightShot_LightShotProjectile_h_15_PRIVATE_PROPERTY_OFFSET \
	LightShot_Source_LightShot_LightShotProjectile_h_15_SPARSE_DATA \
	LightShot_Source_LightShot_LightShotProjectile_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
	LightShot_Source_LightShot_LightShotProjectile_h_15_INCLASS_NO_PURE_DECLS \
	LightShot_Source_LightShot_LightShotProjectile_h_15_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> LIGHTSHOT_API UClass* StaticClass<class ALightShotProjectile>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID LightShot_Source_LightShot_LightShotProjectile_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
