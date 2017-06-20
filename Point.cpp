// Point.cpp: implementation of the Point class.
//
//////////////////////////////////////////////////////////////////////

#include "Point.h"
#include <windows.h>
#include <gl/gl.h>
#include <gl/glu.h>

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

Point::Point()
{
	this->id = -1;
	this->jointid = -1;
	this->normal.Fill(1.0f, 0.0f, 0.0f);
}

Point::~Point()
{
}

//////////////////////////////////////////////////////////////////////
// Purpose : 
// Input   : 
// Output  : 
//////////////////////////////////////////////////////////////////////
int Point::ID()
{
	return this->id;
}

//////////////////////////////////////////////////////////////////////
// Purpose : 
// Input   : 
// Output  : 
//////////////////////////////////////////////////////////////////////
void Point::ID(int id)
{
	this->id = id;
}

//////////////////////////////////////////////////////////////////////
// Purpose : 
// Input   : 
// Output  : 
//////////////////////////////////////////////////////////////////////
int Point::Joint()
{
	return this->jointid;
}

//////////////////////////////////////////////////////////////////////
// Purpose : 
// Input   : 
// Output  : 
//////////////////////////////////////////////////////////////////////
void Point::Joint(int id)
{
	this->jointid = id;
}

//////////////////////////////////////////////////////////////////////
// Purpose : 
// Input   : 
// Output  : 
//////////////////////////////////////////////////////////////////////
void Point::Move(float x, float y, float z)
{
	this->position.X += x;
	this->position.Y += y;
	this->position.Z += z;
}

//////////////////////////////////////////////////////////////////////
// Purpose : 
// Input   : 
// Output  : 
//////////////////////////////////////////////////////////////////////
void Point::Set(float x, float y, float z)
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
void Point::Render()
{
	::glNormal3f(this->normal.X, this->normal.Y, this->normal.Z);
	::glVertex3f(this->position.X, this->position.Y, this->position.Z);
}

//////////////////////////////////////////////////////////////////////
// Purpose : 
// Input   : 
// Output  : 
//////////////////////////////////////////////////////////////////////
Vector& Point::AnimPosition()
{
	return this->animPosition;
}

//////////////////////////////////////////////////////////////////////
// Purpose : 
// Input   : 
// Output  : 
//////////////////////////////////////////////////////////////////////
Vector& Point::AnimNormal()
{
	return this->animNormal;
}