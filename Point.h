// Point.h: interface for the Point class.
//
//////////////////////////////////////////////////////////////////////

#ifndef POINT_H
#define POINT_H

#include "mathlib.h"

class Point  
{
friend class Mesh;

private:
	int id;
	Vector position;
	Vector normal;
	Vector animPosition;
	Vector animNormal;
	int jointid;

	int ID();
	void ID(int id);

public:
	Point();
	virtual ~Point();

	void Move(float x, float y, float z);
	void Set(float x, float y, float z);

	void Render();

	int Joint();
	void Joint(int id);

	Vector& AnimPosition();
	Vector& AnimNormal();
};

#endif
