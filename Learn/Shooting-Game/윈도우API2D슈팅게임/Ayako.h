#pragma once

#include "Animation.h"

class Ayako : public Animation {
private:
	enum class State { right = 0, left = 1, down = 2, drop = 4};

	float hp;
	float speed;
	float downPy;

	State state;

	float fireTimer;
	float fireDelay;

public:
	Ayako(float px, float py);
	~Ayako();

	void start();
	void update();

	void onTrigger(GameObject * other);
	virtual void die();
};