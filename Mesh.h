// Mesh.h: interface for the Mesh class.
//
//////////////////////////////////////////////////////////////////////

#ifndef MESH_H
#define MESH_H

#include "IMesh.h"
#include "SelectionObject.h"
#include "Material.h"
#include "Triangle.h"
#include "Vertex.h"
#include "Point.h"
#include "Collection.h"

class Mesh : public SelectionObject, public IMesh
{
private:
	char name[128];

	Collection <Material*> materials;
	Collection <Triangle*> triangles;
	Collection <Vertex*> vertices;
	Collection <Point*> points;

	int GetMaterialIndex(int id);
	int GetTriangleIndex(int id);
	int GetVertexIndex(int id);
	int GetPointIndex(int id);

	void ClearMaterials();
	void ClearTriangles();
	void ClearVertices();
	void ClearPoints();

public:
	Mesh(char* name);
	virtual ~Mesh();

	char* Name();
	void Name(char* name);

	void Render(RenderArgs* args);
	
	void Select(SelectionArgs* args);

	Collection <Material*> &GetMaterials();
	Collection <Triangle*> &GetTriangles();
	Collection <Vertex*> &GetVertices();
	Collection <Point*> &GetPoints();

	Material* GetMaterial(int id);
	Triangle* GetTriangle(int id);
	Vertex* GetVertex(int id);
	Point* GetPoint(int id);

	int AddMaterial();
	int AddTriangle(int v1, int v2, int v3, int material);
	int AddVertex(int point);
	int AddPoint(float x, float y, float z);
	
	bool RemoveMaterial(int id);
	bool RemoveTriangle(int id);
	bool RemoveVertex(int id);
	bool RemovePoint(int id);

};

#endif
