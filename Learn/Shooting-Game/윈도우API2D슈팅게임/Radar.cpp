#include "framework.h"

Radar::Radar(float px, float py) :
	Sprite("레이더", "레이더", true, px, py) {
	this->hp = 100.0f;
}

Radar::~Radar() {

}

void Radar::start() {
	setSprite("Asset/적보스.bmp", 360, 245, 11, 9);
	addBoxCollider(0, 0, 11, 9);
}

void Radar::onTrigger(GameObject * other) {
	if (hp <= 0) {
		return;
	}

	string tag = other->getTag();

	if (tag == "플레이어블릿") {
		hp -= 10;
	}

	if (tag == "플레이어폭탄폭팔" || tag == "플레이어그림자") {
		die();
		return;
	}

	if (hp <= 0) {
		die();
		return;
	}
}

void Radar::die() {
	hp = 0;
	Boss * parent = (Boss *)getParent();
	parent->onDeadPartsCount();
	ObjectManager::addGameObject(new PartsExp(getPx() - 30, getPy() - 30), 4);
	ObjectManager::destroy(this);
}