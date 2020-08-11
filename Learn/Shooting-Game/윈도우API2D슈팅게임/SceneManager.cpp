#include "framework.h"

Scene * SceneManager::scene = nullptr;

void SceneManager::init() {
	scene = new TitleScene();
	scene->start();
}

void SceneManager::run() {
	scene->run();
}

void SceneManager::loadScene(Scene * scene) {
	delete SceneManager::scene;
	SceneManager::scene = scene;
	scene->start();
}