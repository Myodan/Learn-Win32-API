#include "framework.h"

TitleBG::TitleBG(float px, float py) :
	Sprite("���", "Ÿ��Ʋ���", true, px, py) {

}

TitleBG::~TitleBG() {

}

void TitleBG::start() {
	setSprite("Asset/Title/TITLE_BACKGROUND.bmp");
}

void TitleBG::update() {

}
