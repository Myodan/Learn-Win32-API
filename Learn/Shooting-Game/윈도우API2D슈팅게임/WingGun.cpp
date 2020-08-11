#include "framework.h"

WingGun::WingGun(float px, float py) :
	Sprite("³¯°³ÃÑ", "³¯°³ÃÑ", true, px, py) {
	this->hp = 100.0f;
	this->fireTimer = 0.0f;
	this->fireDelay = 0.25f;
}

WingGun::~WingGun() {

}

void WingGun::start() {
	setSprite("Asset/Àûº¸½º.bmp", 357, 262, 21, 22);
	addBoxCollider(0, 0, 21, 22);
}

void WingGun::update() {
	Boss* parent = (Boss*)getParent();
	if (parent->getState() == Boss::State::down) {
		return;
	}

	fireTimer += Time::getDeltaTime();

	if (fireTimer >= fireDelay) {
		float px = getPx();
		float py = getPy();

		ObjectManager::addGameObject(new StealthBullet(px, py, 45, -15), 2);
		ObjectManager::addGameObject(new StealthBullet(px, py, 40, -15), 2);
		ObjectManager::addGameObject(new StealthBullet(px, py, 35, -15), 2);

		ObjectManager::addGameObject(new StealthBullet(px, py, 5, 0), 2);
		ObjectManager::addGameObject(new StealthBullet(px, py, 0, 0), 2);
		ObjectManager::addGameObject(new StealthBullet(px, py, -5, 0), 2);

		ObjectManager::addGameObject(new StealthBullet(px, py, -45, 15), 2);
		ObjectManager::addGameObject(new StealthBullet(px, py, -40, 15), 2);
		ObjectManager::addGameObject(new StealthBullet(px, py, -35, 15), 2);

		fireTimer = 0.0f;
	}
}

void WingGun::onTrigger(GameObject * other) {
	if (hp <= 0) {
		return;
	}

	string tag = other->getTag();

	if (tag == "ÇÃ·¹ÀÌ¾îºí¸´") {
		hp -= 10;
	}

	if (tag == "ÇÃ·¹ÀÌ¾îÆøÅºÆøÆÈ" || tag == "ÇÃ·¹ÀÌ¾î±×¸²ÀÚ") {
		die();
		return;
	}

	if (hp <= 0) {
		die();
		return;
	}
}

void WingGun::die() {
	hp = 0;
	Boss * parent = (Boss *)getParent();
	parent->onDeadPartsCount();
	
	ObjectManager::addGameObject(new PartsExp(getPx() - 30, getPy() - 30), 4);
	ObjectManager::destroy(this);
}