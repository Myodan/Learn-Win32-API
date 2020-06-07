#pragma once

#include "Sprite.h"

class Animation : public Sprite {
private:
	int index;
	Image * spriteSet;
	float animDelay;
	float animTimer;

public:
	Animation(string _tag, string _name, bool _active, float _posX, float _posY, float _animDelay);
	virtual ~Animation();

	void Draw();

	Image * CreateImgSet(string path, int numX, int numY, RECT position, RECT border);
	void SetSpriteSet(Image * img);
};