#include "framework.h"

EndingScene::EndingScene() : Scene() {

}

EndingScene::~EndingScene() {

}

void EndingScene::start() {
	ObjectManager::addGameObject(new EndingBG(BG_WIDTH / 2 - 320 / 2, 0), 0);
}