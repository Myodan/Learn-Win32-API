#include "framework.h"

BombIcon::BombIcon(float px, float py)
	:Sprite("������", "��ź", true, px, py) {

}

BombIcon::~BombIcon() {

}

void BombIcon::start() {
	setSprite("Asset/UI/��ź������.bmp");
}
