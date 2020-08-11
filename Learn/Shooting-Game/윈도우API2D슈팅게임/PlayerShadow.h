#pragma once

#include "Animation.h"

class PlayerShadow : public Animation {
private:
	float speed;
	float lifeTime;

public:
	PlayerShadow(float px, float py);
	~PlayerShadow();

	void start();
	void update();
};