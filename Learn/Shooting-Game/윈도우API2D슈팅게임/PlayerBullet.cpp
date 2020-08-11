#include "framework.h"

PlayerBullet::PlayerBullet(float px, float py, int type)
	:Sprite("�÷��̾��", "�Ҹ�", true, px, py) {
	this->speed = 250;
	this->type = type;
	this->lifeTime = 5;
}

PlayerBullet::~PlayerBullet() {
}

void PlayerBullet::start() {
	if (type == 0) {
		setSprite("Asset/�Ҹ�����.bmp", 26, 10, 12, 15);
		addBoxCollider(3, 0, 6, 15);
	}
	else if (type == 1) {

		setSprite("Asset/�Ҹ�����.bmp", 9, 11, 14, 14);
		addBoxCollider(0, 0, 4, 4);
		addBoxCollider(3, 3, 4, 4);
		addBoxCollider(6, 6, 4, 4);
	}
	else if (type == 2) {

		setSprite("Asset/�Ҹ�����.bmp", 41, 11, 14, 14);
		addBoxCollider(9, 0, 4, 4);
		addBoxCollider(6, 3, 4, 4);
		addBoxCollider(3, 6, 4, 4);
	}
}

void PlayerBullet::update() {
	//�� �̵�//
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

	//������ Ÿ�� ����//
	lifeTime = lifeTime - Time::getDeltaTime();

	if (lifeTime < 0) {
		ObjectManager::destroy(this);
	}
}

void PlayerBullet::onTrigger(GameObject * other) {
	string tag = other->getTag();

	if (tag == "�ƾ���" || tag == "���ڽ�" || tag == "������" || tag == "���̴�" || tag == "����" || tag == "������" || tag == "����") {
		////�� ���� ��ġ//
		float px = getPx();
		float py = getPy();

		//�� ����//
		ObjectManager::addGameObject(new BulletExp(px - 10, py), 3);

		//�� ����//
		ObjectManager::destroy(this);
	}
}