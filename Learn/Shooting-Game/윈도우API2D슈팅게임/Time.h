#pragma once

#include <Windows.h>

class Time {
private:
	static LARGE_INTEGER second;
	static LARGE_INTEGER prevTime;
	static LARGE_INTEGER curTime;
	static float         deltaTime;
	static float         timeScale;

public:
	Time();
	virtual ~Time();

	static float getDeltaTime();
	static float getTimeScale();

	static void setTimeScale(float timeScale);

	static void initTime();
	static void updateTime();
};