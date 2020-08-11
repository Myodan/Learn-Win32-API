#pragma once

#include "Sprite.h"

class Wing : public Sprite {
private:
	int wingNum;
	float hp;

public:
	Wing(float px, float py, int wingNum);
	~Wing();

	void start();

	void onTrigger(GameObject * other);

	void die();
};