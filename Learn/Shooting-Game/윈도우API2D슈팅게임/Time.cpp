#include "framework.h"

LARGE_INTEGER Time::second;
LARGE_INTEGER Time::prevTime;
LARGE_INTEGER Time::curTime;
float         Time::deltaTime = 0.0f;
float         Time::timeScale = 1.0f;

Time::Time() {

}

Time::~Time() {

}

float Time::getDeltaTime() {
	return deltaTime * timeScale;
}

float Time::getTimeScale() {
	return timeScale;
}

void Time::setTimeScale(float timeScale) {
	Time::timeScale = timeScale;
}

void Time::initTime() {
	QueryPerformanceFrequency(&second);
	QueryPerformanceCounter(&prevTime);
	QueryPerformanceCounter(&curTime);
}

void Time::updateTime() {
	QueryPerformanceCounter(&curTime);
	deltaTime = (curTime.QuadPart - prevTime.QuadPart) / (float)second.QuadPart;
	prevTime = curTime;
}