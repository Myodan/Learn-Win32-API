#pragma once

#include <windows.h>



class Input {
private:
	static char keyState[255];

public:
	enum keyState { upRep = 0, down = 1, downRep = 2, up = 3 };

	Input();
	virtual ~Input();

	static void Update();

	static bool GetKeyDown(char keyCode);
	static bool GetKeyUp(char keyCode);
	static bool GetKeyDownRep(char keyCode);
};