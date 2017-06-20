// IModel.h: IModel interface.
//
//////////////////////////////////////////////////////////////////////

#ifndef IMODEL_H
#define IMODEL_H


class IModel
{
public:		virtual bool IsReady() = 0;
/*
public:		virtual bool AddBone(int id, int parentid, float position[3], float pan[3], float rot[3]) = 0;
public:		virtual bool AddSequence(char* name) = 0;
public:		virtual bool AddMeshGroup(char* name) = 0;
public:		virtual bool AddMesh(char* meshgroup, char* name) = 0;
public:		virtual bool AddPoint(char* meshgroup, char* mesh, int id, float position[3], float normal[3], int boneid) = 0;
public:		virtual bool AddVertex(char* meshgroup, char* mesh, int id, int pointid, float uv[2]) = 0;
public:		virtual bool AddTriangle(char* meshgroup, char* mesh, int id, int vertexindices[3], int material) = 0;
public:		virtual bool AddMaterial(char* meshgroup, char* mesh, int id) = 0;

public:		virtual int GetBoneCount() = 0;
public:		virtual int GetSequenceCount() = 0;
public:		virtual int GetMeshGroupCount() = 0;
public:		virtual int GetMeshCount() = 0;
public:		virtual int GetPointCount() = 0;
public:		virtual int GetVertexCount() = 0;
public:		virtual int GetTriangleCount() = 0;
public:		virtual int GetMaterialCount() = 0;

public:		virtual bool GetBone(int index, int* id, int* parentid, float position[3], float pan[3], float rot[3]) = 0;
public:		virtual bool GetSequence(int index, char name[128]) = 0;
public:		virtual bool GetMeshGroup(int index, char name[128]) = 0;
public:		virtual bool GetMesh(int index, int meshgroupindex, char name[128]) = 0;
public:		virtual bool GetPoint(int index, int meshgroupindex, char mesh[128], int* id, float position[3], float normal[3], int* boneid) = 0;
public:		virtual bool GetVertex(int index, int meshgroupindex, char mesh[128], int* id, int* pointid, float uv[2]) = 0;
public:		virtual bool GetTriangle(int index, int meshgroupindex, char mesh[128], int* id, int vertexindices[3], int* material) = 0;
public:		virtual bool GetMaterial(int index, int meshgroupindex, char mesh[128], int* id) = 0;
*/
};

#endif