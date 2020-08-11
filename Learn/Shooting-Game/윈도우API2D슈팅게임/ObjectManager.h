#pragma once

#include <vector>
#include "GameObject.h"

#define MAX_LAYERS 10

class ObjectManager {
private:
	static vector<GameObject *> objList[MAX_LAYERS];
	static bool isDrawCollider;

public:
	static void addGameObject(GameObject * obj, int order);

	static void destroy(GameObject * obj);
	static void destroyExe();
	static void clear();

	static void update();
	static void draw();

	static void checkCollision();

	static GameObject * findWithName(string name);
	static GameObject * findWithTag(string tag);
};