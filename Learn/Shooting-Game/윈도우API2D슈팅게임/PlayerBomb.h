#pragma once

#include "Animation.h"

class PlayerBomb : public Animation {
private:
	float speed;
	float lifeTime;

public:
	PlayerBomb(float px, float py);
	virtual ~PlayerBomb();

	void start();
	void update();
};