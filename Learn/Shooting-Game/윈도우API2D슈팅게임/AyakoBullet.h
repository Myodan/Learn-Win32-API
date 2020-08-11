#pragma once

#include "Sprite.h"

class AyakoBullet : public Sprite
{
private:
	
	float speed;
	float lifeTime;

public:
	AyakoBullet(float px, float py);
	~AyakoBullet();

	void start();
	void update();

	////충돌 이벤트 추가하기////
	void onTrigger(GameObject* other);
};
