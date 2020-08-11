#pragma once

#include "Scene.h"


class SceneManager {
public:
	static void init();
	static void loadScene(Scene * scene);

	static void run();

private:
	static Scene * scene;
};