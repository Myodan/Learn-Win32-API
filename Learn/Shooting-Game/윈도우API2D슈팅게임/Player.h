#pragma once

#include "Sprite.h"

class Player : public Sprite {
private:
	enum class State { spawn = 0, idle = 1 };
	State state;
	float health;
	float speed;
	int power;
	int bombNum;

	Image image[7];
	int   index;

	// Fire Cooltime
	float fireTimer;
	float fireDelay;

	// Shadow Cooltime
	float shadowTimer;
	float shadowDelay;

	// Shield Cooltime
	float shieldTimer;
	float shieldHoldingTime;

	// Bomb Cooltime
	float bombTimer;
	float bombDelay;

public:
	Player(float px, float py);
	~Player();

	int getPower();
	void setPower(int power);

	void start();
	void update();

	void move();
	void fire();
	void shadow();
	void shield();
	void bomb();
	void onDeath();

	void onTrigger(GameObject * other);
};