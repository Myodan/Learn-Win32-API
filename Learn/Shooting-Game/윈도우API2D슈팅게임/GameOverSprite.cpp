#include "framework.h"

GameOverSprite::GameOverSprite(float px, float py) :
	Sprite("UI_GameOver", "UI_GameOver", true, px, py){
	
}

GameOverSprite::~GameOverSprite() {

}

void GameOverSprite::start() {
	setSprite("Asset/���ӿ���.bmp");
}
