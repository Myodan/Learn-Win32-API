#include "framework.h"

PlayerLifeIcon::PlayerLifeIcon(float px, float py)
	:Sprite("아이콘", "플레이어목숨아이콘", true, px, py) {

}

PlayerLifeIcon::~PlayerLifeIcon() {

}

void PlayerLifeIcon::start() {
	setSprite("Asset/UI/팬텀이미지.bmp");
}
