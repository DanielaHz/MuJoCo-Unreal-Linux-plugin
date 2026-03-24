// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "mujoco/mujoco.h"

#include "CoreMinimal.h"

#include "GameFramework/Actor.h"
#include "ProceduralMeshComponent.h"
// #include "Components/InstancedStaticMeshComponent.h"
#include "MuJoCoSimulation.generated.h"

/**
 * @struct BodyInfo
 * @brief Contains information about a body extracted form the MuJoCo Model and Data.
 *
 * @property std::string name - The name of the body.
 * @property int parent_id - The ID of the parent body.
 * @property mjtNum[3] pos - The position of the body as a 3D vector.
 * @property mjtNum[4] quat - The orientation of the body as a quaternion in MuJoCo format.
 * @property FQuat quat2 - The orientation of the body as an Unreal Engine quaternion.
 */
struct BodyInfo
{
	std::string name;
	int parent_id;
	mjtNum pos[3];
	mjtNum quat[4];
	FQuat quat2;
};

/**
 * @struct GeomInfo
 * @brief Contains information about a geometry extracted form the MuJoCo Model and Data.
 *
 * This structure stores various properties of a geometry object such as its name,
 * body ID, type, size, position, orientation, and color. It provides a way to manage
 * and adjust geometries within the MuJoCo simulation environment.
 *
 * @var std::string name
 * The name identifier of the geometry.
 *
 * @var int body_id
 * The ID of the body to which this geometry is attached.
 *
 * @var int type
 * The type of the geometry (e.g., box, sphere, etc.).
 *
 * @var mjtNum size[3]
 * The dimensions of the geometry along each axis.
 *
 * @var mjtNum pos[3]
 * The position of the geometry in 3D space.
 *
 * @var mjtNum posAdjust[3]
 * Additional position adjustment values, initialized to zero.
 *
 * @var mjtNum quat[4]
 * Quaternion representing the orientation of the geometry in MuJoCo format.
 *
 * @var FQuat quat2
 * Quaternion representing the orientation in Unreal Engine format.
 *
 * @var FLinearColor color
 * The color of the geometry in Unreal Engine format.
 */
struct GeomInfo
{
	std::string name;
	int body_id;
	int type;
	mjtNum size[3];
	mjtNum pos[3];
	mjtNum posAdjust[3];
	mjtNum quat[4];
	FQuat quat2;
	FLinearColor color;
	GeomInfo()
	{
		posAdjust[0] = 0;
		posAdjust[1] = 0;
		posAdjust[2] = 0;
	}
};

/**
 * @struct ModelInfo
 * @brief Represents information about a MuJoCo model.
 *
 * This structure contains collections of body and geometry MuJoCo information
 * that we might need inside the Unreal Engine.
 *
 * @member bodies A vector of BodyInfo structures representing the physical bodies in the model.
 * @member geoms A vector of GeomInfo structures representing the geometric shapes in the model.
 */
struct ModelInfo
{
	std::vector<BodyInfo> bodies;
	std::vector<GeomInfo> geoms;
};

/**
 * @brief Actor class that interfaces with MuJoCo physics simulation in Unreal Engine.
 *
 * This class provides functionality to load, simulate, and visualize MuJoCo physics models
 * within Unreal Engine. It handles the conversion between MuJoCo physics representation and
 * Unreal Engine's visual components, allowing for real-time physics simulation and visualization.
 *
 * The simulation can be controlled via Blueprint functions to start, pause, reset, and step through
 * the physics simulation. It also maps MuJoCo bodies and geometries to Unreal Engine components.
 *
 * @note Requires the MuJoCo physics library to be properly integrated with the project.
 */
/**
 * @class AMuJoCoSimulation
 * @brief Actor for MuJoCo physics simulation integration within Unreal Engine
 *
 * This class provides functionality to load, visualize, and simulate MuJoCo physics models.
 * It handles the conversion between MuJoCo's physics representation and Unreal Engine's
 * visual components, allowing for real-time physics simulation and visualization.
 */

// Protected variables
/** @brief MuJoCo simulation data */
// mjData* mData;

/** @brief MuJoCo model */
// mjModel* mModel;

/** @brief Current model information */
// ModelInfo _info;

/** @brief Initial model information */
// ModelInfo _infoStart;

/** @brief Flag indicating if simulation is currently running */
// bool bSimulationRunning=false;

// Public properties
/** @brief Maps MuJoCo body IDs to scene components */
// UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MuJoCo")
// TMap<int,USceneComponent*> BodyMap;

/** @brief Maps MuJoCo geometry IDs to static mesh components */
// UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MuJoCo")
// TMap<int,UStaticMeshComponent*> GeomMap1;

/** @brief Collection of all procedural meshes created for the simulation */
// UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MuJoCo")
// TArray<UProceduralMeshComponent*> ProceduralMeshes;

/** @brief Path to the MuJoCo XML model file */
// UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MuJoCo")
// FString XmlSourcePath;

/** @brief Collection of available static meshes for geometry visualization */
// UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MuJoCo")
// TMap<int, UStaticMesh*> MeshAssets;

/** @brief Default mesh to use when specific meshes are not provided */
// UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MuJoCo")
// UStaticMesh* defaultMesh;
UCLASS()
class MUJOCOUE_API AMuJoCoSimulation : public AActor
{
	GENERATED_BODY()

public:
	AMuJoCoSimulation();

protected:
	mjData *mData;
	mjModel *mModel;
	ModelInfo _info;
	ModelInfo _infoStart;
	bool bSimulationRunning = false;

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MuJoCo")
	TMap<int, USceneComponent *> BodyMap;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MuJoCo")
	TMap<int, UStaticMeshComponent *> GeomMap1;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MuJoCo")
	TMap<int, UProceduralMeshComponent *> GeomMap2;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MuJoCo")
	TArray<UProceduralMeshComponent *> ProceduralMeshes;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MuJoCo")
	FString XmlSourcePath;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MuJoCo")
	TMap<int, UStaticMesh *> MeshAssets;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MuJoCo")
	UStaticMesh *defaultMesh;

protected:
	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

	/**
	 * Simulate MuJoCo physics for a given time step.
	 * Advances the MuJoCo physics simulation by the specified delta time.
	 *
	 * @param DeltaTime The time step in seconds to advance the simulation
	 */
	void SimulateMuJoCo(float DeltaTime);

	/**
	 * @brief Extracts current state information from the MuJoCo simulation
	 *
	 * This function populates the provided ModelInfo structure with the current
	 * body and geometry data from the active MuJoCo simulation, including positions,
	 * orientations, and other relevant properties.
	 *
	 * @param modelInfo Reference to a ModelInfo structure to be filled with current simulation state
	 */
	void ExtractCurrentState(ModelInfo &modelInfo);

	/**
	 * @brief Updates the visual representation to match the current simulation state
	 *
	 * This function takes the current model info containing body and geometry data from
	 * the MuJoCo simulation and updates the corresponding Unreal Engine components to
	 * reflect the current state. It updates positions, rotations, and other visual properties
	 * of bodies and geometries in the scene.
	 *
	 * @param Info Reference to a ModelInfo structure containing the current simulation state
	 */
	void UpdateSimulationView(const ModelInfo &Info);

	/**
	 * @brief Generates mesh components for all geometries in the model
	 *
	 * This function creates and initializes appropriate mesh components (either static or procedural)
	 * for each geometry in the provided ModelInfo. It handles different geometry types from MuJoCo
	 * (spheres, capsules, boxes, etc.) and creates corresponding visual representations in Unreal Engine.
	 *
	 * @param modelInfo Reference to the ModelInfo structure containing geometry information
	 */
	void GenerateMeshes(ModelInfo &modelInfo);

	/**
	 * @brief Converts custom MuJoCo mesh geometries to procedural meshes in Unreal Engine
	 *
	 * This function extracts mesh data from the MuJoCo model for geometries that are not basic shapes
	 * (like spheres, boxes, etc.) and creates corresponding procedural mesh components in Unreal Engine.
	 * It reads vertex positions, normals, face indices, and other mesh properties from the MuJoCo model
	 * and creates equivalent mesh representations that can be rendered in the Unreal Engine scene.
	 *
	 * @param mjModel Pointer to the MuJoCo model containing the mesh data to extract
	 * @param  UObject* Outer Reference to owner of the procedural mesh components
	 */
	void ConvertMuJoCoModelToProceduralMeshes(const mjModel *mjModel, UObject *Outer);

	/**
	 * Sets the color of a static mesh component.
	 *
	 * @param StaticMeshComponent The static mesh component to update
	 * @param Color The new linear color to apply to the mesh
	 */
	void SetMeshColor(UStaticMeshComponent *StaticMeshComponent, FLinearColor Color);

	/**
	 * used for Debugging toprintout some properties
	 **/

	void LogInfo();

public:
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable, Category = "MuJoCo")
	bool LoadModel(FString Xml);

	UFUNCTION(BlueprintCallable, Category = "MuJoCo")
	void StartSimulation();

	UFUNCTION(BlueprintCallable, Category = "MuJoCo")
	void PauseSimulation();

	UFUNCTION(BlueprintCallable, Category = "MuJoCo")
	void ResetSimulation();

	UFUNCTION(BlueprintCallable, Category = "MuJoCo")
	void StepSimulation();

	UFUNCTION(BlueprintCallable, Category = "MuJoCo")
	void SetControl(int Id, float Value);
};
