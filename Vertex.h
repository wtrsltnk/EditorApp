// Vertex.h: interface for the Vertex class.
//
//////////////////////////////////////////////////////////////////////

#ifndef VERTEX_H
#define VERTEX_H

class Vertex  
{
friend class Mesh;

private:
	int id;
	int pointid;
	float uv[2];

	int ID();
	void ID(int id);

public:
	Vertex();
	virtual ~Vertex();

	void Prepare();

};

#endif
