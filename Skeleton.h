// Skeleton.h: interface for the Skeleton class.
//
//////////////////////////////////////////////////////////////////////

#ifndef SKELETON_H
#define SKELETON_H

#include "ISkeleton.h"
#include "Collection.h"
#include "Joint.h"

class Skeleton : public ISkeleton
{
private:
	Collection <Joint*> joints;

	void ClearJoints();
public:
	Skeleton();
	virtual ~Skeleton();

	void SetupJoints();

	int AddJoint(Joint* joint);
	bool RemoveJoint(int id);
	int GetJointIndex(int id);

	int GetJointCount();
	Joint* GetJoint(int index);

};

#endif
