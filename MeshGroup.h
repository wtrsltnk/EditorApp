// MeshGroup.h: interface for the MeshGroup class.
//
//////////////////////////////////////////////////////////////////////

#ifndef MESHGROUP_H
#define MESHGROUP_H

#include "IMeshGroup.h"
#include "Collection.h"
#include "Mesh.h"

class MeshGroup : public IMeshGroup
{
private:
	char name[128];
	Collection <Mesh*> meshes;
	Mesh* currentMesh;

	void ClearMeshes();
public:
	MeshGroup(char* name);
	virtual ~MeshGroup();

	char* Name();
	void Name(char* name);

	void AddMesh(Mesh* mesh);
	bool RemoveMesh(char* mesh);
	Mesh* GetMesh(char* mesh);
	int GetMeshIndex(char* mesh);

	int GetMeshCount();
	Mesh* GetMesh(int index);

	void SetCurrentMesh(int index);
	void SetCurrentMesh(char* mesh);
	Mesh* GetCurrentMesh();

};

#endif
