// Sequence.cpp: implementation of the Sequence class.
//
//////////////////////////////////////////////////////////////////////

#include "Sequence.h"
#include <string.h>

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

Sequence::Sequence(const char* name)
{
	Name(name);
}

Sequence::~Sequence()
{
}

//////////////////////////////////////////////////////////////////////
// Purpose : 
// Input   : 
// Output  : 
//////////////////////////////////////////////////////////////////////
const char* Sequence::Name()
{
	return this->name;
}

//////////////////////////////////////////////////////////////////////
// Purpose : 
// Input   : 
// Output  : 
//////////////////////////////////////////////////////////////////////
void Sequence::Name(const char* name)
{
	strcpy(this->name, name);
}

//////////////////////////////////////////////////////////////////////
// Purpose : 
// Input   : 
// Output  : 
//////////////////////////////////////////////////////////////////////
void Sequence::SetupMotions()
{
}

//////////////////////////////////////////////////////////////////////
// Purpose : 
// Input   : 
// Output  : 
//////////////////////////////////////////////////////////////////////
void Sequence::ClearMotions()
{
	for (int i = 0; i < this->motions.Size(); i++)
		delete this->motions[i];

	this->motions.Clear();
}

//////////////////////////////////////////////////////////////////////
// Purpose : 
// Input   : 
// Output  : 
//////////////////////////////////////////////////////////////////////
void Sequence::AddMotion(Motion* bone)
{
	this->motions.Add(bone);
}

//////////////////////////////////////////////////////////////////////
// Purpose : 
// Input   : 
// Output  : 
//////////////////////////////////////////////////////////////////////
bool Sequence::RemoveMotion(int index)
{
	return this->motions.Remove(index);
}

//////////////////////////////////////////////////////////////////////
// Purpose : 
// Input   : 
// Output  : 
//////////////////////////////////////////////////////////////////////
int Sequence::GetMotionCount()
{
	return this->motions.Size();
}

//////////////////////////////////////////////////////////////////////
// Purpose : 
// Input   : 
// Output  : 
//////////////////////////////////////////////////////////////////////
Motion* Sequence::GetMotion(int index)
{
	return this->motions[index];
}
