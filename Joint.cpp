// Joint.cpp: implementation of the Joint class.
//
//////////////////////////////////////////////////////////////////////

#include "Joint.h"
#include <string.h>

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

Joint::Joint(int id)
{
	ID(id);
	Parent(-1);
}

Joint::Joint(int id, int parent)
{
	ID(id);
	Parent(parent);
}

Joint::~Joint()
{
}

//////////////////////////////////////////////////////////////////////
// Purpose : 
// Input   : 
// Output  : 
//////////////////////////////////////////////////////////////////////
void Joint::SetupJoint()
{
}

//////////////////////////////////////////////////////////////////////
// Purpose : 
// Input   : 
// Output  : 
//////////////////////////////////////////////////////////////////////
int Joint::ID()
{
	return this->id;
}

//////////////////////////////////////////////////////////////////////
// Purpose : 
// Input   : 
// Output  : 
//////////////////////////////////////////////////////////////////////
void Joint::ID(int id)
{
	this->id = id;
}

//////////////////////////////////////////////////////////////////////
// Purpose : 
// Input   : 
// Output  : 
//////////////////////////////////////////////////////////////////////
int Joint::Parent()
{
	return this->parent;
}

//////////////////////////////////////////////////////////////////////
// Purpose : 
// Input   : 
// Output  : 
//////////////////////////////////////////////////////////////////////
void Joint::Parent(int parent)
{
	if (this->id > parent)
		this->parent = parent;
	else
		this->parent = -1;
}

//////////////////////////////////////////////////////////////////////
// Purpose : 
// Input   : 
// Output  : 
//////////////////////////////////////////////////////////////////////
const char* Joint::Name()
{
	return this->name;
}

//////////////////////////////////////////////////////////////////////
// Purpose : 
// Input   : 
// Output  : 
//////////////////////////////////////////////////////////////////////
void Joint::Name(const char* name)
{
	strcpy(this->name, name);
}

//////////////////////////////////////////////////////////////////////
// Purpose : 
// Input   : 
// Output  : 
//////////////////////////////////////////////////////////////////////
void Joint::Position(float position[3])
{
	position[0] = this->position.X;
	position[1] = this->position.Y;
	position[2] = this->position.Z;
}

//////////////////////////////////////////////////////////////////////
// Purpose : 
// Input   : 
// Output  : 
//////////////////////////////////////////////////////////////////////
void Joint::Position(float x, float y, float z)
{
	this->position.X = x;
	this->position.Y = y;
	this->position.Z = z;
}

//////////////////////////////////////////////////////////////////////
// Purpose : 
// Input   : 
// Output  : 
//////////////////////////////////////////////////////////////////////
void Joint::Rotation(float rotation[3])
{
	rotation[0] = this->rotation.X;
	rotation[1] = this->rotation.Y;
	rotation[2] = this->rotation.Z;
}

//////////////////////////////////////////////////////////////////////
// Purpose : 
// Input   : 
// Output  : 
//////////////////////////////////////////////////////////////////////
void Joint::Rotation(float x, float y, float z)
{
	this->rotation.X = x;
	this->rotation.Y = y;
	this->rotation.Z = z;
}

//////////////////////////////////////////////////////////////////////
// Purpose : 
// Input   : 
// Output  : 
//////////////////////////////////////////////////////////////////////
Matrix& Joint::FromZero()
{
	return this->fromZero;
}

//////////////////////////////////////////////////////////////////////
// Purpose : 
// Input   : 
// Output  : 
//////////////////////////////////////////////////////////////////////
Matrix& Joint::FromParent()
{
	return this->fromParent;
}
