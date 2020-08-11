#include "framework.h"

Stealth::Stealth(float px, float py) :
	Sprite("스텔스", "스텔스", true, px, py) {
	this->state = down;
	this->hp = 100.0f;
	this->speed = 100.0f;

	this->fireTimer = 0.0f;
	this->fireDelay = 0.5f;

	this->initAngle = 0;
	this->angleRate = 45.0f;

	this->index = 0;

}

Stealth::~Stealth() {

}

void Stealth::start() {
	setSprite("Asset/적기2.bmp");
	addBoxCollider(45, 0, 40, 150);
	addBoxCollider(0, 0, 128, 80);
}

void Stealth::update() {
	if (state == down) {
		move();

		if (getPy() >= 75) {
			state = attack;
		}
	}
	else if (state == attack) {
		fire();
	}
}

void Stealth::onTrigger(GameObject * other) {
	if (hp <= 0) {
		return;
	}

	string tag = other->getTag();
	if (tag == "플레이어블릿") {
		hp -= 10;
		if (hp <= 0) {
			die();
		}
	}
	else if (tag == "플레이어그림자" || tag == "Shield" || tag == "플레이어폭탄폭팔") {
		die();
	}
}

void Stealth::move() {
	float dist = speed * Time::getDeltaTime();

	translate(0, dist);
}

void Stealth::fire() {
	fireTimer += Time::getDeltaTime();

	if (fireTimer > fireDelay) {
		if (pat[index < 10 ? index++ : index = 0]) {
			roundShot(getPx(), getPy(), initAngle * 360 / 15 / 2, 15, 360 / 15);
			initAngle++;
		}
		fireTimer = 0;
	}
}

void Stealth::roundShot(float px, float py, float initAngle, float amount, float interval) {
	for (float i = 0; i < amount; i++) {
		ObjectManager::addGameObject(new StealthBullet(px + 54, py + 99, (float)i * interval + initAngle, angleRate), 1);
	}
	angleRate *= -1;
}

void Stealth::die() {
	GameManager::decStealthCount();
	GameManager::addScore(20);
	ObjectManager::addGameObject(new ShipExp(getPx(), getPy()), 2);
	switch (Random::range(0, 1)) {
	case 0:
	{
		if (!Random::range(0, 4)) {
			ObjectManager::addGameObject(new BulletItem(getPx(), getPy()), 3);
		}
	}
	break;
	case 1:
	{
		if (!Random::range(0, 4)) {
			ObjectManager::addGameObject(new BombItem(getPx(), getPy()), 3);
		}
	}
	}
	ObjectManager::destroy(this);
}