#pragma once

#include "Animation.h"

class BulletExp : public Animation
{
private:

	//����ȿ���� ���� �ð�//
	float lifeTime;

public:
	BulletExp(float px, float py);
	~BulletExp();


	void start();
	void update();
};