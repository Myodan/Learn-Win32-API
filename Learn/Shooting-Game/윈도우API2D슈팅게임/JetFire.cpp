#include "framework.h"

JetFire::JetFire(float px, float py) :
	Animation("��Ʈ�Ҳ�", "��Ʈ�Ҳ�", true, px, py){

}

JetFire::~JetFire() {

}

void JetFire::start() {
	addSprite("Asset/�л�1.bmp");
	addSprite("Asset/�л�2.bmp");
	addSprite("Asset/�л�3.bmp");
}
