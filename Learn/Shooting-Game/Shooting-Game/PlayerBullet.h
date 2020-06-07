#pragma once

#include "Sprite.h"

class PlayerBullet : public Sprite {
private:
	float speed;
	Image image[8];
	int index;
	int type;

public:
	PlayerBullet();
	PlayerBullet(string _tag, string _name, bool _active, float _posX, float _posY, float _speed, int _type);
	virtual ~PlayerBullet();

	void Start();
	void Update();

};