#include "framework.h"

BulletItem::BulletItem(float px, float py) :
	Sprite("아이템", "총알", true, px, py) {
	this->speed = 50.0f;
}

BulletItem::~BulletItem() {

}

void BulletItem::start() {
	setSprite("Asset/총알아이템.bmp");

	addBoxCollider(0, 0, 28, 80);
}

void BulletItem::update() {
	translate(0, speed * Time::getDeltaTime());

	if (getPy() > 1000) {
		ObjectManager::destroy(this);
	}
}

void BulletItem::onTrigger(GameObject * other) {
	string tag = other->getTag();

	if (tag == "플레이어") {
		ObjectManager::destroy(this);
	}
}