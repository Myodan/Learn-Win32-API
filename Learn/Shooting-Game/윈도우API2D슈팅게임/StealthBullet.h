#pragma once

#define _USE_MATH_DEFINES
#include <math.h>

#include "Sprite.h"

class StealthBullet : public Sprite {
private:
	float speed;
	float angle;
	float angleRate;
	float lifeTime;

public:
	StealthBullet(float px, float py, float rot, float rotRate);
	virtual ~StealthBullet();

	void start();
	void update();

	void onTrigger(GameObject * other);

	void move();
	void lifeTimer();
};

