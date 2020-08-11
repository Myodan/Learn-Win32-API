#include "framework.h"

Boss::Boss(float px, float py) :
	Sprite("º¸½º", "º¸½º", true, px, py) {
	this->state = State::down;
	this->speed = 50.0f;
	this->deadPartsCount = 0;

	this->gunPatternTimer = 0.0f;
	this->gunPatternDelay = 1.0f;
	this->gunPatternIndex = 0;
}

Boss::~Boss() {

}

int * Boss::getGunPattern() {
	return gunPattern[gunPatternIndex];
}

Boss::State Boss::getState() {
	return state;
}

void Boss::start() {
	// Idle
	setSprite("Asset/Àûº¸½º.bmp", 0, 0, 493, 206);
	// Die
	//setSprite("Asset/Àûº¸½º.bmp", 0, 613, 385, 182);

	// ·ÎÅÍ
	addChildObj(new Rotor(63, 41), 3);
	addChildObj(new Rotor(111, 41), 3);
	addChildObj(new Rotor(159, 41), 3);
	addChildObj(new Rotor(302, 41), 3);
	addChildObj(new Rotor(350, 41), 3);
	addChildObj(new Rotor(398, 41), 3);

	// ³¯°³
	addChildObj(new Wing(62, 85, 0), 3);
	addChildObj(new Wing(110, 90, 1), 3);
	addChildObj(new Wing(158, 94, 2), 3);
	addChildObj(new Wing(206, 98, 3), 3);
	addChildObj(new Wing(256, 97, 4), 3);
	addChildObj(new Wing(302, 94, 5), 3);
	addChildObj(new Wing(350, 90, 6), 3);
	addChildObj(new Wing(405, 84, 7), 3);

	// ÃÑ
	addChildObj(new Gun(94, 71, "º¸½ºÃÑ0"), 3);
	addChildObj(new Gun(142, 71, "º¸½ºÃÑ1"), 3);
	addChildObj(new Gun(190, 71, "º¸½ºÃÑ2"), 3);
	addChildObj(new Gun(238, 63, "º¸½ºÃÑ3"), 3);
	addChildObj(new Gun(286, 71, "º¸½ºÃÑ4"), 3);
	addChildObj(new Gun(334, 71, "º¸½ºÃÑ5"), 3);
	addChildObj(new Gun(382, 71, "º¸½ºÃÑ6"), 3);

	// ³¯°³ ÃÑ
	addChildObj(new WingGun(270, 107), 3);
	addChildObj(new WingGun(201, 107), 3);

	// ·¹ÀÌ´õ
	addChildObj(new Radar(241, 105), 3);
	addChildObj(new Radar(241, 117), 3);

	addBoxCollider(184, 173, 124, 25);
	addBoxCollider(8, 60, 477, 40);
	addBoxCollider(227, 6, 40, 170);
}

void Boss::update() {
	onMove();
	onFire();
}

void Boss::onFire() {
	if (state == State::down) {
		return;
	}

	gunPatternTimer += Time::getDeltaTime();

	if (gunPatternTimer >= gunPatternDelay) {
		gunPatternIndex++;

		if (gunPatternIndex >= 10) {
			gunPatternIndex = 0;
		}

		for (int i = 0; i < sizeof(gunPattern[0]) / sizeof(gunPattern[0][0]); i++) {
			if (gunPattern[gunPatternIndex][i]) {
				Gun* gun = (Gun*)getChildObjByName("º¸½ºÃÑ" + to_string(i));
				if (gun != nullptr) {
					gun->onFire();
				}
			}
		}

		gunPatternTimer = 0.0f;
	}
}

void Boss::onMove() {
	float dist = speed * Time::getDeltaTime();

	if (state == State::down) {
		translate(0, dist);
		if (getPy() >= 75.0f) {
			state = State::left;
		}
	}
	else if (state == State::left) {
		translate(-dist, 0);
		if (getPx() < 0.0f - 100.0f) {
			state = State::right;
		}
	}
	else if (state == State::right) {
		translate(dist, 0);
		if (getPx() > BG_WIDTH - 493 + 100.0f) {
			state = State::left;
		}
	}
}

void Boss::onDeadPartsCount() {
	deadPartsCount++;
	GameManager::addScore(50);
	if (deadPartsCount >= 25) {
		onDeath();
	}
}

void Boss::onDeath() {
	GameManager::addScore(1000);
	ObjectManager::addGameObject(new DeadBoss(getPx() + 46, getPy() + 10), 1);
	ObjectManager::destroy(this);
}