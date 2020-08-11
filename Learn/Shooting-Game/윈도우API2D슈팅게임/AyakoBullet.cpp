#include "framework.h"

AyakoBullet::AyakoBullet(float px, float py)
	:Sprite("아야코블릿", "아야코블릿", true, px, py) {
	this->speed = 250;
	this->lifeTime = 4;
}

AyakoBullet::~AyakoBullet() {
}

void AyakoBullet::start() {
	///이미지 로드하기////
	setSprite("Asset/불릿모음.bmp", 207, 82, 13, 16);

	///충돌체 추가하기////
	addBoxCollider(0, 0, 11, 16);
}

void AyakoBullet::update() {
	//블릿 이동//
	float d = speed * Time::getDeltaTime();
	translate(0, d);

	//라이프 타임 측정//
	lifeTime = lifeTime - Time::getDeltaTime();

	if (lifeTime < 0) {
		ObjectManager::destroy(this);
	}
}

void AyakoBullet::onTrigger(GameObject * other) {
	string tag = other->getTag();

	if (tag == "플레이어" || tag == "플레이어그림자" || tag == "Shield") {
		float px = getPx();
		float py = getPy();
		ObjectManager::addGameObject(new BulletExp(px - 5, py - 5), 2);
		ObjectManager::destroy(this);
	}
}