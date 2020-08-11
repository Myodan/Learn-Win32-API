#pragma once

#include "Animation.h"

class BombExp : public Animation {
private:
	float lifeTime;

public:
	BombExp(float px, float py);
	virtual ~BombExp();

	void start();
	void update();

	void onTrigger(GameObject * other);
};