#include "framework.h"

BombExp::BombExp(float px, float py) :
	Animation("�÷��̾���ź����", "�÷��̾���ź����", true, px, py) {
	lifeTime = 0.65f;
}

BombExp::~BombExp() {

}

void BombExp::start() {
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 6; j++) {
			addSprite("Asset/������ź����.bmp", 130 * j, 130 * i, 128, 128);
		}
	}

	// Animation Setting
	setLoop(false);
	setAnimDelay(0.05f);

	addBoxCollider(19, 19, 90, 90);
}

void BombExp::update() {
	lifeTime -= Time::getDeltaTime();

	if (lifeTime < 0) {
		ObjectManager::destroy(this);
	}
}

void BombExp::onTrigger(GameObject* other) {

}