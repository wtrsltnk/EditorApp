// Triangle.h: interface for the Triangle class.
//
//////////////////////////////////////////////////////////////////////

#ifndef TRIANGLE_H
#define TRIANGLE_H

class Triangle  
{
friend class Mesh;

private:
	int id;
	int vertexIndexes[3];
	int material;

	int ID();
	void ID(int id);

public:
	Triangle();
	virtual ~Triangle();

	void SetIndices(int v1, int v2, int v3);
	void SetMaterial(int material);
	
	void Begin();
	void End();

};

#endif
