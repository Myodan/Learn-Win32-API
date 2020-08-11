#include "framework.h"

Wing::Wing(float px, float py, int wingNum) :
	Sprite("날개", "날개", true, px, py) {
	this->wingNum = wingNum;
	this->hp = 100.0f;
}

Wing::~Wing() {

}

void Wing::start() {
	switch (wingNum) {
	case 0:
		setSprite("Asset/적보스.bmp", 299, 406, 32, 16);
		addBoxCollider(0, 0, 32, 16);
		break;
	case 1:
		setSprite("Asset/적보스.bmp", 334, 406, 32, 16);
		addBoxCollider(0, 0, 32, 16);
		break;
	case 2:
		setSprite("Asset/적보스.bmp", 369, 406, 32, 16);
		addBoxCollider(0, 0, 32, 16);
		break;
	case 3:
		setSprite("Asset/적보스.bmp", 404, 406, 28, 15);
		addBoxCollider(0, 0, 28, 15);
		break;
	case 4:
		setSprite("Asset/적보스.bmp", 298, 425, 30, 18);
		addBoxCollider(0, 0, 30, 18);
		break;
	case 5:
		setSprite("Asset/적보스.bmp", 329, 426, 32, 16);
		addBoxCollider(0, 0, 32, 16);
		break;
	case 6:
		setSprite("Asset/적보스.bmp", 364, 426, 32, 16);
		addBoxCollider(0, 0, 32, 16);
		break;
	case 7:
		setSprite("Asset/적보스.bmp", 399, 426, 32, 16);
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

void Wing::die() {
	hp = 0;
	Boss * parent = (Boss *)getParent();
	parent->onDeadPartsCount();
	ObjectManager::addGameObject(new PartsExp(getPx() - 30, getPy() - 30), 4);
	ObjectManager::destroy(this);
}