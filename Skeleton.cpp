// Skeleton.cpp: implementation of the Skeleton class.
//
//////////////////////////////////////////////////////////////////////

#include "Skeleton.h"
#include <string>

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

Skeleton::Skeleton()
{
}

Skeleton::~Skeleton()
{
}

//////////////////////////////////////////////////////////////////////
// Purpose : 
// Input   : 
// Output  : 
//////////////////////////////////////////////////////////////////////
void Skeleton::ClearJoints()
{
	for (int i = 0; i < this->joints.Size(); i++)
		delete this->joints[i];

	this->joints.Clear();
}

//////////////////////////////////////////////////////////////////////
// Purpose : 
// Input   : 
// Output  : 
//////////////////////////////////////////////////////////////////////
void Skeleton::SetupJoints()
{
	for (int i = 0; i < this->joints.Size(); i++)
	{
		this->joints[i]->fromParent.MatrixRotateRad(this->joints[i]->rotation);
		this->joints[i]->fromParent.MatrixTranslate(this->joints[i]->position);

		if (this->joints[i]->parent > -1)
		{
			Joint* parent = GetJoint(GetJointIndex(this->joints[i]->parent));
			if (parent != 0)
			{
				this->joints[i]->fromZero = parent->fromZero * this->joints[i]->fromParent;
			}
			else
			{
				this->joints[i]->fromZero = this->joints[i]->fromParent;
			}
		}
	}
}

//////////////////////////////////////////////////////////////////////
// Purpose : 
// Input   : 
// Output  : 
//////////////////////////////////////////////////////////////////////
int Skeleton::AddJoint(Joint* joint)
{
	if (this->joints.Size() > 0)
		joint->ID(this->joints[this->joints.Size()-1]->ID() + 1);
	else
		joint->ID(0);

	this->joints.Add(joint);

	return joint->ID();
}

//////////////////////////////////////////////////////////////////////
// Purpose : 
// Input   : 
// Output  : 
//////////////////////////////////////////////////////////////////////
bool Skeleton::RemoveJoint(int id)
{
	int i = GetJointIndex(id);
	
	if (i > -1)
		this->joints.Remove(i);

	return false;
}

//////////////////////////////////////////////////////////////////////
// Purpose : 
// Input   : 
// Output  : 
//////////////////////////////////////////////////////////////////////
int Skeleton::GetJointIndex(int id)
{
	for (int i = 0; i < this->joints.Size(); i++)
	{
		if (this->joints[i]->ID(), id)
		{
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
int Skeleton::GetJointCount()
{
	return this->joints.Size();
}

//////////////////////////////////////////////////////////////////////
// Purpose : 
// Input   : 
// Output  : 
//////////////////////////////////////////////////////////////////////
Joint* Skeleton::GetJoint(int index)
{
	return this->joints[index];
}
