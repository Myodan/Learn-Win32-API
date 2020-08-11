#include "framework.h"

Ayako::Ayako(float px, float py) :
	Animation("아야코", "아야코", true, px, py) {
	this->hp = 100;
	this->speed = 100;
	this->state = State::down;
	this->downPy = 80;

	this->fireTimer = 0;
	this->fireDelay = 1;
}

Ayako::~Ayako() {

}

void Ayako::start() {
	for (int i = 0; i < 2; i++) {
		addSprite("Asset/적기1.bmp", 1 + (200 * i), 281, 190, 137);
	}

	for (int i = 0; i < 4; i++) {
		addSprite("Asset/적기1.bmp", 1 + (200 * i), 141, 190, 137, 1);
	}

	for (int i = 0; i < 4; i++) {
		addSprite("Asset/적기1.bmp", 1 + (200 * i), 1, 190, 137, 2);
	}

	addBoxCollider(64, 9, 64, 16);
	addBoxCollider(87, 24, 16, 112);
	addBoxCollider(1, 75, 189, 30);

	downPy = downPy + Random::range(-50, 50);
}

void Ayako::update() {
	float d = speed * Time::getDeltaTime();

	if (state == State::right) {
		translate(d, 0);

		if (getPx() > BG_WIDTH - 190) {
			state = State::left;
		}
	}
	else if (state == State::left) {
		translate(-d, 0);

		if (getPx() < 0) {
			state = State::right;
		}
	}
	else if (state == State::down) {
		translate(0, d);

		if (getPy() > downPy) {
			if (Random::range(0, 1) == 0) {
				state = State::right;
			}
			else {
				state = State::left;
			}
		}
	}
	else if (state == State::drop) {
		translate(0, d);
	}

	fireTimer = fireTimer + Time::getDeltaTime();

	if (fireTimer > fireDelay) {
		float px = getPx();
		float py = getPy();

		ObjectManager::addGameObject(new AyakoBullet(px + 90, py + 130), 2);

		fireTimer = 0;
	}

	if (getPy() > 1000) {
		die();
	}

}

void Ayako::onTrigger(GameObject * other) {
	if (hp <= 0) {
		return;
	}

	string tag = other->getTag();

	if (tag == "플레이어블릿") {
		hp -= 10;

		if (hp > 80) {
			setAnim(0);
		}
		else if (hp > 60) {
			setAnim(1);
		}
		else if (hp > 30) {
			setAnim(2);
			state = State::drop;
			speed = 300.0f;
		}
		else if (hp <= 0) {
			die();
		}
	}
	else if (tag == "플레이어그림자" || tag == "Shield" || tag == "플레이어폭탄폭팔") {
		die();
	}
}

void Ayako::die() {
	hp = 0;
	GameManager::decAyacoCount();
	GameManager::addScore(10);
	ObjectManager::addGameObject(new ShipExp(getPx(), getPy()), 2);
	switch (Random::range(0, 1)) {
	case 0:
	{
		if (!Random::range(0, 1)) {
			ObjectManager::addGameObject(new BulletItem(getPx(), getPy()), 3);
		}
	}
	break;
	case 1:
	{
		if (!Random::range(0, 1)) {
			ObjectManager::addGameObject(new BombItem(getPx(), getPy()), 3);
		}
	}
	}
	ObjectManager::destroy(this);
}