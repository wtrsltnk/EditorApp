// Motion.h: interface for the Motion class.
//
//////////////////////////////////////////////////////////////////////

#ifndef MOTION_H
#define MOTION_H

#include "Mathlib.h"
#include "Collection.h"
#include "KeyFrame.h"

class Motion  
{
private:
	int jointid;
	Collection <KeyFrame*> translationFrames;
	Collection <KeyFrame*> rotationFrames;

	int currentTranslationFrame;
	int currentRotationFrame;
	Matrix final;

public:
	Motion();
	virtual ~Motion();

};

#endif
