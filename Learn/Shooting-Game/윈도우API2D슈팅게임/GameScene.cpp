#include "framework.h"

GameScene::GameScene() :
	Scene() {

}

GameScene::~GameScene() {

}

void GameScene::start() {
	GameManager::init();
	GameManager::initUI();

	ObjectManager::addGameObject(new GameBG(0, 0), 0);
	ObjectManager::addGameObject(new Player(200, 800), 2);

	ObjectManager::addGameObject(new SpawnManager(BG_WIDTH / 2, 0), 0);
	ObjectManager::addGameObject(new Ayako(0, -100), 2);
	ObjectManager::addGameObject(new Ayako(150, -100), 2);
	ObjectManager::addGameObject(new Ayako(300, -100), 2);
	GameManager::setAyacoCount(3);
}