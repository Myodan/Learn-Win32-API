#include "framework.h"

AyakoBullet::AyakoBullet(float px, float py)
	:Sprite("�ƾ��ں�", "�ƾ��ں�", true, px, py) {
	this->speed = 250;
	this->lifeTime = 4;
}

AyakoBullet::~AyakoBullet() {
}

void AyakoBullet::start() {
	///�̹��� �ε��ϱ�////
	setSprite("Asset/�Ҹ�����.bmp", 207, 82, 13, 16);

	///�浹ü �߰��ϱ�////
	addBoxCollider(0, 0, 11, 16);
}

void AyakoBullet::update() {
	//�� �̵�//
	float d = speed * Time::getDeltaTime();
	translate(0, d);

	//������ Ÿ�� ����//
	lifeTime = lifeTime - Time::getDeltaTime();

	if (lifeTime < 0) {
		ObjectManager::destroy(this);
	}
}

void AyakoBullet::onTrigger(GameObject * other) {
	string tag = other->getTag();

	if (tag == "�÷��̾�" || tag == "�÷��̾�׸���" || tag == "Shield") {
		float px = getPx();
		float py = getPy();
		ObjectManager::addGameObject(new BulletExp(px - 5, py - 5), 2);
		ObjectManager::destroy(this);
	}
}