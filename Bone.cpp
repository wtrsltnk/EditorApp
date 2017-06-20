// Bone.cpp: implementation of the Bone class.
//
//////////////////////////////////////////////////////////////////////

#include "Bone.h"
#include <string.h>

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

Bone::Bone(int id)
{
	ID(id);
	Parent(-1);
}

Bone::Bone(int id, int parent)
{
	ID(id);
	Parent(parent);
}

Bone::~Bone()
{
}

//////////////////////////////////////////////////////////////////////
// Purpose : 
// Input   : 
// Output  : 
//////////////////////////////////////////////////////////////////////
int Bone::ID()
{
	return this->id;
}

//////////////////////////////////////////////////////////////////////
// Purpose : 
// Input   : 
// Output  : 
//////////////////////////////////////////////////////////////////////
void Bone::ID(int id)
{
	this->id = id;
}

//////////////////////////////////////////////////////////////////////
// Purpose : 
// Input   : 
// Output  : 
//////////////////////////////////////////////////////////////////////
int Bone::Parent()
{
	return this->parent;
}

//////////////////////////////////////////////////////////////////////
// Purpose : 
// Input   : 
// Output  : 
//////////////////////////////////////////////////////////////////////
void Bone::Parent(int parent)
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
const char* Bone::Name()
{
	return this->name;
}

//////////////////////////////////////////////////////////////////////
// Purpose : 
// Input   : 
// Output  : 
//////////////////////////////////////////////////////////////////////
void Bone::Name(const char* name)
{
	strcpy(this->name, name);
}
