#pragma once

#include "Sprite.h"

class BombIcon : public Sprite {
private:

public:
	BombIcon(float px, float py);
	~BombIcon();

	void start();
};

