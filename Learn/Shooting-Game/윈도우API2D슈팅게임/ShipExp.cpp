#include "framework.h"

ShipExp::ShipExp(float px, float py) :
	Animation("气惯", "气惯", true, px, py) {
	this->lifeTime = 0.02f * 18.0f;
}

ShipExp::~ShipExp() {
}

void ShipExp::start() {
	for (int j = 1; j < 4; j++) {
		for (int i = 0; i < 6; i++) {
			addSprite("Asset/利扁气惯.bmp", 200 * i, 200 * j, 200, 200);
		}
	}

	setAnimDelay(0.02f);
}

void ShipExp::update() {
	lifeTime = lifeTime - Time::getDeltaTime();

	if (lifeTime < 0) {
		ObjectManager::destroy(this);
	}
}