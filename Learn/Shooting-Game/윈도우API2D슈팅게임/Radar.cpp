#include "framework.h"

Radar::Radar(float px, float py) :
	Sprite("���̴�", "���̴�", true, px, py) {
	this->hp = 100.0f;
}

Radar::~Radar() {

}

void Radar::start() {
	setSprite("Asset/������.bmp", 360, 245, 11, 9);
	addBoxCollider(0, 0, 11, 9);
}

void Radar::onTrigger(GameObject * other) {
	if (hp <= 0) {
		return;
	}

	string tag = other->getTag();

	if (tag == "�÷��̾��") {
		hp -= 10;
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

void Radar::die() {
	hp = 0;
	Boss * parent = (Boss *)getParent();
	parent->onDeadPartsCount();
	ObjectManager::addGameObject(new PartsExp(getPx() - 30, getPy() - 30), 4);
	ObjectManager::destroy(this);
}