#pragma once

#include "Sprite.h"

class PlayerLifeIcon : public Sprite {
private:

public:
	PlayerLifeIcon(float px, float py);
	~PlayerLifeIcon();

	void start();
};