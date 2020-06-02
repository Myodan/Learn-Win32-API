#pragma once

#include "timer.h"

#include "Sprite.h"
#include "ObjectManager.h"

using namespace std;

class Player : public Sprite {
private:
	float speed;
	Image image[7];
	int index;

public:
	Player();
	Player(string _tag, string _name, bool _active, float _posX, float _posY, float _speed);
	virtual ~Player();

	void Start();
	void Update();
};
