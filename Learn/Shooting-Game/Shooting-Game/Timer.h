#pragma once

#include <windows.h>

class Timer{
private:
	static float curTime;
	static float prevTime;
	static float deltaTime;

public:
	static void Init();
	static void Update();
	static float GetDeltaTime();
};
