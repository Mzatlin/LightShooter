// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef LIGHTSHOT_LightShotPawn_generated_h
#error "LightShotPawn.generated.h already included, missing '#pragma once' in LightShotPawn.h"
#endif
#define LIGHTSHOT_LightShotPawn_generated_h

#define LightShot_Source_LightShot_LightShotPawn_h_12_SPARSE_DATA
#define LightShot_Source_LightShot_LightShotPawn_h_12_RPC_WRAPPERS
#define LightShot_Source_LightShot_LightShotPawn_h_12_RPC_WRAPPERS_NO_PURE_DECLS
#define LightShot_Source_LightShot_LightShotPawn_h_12_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesALightShotPawn(); \
	friend struct Z_Construct_UClass_ALightShotPawn_Statics; \
public: \
	DECLARE_CLASS(ALightShotPawn, APawn, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/LightShot"), NO_API) \
	DECLARE_SERIALIZER(ALightShotPawn)


#define LightShot_Source_LightShot_LightShotPawn_h_12_INCLASS \
private: \
	static void StaticRegisterNativesALightShotPawn(); \
	friend struct Z_Construct_UClass_ALightShotPawn_Statics; \
public: \
	DECLARE_CLASS(ALightShotPawn, APawn, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/LightShot"), NO_API) \
	DECLARE_SERIALIZER(ALightShotPawn)


#define LightShot_Source_LightShot_LightShotPawn_h_12_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ALightShotPawn(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ALightShotPawn) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ALightShotPawn); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ALightShotPawn); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ALightShotPawn(ALightShotPawn&&); \
	NO_API ALightShotPawn(const ALightShotPawn&); \
public:


#define LightShot_Source_LightShot_LightShotPawn_h_12_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ALightShotPawn(ALightShotPawn&&); \
	NO_API ALightShotPawn(const ALightShotPawn&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ALightShotPawn); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ALightShotPawn); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(ALightShotPawn)


#define LightShot_Source_LightShot_LightShotPawn_h_12_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__ShipMeshComponent() { return STRUCT_OFFSET(ALightShotPawn, ShipMeshComponent); } \
	FORCEINLINE static uint32 __PPO__CameraComponent() { return STRUCT_OFFSET(ALightShotPawn, CameraComponent); } \
	FORCEINLINE static uint32 __PPO__CameraBoom() { return STRUCT_OFFSET(ALightShotPawn, CameraBoom); }


#define LightShot_Source_LightShot_LightShotPawn_h_9_PROLOG
#define LightShot_Source_LightShot_LightShotPawn_h_12_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	LightShot_Source_LightShot_LightShotPawn_h_12_PRIVATE_PROPERTY_OFFSET \
	LightShot_Source_LightShot_LightShotPawn_h_12_SPARSE_DATA \
	LightShot_Source_LightShot_LightShotPawn_h_12_RPC_WRAPPERS \
	LightShot_Source_LightShot_LightShotPawn_h_12_INCLASS \
	LightShot_Source_LightShot_LightShotPawn_h_12_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define LightShot_Source_LightShot_LightShotPawn_h_12_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	LightShot_Source_LightShot_LightShotPawn_h_12_PRIVATE_PROPERTY_OFFSET \
	LightShot_Source_LightShot_LightShotPawn_h_12_SPARSE_DATA \
	LightShot_Source_LightShot_LightShotPawn_h_12_RPC_WRAPPERS_NO_PURE_DECLS \
	LightShot_Source_LightShot_LightShotPawn_h_12_INCLASS_NO_PURE_DECLS \
	LightShot_Source_LightShot_LightShotPawn_h_12_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> LIGHTSHOT_API UClass* StaticClass<class ALightShotPawn>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID LightShot_Source_LightShot_LightShotPawn_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
