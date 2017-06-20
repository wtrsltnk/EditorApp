// Keys.h: interface for the Keys class.
//
//////////////////////////////////////////////////////////////////////

#ifndef KEYS_H
#define KEYS_H

#include <windows.h>

enum
{
	Left = 0,
	Right,
	Middle,
	Mouse1,
	Mouse2,
	Mouse3
};

class Keys
{
private:
	bool keys[255];
	bool buttons[16];

public:
	Keys(void);
	virtual ~Keys(void);

	void KeyDown(int key);
	void KeyUp(int key);
	bool IsKey(int key);

	void ButtonDown(int button);
	void ButtonUp(int button);
	bool IsButton(int button);
};

#endif