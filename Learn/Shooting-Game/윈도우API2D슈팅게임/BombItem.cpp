#include "framework.h"

BombItem::BombItem(float px, float py) :
	Sprite("������", "��ź", true, px, py) {
	this->speed = 50.0f;
}

BombItem::~BombItem() {

}

void BombItem::start() {
	setSprite("Asset/��ź������.bmp");

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

	if (tag == "�÷��̾�") {
		ObjectManager::destroy(this);
	}
}