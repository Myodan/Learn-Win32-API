#pragma once

#include "Sprite.h"

class Boss : public Sprite {
public:
	enum class State { down = -1, left = 0, right = 1 };

private:
	State state;
	float speed;

	int deadPartsCount;

	float gunPatternTimer;
	float gunPatternDelay;

	int gunPatternIndex;
	int gunPattern[10][7] = {
		{1, 1, 1,  0,  1, 1, 1},
		{1, 1, 0,  1,  0, 1, 1},
		{1, 1, 1,  0,  1, 1, 1},
		{1, 0, 1,  1,  1, 0, 1},
		{0, 1, 0,  0,  0, 1, 0},

		{0, 1, 1,  1,  1, 1, 0},
		{0, 1, 1,  1,  1, 1, 0},
		{1, 0, 1,  1,  1, 0, 1},
		{1, 0, 1,  1,  1, 0, 1},
		{1, 1, 0,  0,  0, 1, 1}
	};

public:
	Boss(float px, float py);
	~Boss();

	int * getGunPattern();
	State getState();

	void onDeadPartsCount();

	void start();
	void update();

	void onFire();
	void onMove();
	void onDeath();
};