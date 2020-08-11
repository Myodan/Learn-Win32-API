#include "framework.h"


Shield::Shield(float px, float py) : Animation("Shield", "Shield", true, px, py) {
	//lifeTime = 3.0f;
}

Shield::~Shield() {

}

void Shield::start() {
	addSprite("Asset/��ȣ����1.bmp");
	addSprite("Asset/��ȣ����2.bmp");
	addSprite("Asset/��ȣ����3.bmp");

	addBoxCollider(0, 0, 90, 90);
}

void Shield::update() {
	//lifeTime -= Time::getDeltaTime();

	//if (lifeTime <= 0) {
	//	ObjectManager::destroy(this);
	//}
}

void Shield::onTrigger(GameObject * other) {
	string tag = other->getTag();

	if (tag == "����") {
		setActive(false);
	}
}