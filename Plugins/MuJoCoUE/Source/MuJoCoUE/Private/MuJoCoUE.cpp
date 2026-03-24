// Copyright Epic Games, Inc. All Rights Reserved.

#include "MuJoCoUE.h"

#include "Interfaces/IPluginManager.h"

#define LOCTEXT_NAMESPACE "FMuJoCoUEModule"

void FMuJoCoUEModule::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module
	FString DLLPath = IPluginManager::Get().FindPlugin("MuJoCoUE")->GetBaseDir();

	DLLPath = DLLPath + TEXT("/Binaries/mujoco.dll");

	DLLHandle = FPlatformProcess::GetDllHandle(*DLLPath);
	// IModularFeatures::Get().RegisterModularFeature(IInputDeviceModule::GetModularFeatureName(), this);
}

void FMuJoCoUEModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
	FPlatformProcess::FreeDllHandle(DLLHandle);
}

#undef LOCTEXT_NAMESPACE

IMPLEMENT_MODULE(FMuJoCoUEModule, MuJoCoUE)