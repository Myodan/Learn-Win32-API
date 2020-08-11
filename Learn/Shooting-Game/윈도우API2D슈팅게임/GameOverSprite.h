#pragma once

#include "Sprite.h"

class GameOverSprite : public Sprite {
private:

public:
	GameOverSprite(float px, float py);
	~GameOverSprite();

	void start();
};