#include "framework.h"

GameBG::GameBG(float px, float py) :
	Sprite("���", "���ӹ��", true, px, py) {

}

GameBG::~GameBG() {

}

void GameBG::start() {
	setSprite("Asset/���1.bmp");
}

void GameBG::update() {

}