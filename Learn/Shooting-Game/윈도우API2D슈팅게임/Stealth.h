#pragma once

#include "Sprite.h"

class Stealth : public Sprite {
private:
	enum State{ down = 0, attack = 1 };
	State state;

	float hp;
	float speed;

	float fireTimer;
	float fireDelay;

	float initAngle;
	float angleRate;

	int pat[10] = { 1, 0, 0, 1, 1, 0, 0, 1, 1, 1 };
	int index;

public:
	Stealth(float px, float py);
	virtual ~Stealth();

	void start();
	void update();

	void onTrigger(GameObject * other);

	void move();
	void fire();
	void roundShot(float px, float py, float initAngle, float amount, float interval);
	void die();
};