#include "framework.h"

PartsExp::PartsExp(float px, float py) :
	Animation("颇明气迫", "颇明气迫", true, px, py) {
	this->lifeTime = 0.08f * 6;
}

PartsExp::~PartsExp() {

}

void PartsExp::start() {
	for (int i = 0; i < 6; i++) {
		addSprite("Asset/焊胶颇明气惯2.bmp", 72 * i, 0, 72, 72);
	}

	setAnimDelay(0.08f);
}

void PartsExp::update() {
	lifeTime -= Time::getDeltaTime();

	if (lifeTime <= 0) {
		ObjectManager::destroy(this);
	}
}