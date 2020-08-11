#pragma once

#include "Animation.h"

class PartsExp : public Animation {
private:
	float lifeTime;

public:
	PartsExp(float px, float py);
	~PartsExp();

	void start();
	void update();
};