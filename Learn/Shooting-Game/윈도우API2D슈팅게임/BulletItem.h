#pragma once

#include "Sprite.h"

class BulletItem : public Sprite {
private:
	float speed;

public:
	BulletItem(float px, float py);
	~BulletItem();

	void start();
	void update();

	void onTrigger(GameObject * other);
};