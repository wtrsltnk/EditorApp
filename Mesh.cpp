// Mesh.cpp: implementation of the Mesh class.
//
//////////////////////////////////////////////////////////////////////

#include "Mesh.h"
#include <windows.h>
#include <gl/gl.h>
#include <gl/glu.h>
#include <string>
#include "Engine.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

Mesh::Mesh(const char* name)
{
	Name(name);
}

Mesh::~Mesh()
{
}

//////////////////////////////////////////////////////////////////////
// Purpose : 
// Input   : 
// Output  : 
//////////////////////////////////////////////////////////////////////
const char* Mesh::Name()
{
	return this->name;
}

//////////////////////////////////////////////////////////////////////
// Purpose : 
// Input   : 
// Output  : 
//////////////////////////////////////////////////////////////////////
void Mesh::Name(const char* name)
{
	strcpy(this->name, name);
}

//////////////////////////////////////////////////////////////////////
// Purpose : 
// Input   : 
// Output  : 
//////////////////////////////////////////////////////////////////////
void Mesh::Render(RenderArgs* args)
{
	for (int i = 0; i < this->triangles.Size(); i++)
	{
		Triangle* tri = this->triangles[i];

		if (tri)
		{
			Vertex* v0 = GetVertex(tri->vertexIndexes[0]);
			Vertex* v1 = GetVertex(tri->vertexIndexes[1]);
			Vertex* v2 = GetVertex(tri->vertexIndexes[2]);

			if (v0 && v1 && v2)
			{
				Material* m = GetMaterial(tri->material);

				if (m && this->selectionState > 0)
				{
					m->Use();
				}

				Point* p0 = GetPoint(v0->pointid);
				Point* p1 = GetPoint(v1->pointid);
				Point* p2 = GetPoint(v2->pointid);

				if (p0 && p1 && p2)
				{
					tri->Begin();
					v0->Prepare(); p0->Render();
					v1->Prepare(); p1->Render();
					v2->Prepare(); p2->Render();
					tri->End();
				}
			}
		}
	}
}

//////////////////////////////////////////////////////////////////////
// Purpose : 
// Input   : 
// Output  : 
//////////////////////////////////////////////////////////////////////
void Mesh::Select(SelectionArgs* args)
{
	glLoadName((LONG)this);
	Render(args->RenderArguments());
}

//////////////////////////////////////////////////////////////////////
// Purpose : 
// Input   : 
// Output  : 
//////////////////////////////////////////////////////////////////////
void Mesh::ClearMaterials()
{
	for (int i = 0; i < this->materials.Size(); i++)
	{
		delete this->materials[i];
	}
	this->materials.Clear();
}

//////////////////////////////////////////////////////////////////////
// Purpose : 
// Input   : 
// Output  : 
//////////////////////////////////////////////////////////////////////
void Mesh::ClearTriangles()
{
	for (int i = 0; i < this->triangles.Size(); i++)
	{
		delete this->triangles[i];
	}
	this->triangles.Clear();
}

//////////////////////////////////////////////////////////////////////
// Purpose : 
// Input   : 
// Output  : 
//////////////////////////////////////////////////////////////////////
void Mesh::ClearVertices()
{
	for (int i = 0; i < this->vertices.Size(); i++)
	{
		delete this->vertices[i];
	}
	this->vertices.Clear();
}

//////////////////////////////////////////////////////////////////////
// Purpose : 
// Input   : 
// Output  : 
//////////////////////////////////////////////////////////////////////
void Mesh::ClearPoints()
{
	for (int i = 0; i < this->points.Size(); i++)
	{
		delete this->points[i];
	}
	this->points.Clear();
}

//////////////////////////////////////////////////////////////////////
// Purpose : 
// Input   : 
// Output  : 
//////////////////////////////////////////////////////////////////////
int Mesh::GetMaterialIndex(int id)
{
	if (id >= 0 && this->materials.Size() > 0)
	{
		int start = id;

		if (id >= this->materials.Size())
			start = this->materials.Size() - 1;

		for (int i = start; i >= 0; i--)
		{
			if (this->materials[i]->id == id)
				return i;
		}
	}
	return -1;
}

//////////////////////////////////////////////////////////////////////
// Purpose : 
// Input   : 
// Output  : 
//////////////////////////////////////////////////////////////////////
int Mesh::GetTriangleIndex(int id)
{
	if (id >= 0 && this->triangles.Size() > 0)
	{
		int start = id;

		if (id >= this->triangles.Size())
			start = this->triangles.Size() - 1;

		for (int i = start; i >= 0; i--)
		{
			if (this->triangles[i]->id == id)
				return i;
		}
	}
	return -1;
}


//////////////////////////////////////////////////////////////////////
// Purpose : 
// Input   : 
// Output  : 
//////////////////////////////////////////////////////////////////////
int Mesh::GetVertexIndex(int id)
{
	if (id >= 0 && this->vertices.Size() > 0)
	{
		int start = id;

		if (id >= this->vertices.Size())
			start = this->vertices.Size() - 1;

		for (int i = start; i >= 0; i--)
		{
			if (this->vertices[i]->id == id)
				return i;
		}
	}
	return -1;
}


//////////////////////////////////////////////////////////////////////
// Purpose : 
// Input   : 
// Output  : 
//////////////////////////////////////////////////////////////////////
int Mesh::GetPointIndex(int id)
{
	if (id >= 0 && this->points.Size() > 0)
	{
		int start = id;

		if (id >= this->points.Size())
			start = this->points.Size() - 1;

		for (int i = start; i >= 0; i--)
		{
			if (this->points[i]->id == id)
				return i;
		}
	}
	return -1;
}

//////////////////////////////////////////////////////////////////////
// Purpose : 
// Input   : 
// Output  : 
//////////////////////////////////////////////////////////////////////
Collection <Material*> &Mesh::GetMaterials()
{
	return this->materials;
}

//////////////////////////////////////////////////////////////////////
// Purpose : 
// Input   : 
// Output  : 
//////////////////////////////////////////////////////////////////////
Collection <Triangle*> &Mesh::GetTriangles()
{
	return this->triangles;
}

//////////////////////////////////////////////////////////////////////
// Purpose : 
// Input   : 
// Output  : 
//////////////////////////////////////////////////////////////////////
Collection <Vertex*> &Mesh::GetVertices()
{
	return this->vertices;
}

//////////////////////////////////////////////////////////////////////
// Purpose : 
// Input   : 
// Output  : 
//////////////////////////////////////////////////////////////////////
Collection <Point*> &Mesh::GetPoints()
{
	return this->points;
}

//////////////////////////////////////////////////////////////////////
// Purpose : 
// Input   : 
// Output  : 
//////////////////////////////////////////////////////////////////////
Material* Mesh::GetMaterial(int id)
{
	int index = GetMaterialIndex(id);
	if (index >= 0)
	{
		return this->materials[index];
	}
	return 0;
}

//////////////////////////////////////////////////////////////////////
// Purpose : 
// Input   : 
// Output  : 
//////////////////////////////////////////////////////////////////////
Triangle* Mesh::GetTriangle(int id)
{
	int index = GetTriangleIndex(id);
	if (index >= 0)
	{
		return this->triangles[index];
	}
	return 0;
}

//////////////////////////////////////////////////////////////////////
// Purpose : 
// Input   : 
// Output  : 
//////////////////////////////////////////////////////////////////////
Vertex* Mesh::GetVertex(int id)
{
	int index = GetVertexIndex(id);
	if (index >= 0)
	{
		return this->vertices[index];
	}
	return 0;
}

//////////////////////////////////////////////////////////////////////
// Purpose : 
// Input   : 
// Output  : 
//////////////////////////////////////////////////////////////////////
Point* Mesh::GetPoint(int id)
{
	int index = GetPointIndex(id);
	if (index >= 0)
	{
		return this->points[index];
	}
	return 0;
}

//////////////////////////////////////////////////////////////////////
// Purpose : 
// Input   : 
// Output  : 
//////////////////////////////////////////////////////////////////////
int Mesh::AddMaterial()
{
	Material* n = new Material();
	int newid = -1;

	if (this->materials.Size() > 0)
	{
		newid = this->materials[this->materials.Size()- 1]->ID();
	}

	n->id = newid + 1;
	if (this->materials.Add(n) != -1)
		return newid;

	return -1;
}

//////////////////////////////////////////////////////////////////////
// Purpose : 
// Input   : 
// Output  : 
//////////////////////////////////////////////////////////////////////
int Mesh::AddTriangle(int v1, int v2, int v3, int material)
{
	Triangle* n = new Triangle();
	int newid = -1;

	if (this->triangles.Size() > 0)
	{
		newid = this->triangles[this->triangles.Size()- 1]->ID();
	}

	n->id = newid + 1;
	n->SetIndices(v1, v2, v3);
	n->material = material;
	if (this->triangles.Add(n) != -1)
		return newid;

	return -1;
}

//////////////////////////////////////////////////////////////////////
// Purpose : 
// Input   : 
// Output  : 
//////////////////////////////////////////////////////////////////////
int Mesh::AddVertex(int point)
{
	Vertex* n = new Vertex();
	int newid = -1;

	if (this->vertices.Size() > 0)
	{
		newid = this->vertices[this->vertices.Size()- 1]->ID();
	}

	n->id = newid + 1;
	n->pointid = point;
	if (this->vertices.Add(n) != -1)
		return newid;

	return -1;
}

//////////////////////////////////////////////////////////////////////
// Purpose : 
// Input   : 
// Output  : 
//////////////////////////////////////////////////////////////////////
int Mesh::AddPoint(float x, float y, float z)
{
	Point* n = new Point();
	int newid = -1;

	if (this->points.Size() > 0)
	{
		newid = this->points[this->points.Size()- 1]->ID();
	}

	n->id = newid + 1;
	n->Set(x, y, z);
	if (this->points.Add(n) != -1)
		return newid;

	return -1;
}	

//////////////////////////////////////////////////////////////////////
// Purpose : 
// Input   : 
// Output  : 
//////////////////////////////////////////////////////////////////////
bool Mesh::RemoveMaterial(int id)
{
	return this->materials.Remove(GetMaterialIndex(id));
}

//////////////////////////////////////////////////////////////////////
// Purpose : 
// Input   : 
// Output  : 
//////////////////////////////////////////////////////////////////////
bool Mesh::RemoveTriangle(int id)
{
	return this->materials.Remove(GetTriangleIndex(id));
}

//////////////////////////////////////////////////////////////////////
// Purpose : 
// Input   : 
// Output  : 
//////////////////////////////////////////////////////////////////////
bool Mesh::RemoveVertex(int id)
{
	return this->materials.Remove(GetVertexIndex(id));
}

//////////////////////////////////////////////////////////////////////
// Purpose : 
// Input   : 
// Output  : 
//////////////////////////////////////////////////////////////////////
bool Mesh::RemovePoint(int id)
{
	return this->materials.Remove(GetPointIndex(id));
}
