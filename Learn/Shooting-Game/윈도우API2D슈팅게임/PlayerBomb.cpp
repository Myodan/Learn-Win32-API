#include "framework.h"

PlayerBomb::PlayerBomb(float px, float py) :
	Animation("ÇÃ·¹ÀÌ¾îÆøÅº", "ÇÃ·¹ÀÌ¾îÆøÅº", true, px, py) {
	this->speed = 200.0f;
	this->lifeTime = 1.0f;
}

PlayerBomb::~PlayerBomb() {

}

void PlayerBomb::start() {
	// Sprite Setting
	for (int i = 0; i < 8; i++) {
		addSprite("Asset/ÆÒÅÒÆøÅº2.bmp", (32 + 2) * i, 0, 32, 32);
	}

	// Animation Setting
	setLoop(false);
	setAnimDelay(0.1f);
}

void PlayerBomb::update() {
	float dist = speed * Time::getDeltaTime();
	translate(0, -dist);

	lifeTime -= Time::getDeltaTime();

	if (lifeTime < 0) {
		ObjectManager::addGameObject(new BombExp(getPx() - 48, getPy() - 48), 3);
		ObjectManager::destroy(this);
	}
}