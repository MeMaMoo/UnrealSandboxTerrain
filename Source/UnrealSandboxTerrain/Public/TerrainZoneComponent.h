// Copyright blackw 2015-2020

#pragma once

#include "EngineMinimal.h"
#include "SandboxTerrainMeshComponent.h"
#include "SandboxTerrainCollisionComponent.h"
#include "Components/HierarchicalInstancedStaticMeshComponent.h"
#include "TerrainZoneComponent.generated.h"


class ASandboxTerrainController;

/**
*
*/
UCLASS()
class UNREALSANDBOXTERRAIN_API UTerrainZoneComponent : public USceneComponent
{
	GENERATED_UCLASS_BODY()

public:

	UPROPERTY()
	USandboxTerrainMeshComponent* MainTerrainMesh;

	UPROPERTY()
	USandboxTerrainCollisionComponent* CollisionMesh;

	UPROPERTY()
	TMap<uint32, UHierarchicalInstancedStaticMeshComponent*> InstancedMeshMap;

public:

	ASandboxTerrainController* GetTerrainController() {
		return (ASandboxTerrainController*)GetAttachmentRootActor();
	};

	void makeTerrain();

	TVoxelData* getVoxelData() { 
		return voxel_data; 
	};

	void setVoxelData(TVoxelData* vd) {
		this->voxel_data = vd; 
	};

	void applyTerrainMesh(std::shared_ptr<TMeshData> mesh_data_ptr);

	std::shared_ptr<TMeshData> generateMesh();

	void SerializeInstancedMeshes(FBufferArchive& binaryData);

	void SaveInstancedMeshesToFile();

	void LoadInstancedMeshesFromFile();

	void SpawnInstancedMesh(FTerrainInstancedMeshType& MeshType, FTransform& transform);

private:
	TVoxelData* voxel_data;
};