#include "framework.h"

Rotor::Rotor(float px, float py) :
	Animation("로터", "로터", true, px, py) {
	this->hp = 100.0f;
}

Rotor::~Rotor() {

}

void Rotor::start() {
	for (int i = 0; i < 2; i++) {
		addSprite("Asset/적보스.bmp", 7 + 34 * i, 439, 32, 12, 0);
	}

	for (int i = 0; i < 2; i++) {
		addSprite("Asset/적보스.bmp", 7 + 34 * i, 455, 32, 52, 1);
	}

	addBoxCollider(0, 0, 32, 12);
}

void Rotor::onTrigger(GameObject * other) {
	if (hp <= 0) {
		return;
	}

	string tag = other->getTag();

	if (tag == "플레이어블릿") {
		hp -= 10;
		if (hp <= 50) {
			setAnim(1);
		}
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

void Rotor::die() {
	hp = 0;
	Boss * parent = (Boss *)getParent();
	parent->onDeadPartsCount();
	ObjectManager::addGameObject(new PartsExp(getPx() - 30, getPy() - 30), 4);
	ObjectManager::destroy(this);
}