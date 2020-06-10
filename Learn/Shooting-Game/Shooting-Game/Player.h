#pragma once

#include "timer.h"

#include "Sprite.h"
#include "ObjectManager.h"

class Player : public Sprite {
private:
	float speed;
	float fireDelay;
	float fireTimer;

	Image image[7];
	int index;

public:
	Player();
	Player(string _tag, string _name, bool _active, float _posX, float _posY, float _speed, float _fireDelay);
	virtual ~Player();

	void Start();
	void Update();

	void OnTrriger(GameObject * other);

	void Move();
	void Fire();
};
