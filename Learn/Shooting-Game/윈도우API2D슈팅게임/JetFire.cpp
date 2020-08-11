#include "framework.h"

JetFire::JetFire(float px, float py) :
	Animation("제트불꽃", "제트불꽃", true, px, py){

}

JetFire::~JetFire() {

}

void JetFire::start() {
	addSprite("Asset/분사1.bmp");
	addSprite("Asset/분사2.bmp");
	addSprite("Asset/분사3.bmp");
}
