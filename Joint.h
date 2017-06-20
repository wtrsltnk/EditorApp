// Joint.h: interface for the Joint class.
//
//////////////////////////////////////////////////////////////////////

#ifndef JOINT_H
#define JOINT_H

#include "Mathlib.h"
#include "Collection.h"
#include "KeyFrame.h"

class Joint  
{
friend class Skeleton;

private:
	int id;
	char name[128];
	int parent;

	Vector position;
	Vector rotation;

	Matrix fromZero;
	Matrix fromParent;

public:
	Joint(int id);
	Joint(int id, int parent);
	virtual ~Joint();

	void SetupJoint();

	int ID();
	void ID(int id);

	int Parent();
	void Parent(int parent);

    const char* Name();
    void Name(const char* name);

	void Position(float position[3]);
	void Position(float x, float y, float z);

	void Rotation(float rotation[3]);
	void Rotation(float x, float y, float z);

	Matrix& FromZero();
	Matrix& FromParent();

};

#endif
