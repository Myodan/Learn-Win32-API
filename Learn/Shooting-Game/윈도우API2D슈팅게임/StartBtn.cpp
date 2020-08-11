#include "framework.h"

StartBtn::StartBtn(bool active, float px, float py)
	:Button("Asset/Title/BTN_START.bmp", active, px, py) {

}

StartBtn::~StartBtn() {

}

void StartBtn::onClick() {
	SceneManager::loadScene(new GameScene());
}