#pragma once

#include "Animation.h"

class BulletExp : public Animation
{
private:

	//폭발효과의 유지 시간//
	float lifeTime;

public:
	BulletExp(float px, float py);
	~BulletExp();


	void start();
	void update();
};