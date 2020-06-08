#include "framework.h"

vector<GameObject *> ObjectManager::objs = vector<GameObject *>();
bool ObjectManager::isDrawCollider = false;

ObjectManager::ObjectManager() {

}

ObjectManager::~ObjectManager() {

}

void ObjectManager::Init() {
	objs.clear();
}

void ObjectManager::Update() {
	for (int i = 0; i < objs.size(); i++) {
		objs.at(i)->Update();
	}

	if (Input::GetKeyDown(VK_F1)) {
		isDrawCollider = !isDrawCollider;
	}
}

void ObjectManager::Draw() {
	for (int i = 0; i < objs.size(); i++) {
		objs.at(i)->Draw();
		if (isDrawCollider) {
			objs.at(i)->DrawCollider();
		}
	}
}

void ObjectManager::Exit() {
	for (int i = 0; i < objs.size(); i++) {
		delete objs.at(i);
	}
}

void ObjectManager::Add(GameObject *_obj) {
	objs.push_back(_obj);
	_obj->Start();
}

void ObjectManager::Delete(GameObject *_obj) {
	for (int i = 0; i < objs.size(); i++) {
		if (objs.at(i) != _obj) {
			continue;
		}

		delete objs.at(i);
		objs.erase(objs.begin() + i);
		break;
	}
}