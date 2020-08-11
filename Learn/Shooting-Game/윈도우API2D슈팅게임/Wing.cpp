#include "framework.h"

Wing::Wing(float px, float py, int wingNum) :
	Sprite("����", "����", true, px, py) {
	this->wingNum = wingNum;
	this->hp = 100.0f;
}

Wing::~Wing() {

}

void Wing::start() {
	switch (wingNum) {
	case 0:
		setSprite("Asset/������.bmp", 299, 406, 32, 16);
		addBoxCollider(0, 0, 32, 16);
		break;
	case 1:
		setSprite("Asset/������.bmp", 334, 406, 32, 16);
		addBoxCollider(0, 0, 32, 16);
		break;
	case 2:
		setSprite("Asset/������.bmp", 369, 406, 32, 16);
		addBoxCollider(0, 0, 32, 16);
		break;
	case 3:
		setSprite("Asset/������.bmp", 404, 406, 28, 15);
		addBoxCollider(0, 0, 28, 15);
		break;
	case 4:
		setSprite("Asset/������.bmp", 298, 425, 30, 18);
		addBoxCollider(0, 0, 30, 18);
		break;
	case 5:
		setSprite("Asset/������.bmp", 329, 426, 32, 16);
		addBoxCollider(0, 0, 32, 16);
		break;
	case 6:
		setSprite("Asset/������.bmp", 364, 426, 32, 16);
		addBoxCollider(0, 0, 32, 16);
		break;
	case 7:
		setSprite("Asset/������.bmp", 399, 426, 32, 16);
		addBoxCollider(0, 0, 32, 16);
		break;
	default:
		break;
	}
}

void Wing::onTrigger(GameObject * other) {
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

void Wing::die() {
	hp = 0;
	Boss * parent = (Boss *)getParent();
	parent->onDeadPartsCount();
	ObjectManager::addGameObject(new PartsExp(getPx() - 30, getPy() - 30), 4);
	ObjectManager::destroy(this);
}