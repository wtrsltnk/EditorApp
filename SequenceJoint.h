// SequenceJoint.h: interface for the SequenceJoint class.
//
//////////////////////////////////////////////////////////////////////

#ifndef SEQUENCEJOINT_H
#define SEQUENCEJOINT_H

#include "Mathlib.h"
#include "Collection.h"
#include "KeyFrame.h"

class SequenceJoint  
{
private:
	int jointid;
	Collection <KeyFrame*> translationFrames;
	Collection <KeyFrame*> rotationFrames;

	int currentTranslationFrame;
	int currentRotationFrame;
	Matrix final;

public:
	SequenceJoint();
	virtual ~SequenceJoint();

};

#endif
