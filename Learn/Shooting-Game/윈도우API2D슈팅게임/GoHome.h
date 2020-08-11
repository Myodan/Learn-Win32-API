#pragma once

#include "Animation.h"

class GoHome : public Animation {
private:
	float speed;

public:
	GoHome(float px, float py);
	~GoHome();

	void start();
	void update();
};