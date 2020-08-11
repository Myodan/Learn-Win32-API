#include "framework.h"

StealthBullet::StealthBullet(float px, float py, float rot, float rotRate) :
	Sprite("스텔스블릿", "스텔스블릿", true, px, py) {
	this->speed = 250.0f;
	this->angle = rot * (float)M_PI / 180.0f;
	this->angleRate = rotRate * (float)M_PI / 180.0f;
	this->lifeTime = 5.0f;
}

StealthBullet::~StealthBullet() {

}

void StealthBullet::start() {
	setSprite("Asset/적기총알1.bmp");
	addBoxCollider(2, 2, 12, 12);
}

void StealthBullet::update() {
	lifeTimer();
	move();
}

void StealthBullet::onTrigger(GameObject * other) {
	if (other->getTag() == "플레이어" || other->getTag() == "Shield") {
		ObjectManager::addGameObject(new BulletExp(getPx() - 7, getPy() + 7), 1);
		ObjectManager::destroy(this);
	}
}

void StealthBullet::move() {
	float dist = speed * Time::getDeltaTime();

	angle += angleRate * Time::getDeltaTime();
	float dx = -dist * sin(angle);
	float dy = dist * cos(angle);

	translate(dx, dy);
}

void StealthBullet::lifeTimer() {
	lifeTime -= Time::getDeltaTime();

	if (lifeTime < 0) {
		ObjectManager::destroy(this);
	}
}
