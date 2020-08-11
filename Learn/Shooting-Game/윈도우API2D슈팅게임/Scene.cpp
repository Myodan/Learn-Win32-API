#include "framework.h"

Scene::Scene() {

}

Scene::~Scene() {
	ObjectManager::clear();
}

void Scene::start() {
}

void Scene::run() {
	ObjectManager::update();
	ObjectManager::checkCollision();
	ObjectManager::destroyExe();

	ObjectManager::draw();
}