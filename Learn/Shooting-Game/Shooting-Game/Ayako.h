#pragma once

#include "Animation.h"

class Ayako : public Animation {
private:
	enum State { down = 0, left = 1, right = 2 };
	State state;

	float speed;
	float downPosY;

public:
	Ayako(string _tag, string _name, bool _active, float _posX, float _posY, float _animDelay);
	virtual ~Ayako();

	void Start();
	void Update();
};