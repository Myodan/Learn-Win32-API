#pragma once

#include "Sprite.h"

class Gun : public Sprite {
private:
	float hp;

public:
	Gun(float px, float py, string name);
	~Gun();

	void start();

	void onTrigger(GameObject * other);
	void onFire();
	void omDeath();
};