#include "framework.h"

BombIcon::BombIcon(float px, float py)
	:Sprite("酒捞能", "气藕", true, px, py) {

}

BombIcon::~BombIcon() {

}

void BombIcon::start() {
	setSprite("Asset/UI/气藕酒捞能.bmp");
}
