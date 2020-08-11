#include "framework.h"

DeadBoss::DeadBoss(float px, float py) :
	Sprite("데드보스", "데드보스", true, px, py) {
	this->speed = 75.0f;
	this->lifeTime = 3.0f;
}

DeadBoss::~DeadBoss() {

}

void DeadBoss::start() {
	setSprite("Asset/적보스.bmp", 0, 613, 385, 182); //폭발 후 이미지		
}

void DeadBoss::update() {
	float dist = speed * Time::getDeltaTime();
	translate(0, dist);

	lifeTime -= Time::getDeltaTime();

	if (lifeTime <= 0) {
		GameManager::setBossDead();
		ObjectManager::destroy(this);
	}
}