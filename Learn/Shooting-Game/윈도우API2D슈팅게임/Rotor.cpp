#include "framework.h"

Rotor::Rotor(float px, float py) :
	Animation("����", "����", true, px, py) {
	this->hp = 100.0f;
}

Rotor::~Rotor() {

}

void Rotor::start() {
	for (int i = 0; i < 2; i++) {
		addSprite("Asset/������.bmp", 7 + 34 * i, 439, 32, 12, 0);
	}

	for (int i = 0; i < 2; i++) {
		addSprite("Asset/������.bmp", 7 + 34 * i, 455, 32, 52, 1);
	}

	addBoxCollider(0, 0, 32, 12);
}

void Rotor::onTrigger(GameObject * other) {
	if (hp <= 0) {
		return;
	}

	string tag = other->getTag();

	if (tag == "�÷��̾��") {
		hp -= 10;
		if (hp <= 50) {
			setAnim(1);
		}
	}

	if (tag == "�÷��̾���ź����" || tag == "�÷��̾�׸���") {
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