#pragma once

#include "Sprite.h"

class PlayerBullet : public Sprite
{
private:

	float speed;
	int   type;   //0-가운데, 1-왼쪽 2-오른쪽

	float lifeTime;

public:
	PlayerBullet(float px, float py, int type);
	~PlayerBullet();

	void start();
	void update();

	/////충돌 이벤트 오버라이딩/////
	void onTrigger(GameObject* other);
};