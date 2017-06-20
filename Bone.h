// Bone.h: interface for the Bone class.
//
//////////////////////////////////////////////////////////////////////

#ifndef BONE_H
#define BONE_H

#include "Mathlib.h"

class Bone  
{
private:
	int id;
	char name[128];
	int parent;

	Vector position;
	Vector rotation;

	Matrix fromZero;
	Matrix fromParent;

public:
	Bone(int id);
	Bone(int id, int parent);
	virtual ~Bone();

	int ID();
	void ID(int id);

	int Parent();
	void Parent(int parent);

	char* Name();
	void Name(char* name);

};

#endif
