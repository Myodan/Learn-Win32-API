#pragma once

#include <vector>

#include "GameObject.h"

class ObjectManager {
private:
	static vector<GameObject *> objs;

public:
	ObjectManager();
	virtual ~ObjectManager();

	static void Init();
	static void Update();
	static void Draw();
	static void Exit();
	static void Add(GameObject *_obj);
	static void Delete(GameObject *_obj);
};