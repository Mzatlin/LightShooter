// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef LIGHTSHOT_MoveActor_generated_h
#error "MoveActor.generated.h already included, missing '#pragma once' in MoveActor.h"
#endif
#define LIGHTSHOT_MoveActor_generated_h

#define LightShot_Source_LightShot_MoveActor_h_13_SPARSE_DATA
#define LightShot_Source_LightShot_MoveActor_h_13_RPC_WRAPPERS
#define LightShot_Source_LightShot_MoveActor_h_13_RPC_WRAPPERS_NO_PURE_DECLS
#define LightShot_Source_LightShot_MoveActor_h_13_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUMoveActor(); \
	friend struct Z_Construct_UClass_UMoveActor_Statics; \
public: \
	DECLARE_CLASS(UMoveActor, UActorComponent, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/LightShot"), NO_API) \
	DECLARE_SERIALIZER(UMoveActor)


#define LightShot_Source_LightShot_MoveActor_h_13_INCLASS \
private: \
	static void StaticRegisterNativesUMoveActor(); \
	friend struct Z_Construct_UClass_UMoveActor_Statics; \
public: \
	DECLARE_CLASS(UMoveActor, UActorComponent, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/LightShot"), NO_API) \
	DECLARE_SERIALIZER(UMoveActor)


#define LightShot_Source_LightShot_MoveActor_h_13_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UMoveActor(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UMoveActor) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UMoveActor); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UMoveActor); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UMoveActor(UMoveActor&&); \
	NO_API UMoveActor(const UMoveActor&); \
public:


#define LightShot_Source_LightShot_MoveActor_h_13_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UMoveActor(UMoveActor&&); \
	NO_API UMoveActor(const UMoveActor&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UMoveActor); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UMoveActor); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UMoveActor)


#define LightShot_Source_LightShot_MoveActor_h_13_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__MoveSpeed() { return STRUCT_OFFSET(UMoveActor, MoveSpeed); }


#define LightShot_Source_LightShot_MoveActor_h_10_PROLOG
#define LightShot_Source_LightShot_MoveActor_h_13_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	LightShot_Source_LightShot_MoveActor_h_13_PRIVATE_PROPERTY_OFFSET \
	LightShot_Source_LightShot_MoveActor_h_13_SPARSE_DATA \
	LightShot_Source_LightShot_MoveActor_h_13_RPC_WRAPPERS \
	LightShot_Source_LightShot_MoveActor_h_13_INCLASS \
	LightShot_Source_LightShot_MoveActor_h_13_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define LightShot_Source_LightShot_MoveActor_h_13_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	LightShot_Source_LightShot_MoveActor_h_13_PRIVATE_PROPERTY_OFFSET \
	LightShot_Source_LightShot_MoveActor_h_13_SPARSE_DATA \
	LightShot_Source_LightShot_MoveActor_h_13_RPC_WRAPPERS_NO_PURE_DECLS \
	LightShot_Source_LightShot_MoveActor_h_13_INCLASS_NO_PURE_DECLS \
	LightShot_Source_LightShot_MoveActor_h_13_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> LIGHTSHOT_API UClass* StaticClass<class UMoveActor>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID LightShot_Source_LightShot_MoveActor_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
