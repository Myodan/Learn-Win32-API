#include "framework.h"

TitleScene::TitleScene() {

}

TitleScene::~TitleScene() {

}

void TitleScene::start() {
	ObjectManager::addGameObject(new TitleBG(0, 0), 0);
	ObjectManager::addGameObject(new StartBtn(true, 40, 395), 0);
	ObjectManager::addGameObject(new Button("Asset/Title/BTN_SETTING.bmp", true, 40, 480), 0);
	ObjectManager::addGameObject(new QuitBtn(true, 40, 565), 0);
}