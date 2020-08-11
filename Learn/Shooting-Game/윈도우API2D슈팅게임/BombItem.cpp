#include "framework.h"

BombItem::BombItem(float px, float py) :
	Sprite("¾ÆÀÌÅÛ", "ÆøÅº", true, px, py) {
	this->speed = 50.0f;
}

BombItem::~BombItem() {

}

void BombItem::start() {
	setSprite("Asset/ÆøÅº¾ÆÀÌÅÛ.bmp");

	addBoxCollider(3, 0, 16, 40);
}

void BombItem::update() {
	translate(0, speed * Time::getDeltaTime());

	if (getPy() > 1000) {
		ObjectManager::destroy(this);
	}
}

void BombItem::onTrigger(GameObject * other) {
	string tag = other->getTag();

	if (tag == "ÇÃ·¹ÀÌ¾î") {
		ObjectManager::destroy(this);
	}
}