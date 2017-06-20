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
    MeshGroup(const char* name);
	virtual ~MeshGroup();

    const char* Name();
    void Name(const char* name);

	void AddMesh(Mesh* mesh);
    bool RemoveMesh(const char* mesh);
    Mesh* GetMesh(const char* mesh);
    int GetMeshIndex(const char* mesh);

	int GetMeshCount();
	Mesh* GetMesh(int index);

	void SetCurrentMesh(int index);
    void SetCurrentMesh(const char* mesh);
	Mesh* GetCurrentMesh();

};

#endif
