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

	////�浹 �̺�Ʈ �߰��ϱ�////
	void onTrigger(GameObject* other);
};
