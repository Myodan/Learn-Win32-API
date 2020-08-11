#pragma once

#include "Animation.h"

class ShipExp : public Animation
{
private:

	float lifeTime;
public:
	ShipExp(float px, float py);
	~ShipExp();

	void start();
	void update();
};