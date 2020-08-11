#include "framework.h"

vector<GameObject *> ObjectManager::objList[10];
bool ObjectManager::isDrawCollider = false;

void ObjectManager::addGameObject(GameObject * obj, int order) {
	objList[order].push_back(obj);
	obj->start();
}

void ObjectManager::destroy(GameObject * obj) {
	obj->setDead();
}

void ObjectManager::clear() {
	for (int l = 0; l < MAX_LAYERS; l++) {
		objList[l].clear();
	}
}

void ObjectManager::update() {
	for (int l = 0; l < MAX_LAYERS; l++) {
		for (int i = 0; i < objList[l].size(); i++) {
			GameObject * obj = objList[l].at(i);
			obj->update();
		}
	}

	if (Input::getKeyDown(VK_F1) == true) {
		if (isDrawCollider == true) {
			isDrawCollider = false;
		}
		else {
			isDrawCollider = true;
		}
	}
}

void ObjectManager::draw() {
	for (int l = 0; l < MAX_LAYERS; l++) {
		for (int i = 0; i < objList[l].size(); i++) {
			GameObject * obj = objList[l].at(i);

			if (obj->getActive()) {
				obj->draw();

				if (isDrawCollider == true) {
					obj->drawCollider();
				}
			}
		}
	}
}

void ObjectManager::checkCollision() {
	vector<GameObject *> tempList;

	for (int i = 0; i < MAX_LAYERS; i++) {
		for (int j = 0; j < objList[i].size(); j++) {
			GameObject * obj = objList[i].at(j);
			tempList.push_back(obj);
		}
	}

	for (int i = 0; i < tempList.size(); i++) {
		for (int j = 0; j < tempList.size(); j++) {
			if (j > i) {
				GameObject * iObj = tempList.at(i);
				GameObject * jObj = tempList.at(j);

				if (iObj->getActive() && jObj->getActive()) {
					vector<BoxCollider> jc = iObj->getCollider();
					vector<BoxCollider> ic = jObj->getCollider();

					for (int ii = 0; ii < ic.size(); ii++) {
						for (int jj = 0; jj < jc.size(); jj++) {
							BoxCollider iic = ic.at(ii);
							BoxCollider jjc = jc.at(jj);

							float a = iic.getX();
							float b = iic.getY();
							float c = a + iic.getWidth();
							float d = b + iic.getHeight();

							float A = jjc.getX();
							float B = jjc.getY();
							float C = A + jjc.getWidth();
							float D = B + jjc.getHeight();

							if (B < d && D > b && C > a && A < c) {
								iObj->onTrigger(jObj);
								jObj->onTrigger(iObj);
							}
						}
					}

				}
			}
		}
	}
	tempList.clear();
}

void ObjectManager::destroyExe() {
	for (int l = 0; l < MAX_LAYERS; l++) {
		for (int i = 0; i < objList[l].size(); i++) {
			GameObject * obj = objList[l].at(i);

			if (obj->getAlive() == false) {
				delete obj;
				objList[l].erase(objList[l].begin() + i);
				i--;
			}
		}
	}
}

GameObject * ObjectManager::findWithName(string name) {
	for (int i = 0; i < MAX_LAYERS; i++) {
		for (int j = 0; j < objList[i].size(); j++) {
			GameObject * obj = objList[i].at(j);
			if (name == obj->getName()) {
				return obj;
			}
		}
	}

	return nullptr;
}

GameObject * ObjectManager::findWithTag(string tag) {
	for (int i = 0; i < MAX_LAYERS; i++) {
		for (int j = 0; j < objList[i].size(); j++) {
			GameObject * obj = objList[i].at(j);
			if (tag == obj->getName()) {
				return obj;
			}
		}
	}

	return nullptr;
}