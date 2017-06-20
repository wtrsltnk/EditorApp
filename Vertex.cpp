// Vertex.cpp: implementation of the Vertex class.
//
//////////////////////////////////////////////////////////////////////

#include "Vertex.h"
#include <windows.h>
#include <gl/gl.h>
#include <gl/glu.h>

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

Vertex::Vertex()
{
	this->id = -1;
	this->pointid = -1;
	this->uv[0] = 0.0f;
	this->uv[1] = 0.0f;
}

Vertex::~Vertex()
{
}

//////////////////////////////////////////////////////////////////////
// Purpose : 
// Input   : 
// Output  : 
//////////////////////////////////////////////////////////////////////
int Vertex::ID()
{
	return this->id;
}

//////////////////////////////////////////////////////////////////////
// Purpose : 
// Input   : 
// Output  : 
//////////////////////////////////////////////////////////////////////
void Vertex::ID(int id)
{
	this->id = id;
}

//////////////////////////////////////////////////////////////////////
// Purpose : 
// Input   : 
// Output  : 
//////////////////////////////////////////////////////////////////////
void Vertex::Prepare()
{
	::glTexCoord2f(this->uv[0], this->uv[0]);
}