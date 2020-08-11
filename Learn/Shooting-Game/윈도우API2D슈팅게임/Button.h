#pragma once

#include "Sprite.h"

class Button : public Sprite {
	enum class State { normal = 0, hover = 1, pushed = 2, clicked = 3 };
	State state;
	string imagePath;

public:
	Button(string imagePath, bool active, float px, float py);
	~Button();

	virtual void onClick();
	bool inRect();

	void start();
	void update();
};
