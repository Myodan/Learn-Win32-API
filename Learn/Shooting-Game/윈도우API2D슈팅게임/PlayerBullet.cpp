#include "framework.h"

PlayerBullet::PlayerBullet(float px, float py, int type)
	:Sprite("플레이어블릿", "불릿", true, px, py) {
	this->speed = 250;
	this->type = type;
	this->lifeTime = 5;
}

PlayerBullet::~PlayerBullet() {
}

void PlayerBullet::start() {
	if (type == 0) {
		setSprite("Asset/불릿모음.bmp", 26, 10, 12, 15);
		addBoxCollider(3, 0, 6, 15);
	}
	else if (type == 1) {

		setSprite("Asset/불릿모음.bmp", 9, 11, 14, 14);
		addBoxCollider(0, 0, 4, 4);
		addBoxCollider(3, 3, 4, 4);
		addBoxCollider(6, 6, 4, 4);
	}
	else if (type == 2) {

		setSprite("Asset/불릿모음.bmp", 41, 11, 14, 14);
		addBoxCollider(9, 0, 4, 4);
		addBoxCollider(6, 3, 4, 4);
		addBoxCollider(3, 6, 4, 4);
	}
}

void PlayerBullet::update() {
	//블릿 이동//
	float d = speed * Time::getDeltaTime();

	if (type == 0) {
		translate(0, -d);
	}
	else if (type == 1) {

		translate(-d, -d);
	}
	else if (type == 2) {

		translate(d, -d);
	}

	//라이프 타임 측정//
	lifeTime = lifeTime - Time::getDeltaTime();

	if (lifeTime < 0) {
		ObjectManager::destroy(this);
	}
}

void PlayerBullet::onTrigger(GameObject * other) {
	string tag = other->getTag();

	if (tag == "아야코" || tag == "스텔스" || tag == "날개총" || tag == "레이더" || tag == "날개" || tag == "보스총" || tag == "로터") {
		////블릿 현재 위치//
		float px = getPx();
		float py = getPy();

		//블릿 폭발//
		ObjectManager::addGameObject(new BulletExp(px - 10, py), 3);

		//블릿 제거//
		ObjectManager::destroy(this);
	}
}