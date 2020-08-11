#include "framework.h"

TitleBG::TitleBG(float px, float py) :
	Sprite("배경", "타이틀배경", true, px, py) {

}

TitleBG::~TitleBG() {

}

void TitleBG::start() {
	setSprite("Asset/Title/TITLE_BACKGROUND.bmp");
}

void TitleBG::update() {

}
