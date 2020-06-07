#include "framework.h"

float Timer::curTime = GetTickCount() / 1000.0f;
float Timer::prevTime = GetTickCount() / 1000.0f;
float Timer::deltaTime = 0;

void Timer::Update(){
	curTime = GetTickCount() / 1000.0f;
	deltaTime = curTime - prevTime;
	prevTime = curTime;
}

float Timer::GetDeltaTime(){
	return deltaTime;
}