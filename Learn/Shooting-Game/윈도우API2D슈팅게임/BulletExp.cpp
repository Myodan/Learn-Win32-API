#include "framework.h"

BulletExp::BulletExp(float px, float py) :
	Animation("����", "����", true, px, py) {
}

BulletExp::~BulletExp() {

}

void BulletExp::start() {
	for (int i = 0; i < 5; i++) {
		addSprite("Asset/�Ѿ�����.bmp", 32 * i, 0, 32, 32);
	}

	for (int i = 0; i < 2; i++) {
		addSprite("Asset/�Ѿ�����.bmp", 32 * i, 32, 32, 32);
	}

	setAnimDelay(0.1f);

	lifeTime = 0.7f;
}

void BulletExp::update() {
	lifeTime = lifeTime - Time::getDeltaTime();

	if (lifeTime < 0) {
		ObjectManager::destroy(this);  //����ȿ�� �����ϱ�
	}
}