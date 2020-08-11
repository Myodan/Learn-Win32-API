#include "framework.h"

PlayerShadow::PlayerShadow(float px, float py) :
	Animation("플레이어그림자", "플레이어그림자", true, px, py) {
	this->speed = 250;
	this->lifeTime = 1.5f;
}

PlayerShadow::~PlayerShadow() {
}

void PlayerShadow::start() {
	for (int i = 0; i < 5; i++) {
		addSprite("Asset/팬텀그림자2.bmp", 0 + (1 + 96) * i, 0, 96, 135);
	}
	for (int i = 0; i < 3; i++) {
		addSprite("Asset/팬텀그림자2.bmp", 0 + (1 + 96) * i, 135 + 1, 96, 135);
	}

	addBoxCollider(39, 48, 17, 78);
	addBoxCollider(11, 92, 73, 30);

	setLoop(false);
	setAnimDelay(0.2f);
}

void PlayerShadow::update() {
	float d = speed * Time::getDeltaTime();
	translate(0, -d);

	lifeTime -= Time::getDeltaTime();

	if (lifeTime < 0) {
		ObjectManager::destroy(this);
	}
}