// Copyright Epic Games, Inc. All Rights Reserved.
using System;
using System.IO;
using UnrealBuildTool;

public class MuJoCoUE : ModuleRules
{
	public MuJoCoUE(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicIncludePaths.AddRange(
			new string[] {
				// ... add public include paths required here ...
			}
			);


		PrivateIncludePaths.AddRange(
			new string[] {
				// ... add other private include paths required here ...
			}
			);


		PublicDependencyModuleNames.AddRange(
			new string[]
			{
				"Core", "ProceduralMeshComponent",
				// ... add other public dependencies that you statically link with here ...
			}
			);


		PrivateDependencyModuleNames.AddRange(
			new string[]
			{
				"CoreUObject",
				"Engine",
				"Slate",
				"SlateCore",
				"Projects", 
				"ProceduralMeshComponent",
				// ... add private dependencies that you statically link with here ...	
			}
			);


		DynamicallyLoadedModuleNames.AddRange(
			new string[]
			{
				// ... add any modules that your module loads dynamically here ...
			}
			);


		string MUJOCO_ROOT = Path.GetFullPath(Path.Combine(ModuleDirectory, "../../Source/mujoco/"));
		string MUJOCO_INCLUDE_PATH = Path.Combine(MUJOCO_ROOT, "include/");
		PublicIncludePaths.Add(MUJOCO_INCLUDE_PATH);

		if (Target.Platform == UnrealTargetPlatform.Linux)
		{
			string MujocoLibDir = Path.Combine(MUJOCO_ROOT, "lib");
			string MujocoBinDir = Path.Combine(MUJOCO_ROOT, "bin");

			// Link against libmujoco.so
			PublicAdditionalLibraries.Add(Path.Combine(MujocoLibDir, "libmujoco.so"));

			// Ensure the .so is packaged with the plugin
			RuntimeDependencies.Add(Path.Combine(MujocoBinDir, "libmujoco.so"));

			// Add runtime library search path
			PublicRuntimeLibraryPaths.Add(MujocoBinDir);
		}
		else if (Target.Platform == UnrealTargetPlatform.Win64)
		{
			string UE4PlatformPrefix = "Win64";

			string MujocoBinDirectory = Path.Combine(MUJOCO_ROOT, "lib");
			string UE4BinDirectory = Path.Combine(PluginDirectory, "Binaries", UE4PlatformPrefix);

			PublicAdditionalLibraries.Add(Path.Combine(MujocoBinDirectory, "mujoco.lib"));
			string DLLTargetPath = Path.Combine(UE4BinDirectory, "mujoco.dll");
			string DLLSourcePath = Path.Combine(Path.Combine(MUJOCO_ROOT, "bin"), "mujoco.dll");

			if (!File.Exists(DLLTargetPath))
			{
				File.Copy(DLLSourcePath, DLLTargetPath, false);
			}

			RuntimeDependencies.Add(DLLTargetPath);
			PublicDelayLoadDLLs.Add("mujoco.dll");
		}
	}
}
