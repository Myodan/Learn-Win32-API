#pragma once

#include "Sprite.h"

using namespace std;

class Background : public Sprite {
public:
	Background();
	Background(string _tag, string _name, bool _active, float _posX, float _posY);
	virtual ~Background();

	void Start();
	void Update();
};