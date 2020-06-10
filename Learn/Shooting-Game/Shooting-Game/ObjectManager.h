#pragma once

#include <vector>

#include "GameObject.h"

class ObjectManager {
private:
	static vector<GameObject *> objs;
	static bool isDrawCollider;

public:
	ObjectManager();
	virtual ~ObjectManager();

	static void Init();
	static void Update();
	static void Draw();
	static void Exit();
	static void Instantiate(GameObject *_obj);
	static void Destroy(GameObject *_obj);
	static void CheckCollision();
	static void DestoryExe();
};