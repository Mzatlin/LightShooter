// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class LightShot : ModuleRules
{
	public LightShot(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore","CableComponent" });
	}
}
