// Keys.cpp: implementation of the Keys class.
//
//////////////////////////////////////////////////////////////////////

#include "keys.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

Keys::Keys(void)
{
	for (int i = 0; i < 255; i++)
		keys[i] = false;
    for (int i = 0; i < 16; i++)
		buttons[i] = false;
}

Keys::~Keys(void)
{
}

void Keys::KeyDown(int key)
{
	this->keys[key] = true;
}

void Keys::KeyUp(int key)
{
	this->keys[key] = false;
}

bool Keys::IsKey(int key)
{
	return this->keys[key];
}

void Keys::ButtonDown(int button)
{
	this->buttons[button] = true;
}

void Keys::ButtonUp(int button)
{
	this->buttons[button] = false;
}

bool Keys::IsButton(int button)
{
	return this->buttons[button];
}
