#pragma once

#include "Sprite.h"

class WingGun : public Sprite {
private:
	float hp;
	float fireTimer;
	float fireDelay;

public:
	WingGun(float px, float py);
	~WingGun();

	void start();
	void update();

	void onTrigger(GameObject * other);

	void die();
};