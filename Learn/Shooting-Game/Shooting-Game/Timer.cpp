#include "framework.h"

float Timer::curTime;
float Timer::prevTime;
float Timer::deltaTime;

void Timer::Init(){
	curTime = GetTickCount() / 1000.0f;
	prevTime = GetTickCount() / 1000.0f;
	deltaTime = 0;
}

void Timer::Update(){
	curTime = GetTickCount() / 1000.0f;
	deltaTime = curTime - prevTime;
	prevTime = curTime;
}

float Timer::GetDeltaTime(){
	return deltaTime;
}