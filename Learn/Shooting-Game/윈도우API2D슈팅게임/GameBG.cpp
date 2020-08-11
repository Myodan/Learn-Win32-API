#include "framework.h"

GameBG::GameBG(float px, float py) :
	Sprite("배경", "게임배경", true, px, py) {

}

GameBG::~GameBG() {

}

void GameBG::start() {
	setSprite("Asset/배경1.bmp");
}

void GameBG::update() {

}