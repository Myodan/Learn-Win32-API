#include "framework.h"

Gun::Gun(float px, float py, string name) :
	Sprite("보스총", name, true, px, py) {
	this->hp = 100.0f;
}

Gun::~Gun() {

}

void Gun::start() {
	setSprite("Asset/적보스.bmp", 426, 315, 20, 25);
	addBoxCollider(0, 0, 18, 18);
}

void Gun::onTrigger(GameObject * other) {
	if (hp <= 0) {
		return;
	}

	string tag = other->getTag();

	if (tag == "플레이어블릿") {
		hp -= 10;
	}

	if (tag == "플레이어폭탄폭팔" || tag == "플레이어그림자") {
		omDeath();
		return;
	}

	if (hp <= 0) {
		omDeath();
		return;
	}
}

void Gun::onFire() {
	ObjectManager::addGameObject(new AyakoBullet(getPx(), getPy()), 3);
}

void Gun::omDeath() {
	hp = 0;
	Boss * parent = (Boss *)getParent();
	parent->onDeadPartsCount();
	ObjectManager::addGameObject(new PartsExp(getPx() - 30, getPy() - 30), 4);
	ObjectManager::destroy(this);
}