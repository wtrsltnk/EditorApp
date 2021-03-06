// Sequence.h: interface for the Sequence class.
//
//////////////////////////////////////////////////////////////////////

#ifndef SEQUENCE_H
#define SEQUENCE_H

#include "ISequence.h"
#include "Collection.h"
#include "Motion.h"

class Sequence : public ISequence
{
private:
	char name[128];
	Collection <Motion*> motions;

	void ClearMotions();

public:
    Sequence(const char* name);
	virtual ~Sequence();

    const char* Name();
    void Name(const char* name);

	void SetupMotions();

	void AddMotion(Motion* joint);
	bool RemoveMotion(int index);

	int GetMotionCount();
	Motion* GetMotion(int index);

};

#endif
