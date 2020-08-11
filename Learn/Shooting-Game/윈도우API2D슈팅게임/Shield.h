#pragma once

#include "Animation.h"

class Shield : public Animation {
private:
	//float lifeTime;

public:
	Shield(float px, float py);
	virtual ~Shield();

	void start();
	void update();

	void onTrigger(GameObject * other);
};