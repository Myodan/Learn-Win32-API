#pragma once

class Scene {
private:

public:
	Scene();
	virtual ~Scene();

	virtual void start();
	virtual void run();
};