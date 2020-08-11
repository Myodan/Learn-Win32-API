#include "framework.h"

GoHome::GoHome(float px, float py) :
	Animation("±ÍÈ¯", "±ÍÈ¯", true, px, py) {
	this->speed = 200.0f;
}

GoHome::~GoHome() {

}

void GoHome::start() {
	for (int i = 0; i < 11; i++) {
		addSprite("Asset/ÆÒÅÒ±ÍÈ¯.bmp", 64 * i, 0, 62, 240);
	}
	setLoop(false);
	setAnimDelay(0.1f);
}

void GoHome::update() {
	speed += 750.0f * Time::getDeltaTime();
	translate(0, -speed * Time::getDeltaTime());

	if (getPy() <= -300.0f) {
		ObjectManager::destroy(this);
	}
}