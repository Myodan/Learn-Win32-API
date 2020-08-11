#pragma once

#include "Sprite.h"

class PlayerBullet : public Sprite
{
private:

	float speed;
	int   type;   //0-���, 1-���� 2-������

	float lifeTime;

public:
	PlayerBullet(float px, float py, int type);
	~PlayerBullet();

	void start();
	void update();

	/////�浹 �̺�Ʈ �������̵�/////
	void onTrigger(GameObject* other);
};