#include "framework.h"

PlayerLifeIcon::PlayerLifeIcon(float px, float py)
	:Sprite("������", "�÷��̾���������", true, px, py) {

}

PlayerLifeIcon::~PlayerLifeIcon() {

}

void PlayerLifeIcon::start() {
	setSprite("Asset/UI/�����̹���.bmp");
}
