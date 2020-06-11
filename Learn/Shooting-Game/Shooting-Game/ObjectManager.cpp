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

void ObjectManager::Instantiate(GameObject * obj) {
	objs.push_back(obj);
	obj->Start();
}

void ObjectManager::Destroy(GameObject * obj) {
	//for (int i = 0; i < objs.size(); i++) {
	//	if (objs.at(i) != obj) {
	//		continue;
	//	}

	//	delete objs.at(i);
	//	objs.erase(objs.begin() + i);
	//	break;
	//}

	obj->SetDead();
}

void ObjectManager::CheckCollision() {
	for (int i = 0; i < objs.size(); i++) {
		for (int j = 0; j < objs.size(); j++) {
			if (i < j) {
				continue;
			}

			GameObject * iObj = objs.at(i);
			GameObject * jObj = objs.at(j);

			vector<BoxCollider *> * iObjCollider = iObj->GetCollider();
			vector<BoxCollider *> * jObjCollider = jObj->GetCollider();

			for (int ii = 0; ii < iObjCollider->size(); ii++) {
				for (int jj = 0; jj < jObjCollider->size(); jj++) {
					if (ii < jj) {
						continue;
					}

					BoxCollider * iiCollider = iObjCollider->at(ii);
					BoxCollider * jjCollider = jObjCollider->at(jj);

					float a = iiCollider->GetX();
					float b = iiCollider->GetY();
					float c = a + iiCollider->GetWidth();
					float d = b + iiCollider->GetHeight();

					float A = jjCollider->GetX();
					float B = jjCollider->GetY();
					float C = A + jjCollider->GetWidth();
					float D = B + jjCollider->GetHeight();

					if (B < d && D > b && C > a && A < c) {
						iObj->OnTrriger(jObj);
						jObj->OnTrriger(iObj);
					}
				}
			}
		}
	}
}

void ObjectManager::DestoryExe() {
	for (int i = 0; i < objs.size(); i++) {
		if (!objs.at(i)->GetAlive()) {
			delete objs.at(i);
			objs.erase(objs.begin() + i);
			i--;
		}
	}
}