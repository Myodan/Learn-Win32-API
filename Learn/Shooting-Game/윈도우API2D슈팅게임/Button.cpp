#include "framework.h"

Button::Button(string imagePath, bool active, float px, float py) :
	Sprite("버튼", "버튼", active, px, py) {
	state = State::normal;
	this->imagePath = imagePath;
}

Button::~Button() {

}

void Button::onClick() {

}

bool Button::inRect() {
	int mousePosX = Input::mousePosition.x;
	int mousePosY = Input::mousePosition.y;
	int posX = (int)getPx();
	int posY = (int)getPy();

	int left = posX;
	int top = posY;
	int right = posX + getWidth();
	int bottom = posY + getHeight();

	if ((left < mousePosX && mousePosX < right) && (top < mousePosY && mousePosY < bottom)) {
		return true;
	}
	else {
		return false;
	}
}

void Button::start() {
	setSprite(imagePath);
}

void Button::update() {
	if (getActive()) {
		if (state == State::normal) {
			if (inRect()) {
				state = State::hover;
			}
		}
		else if (state == State::hover) {
			if (!inRect()) {
				state = State::normal;
			}
			else if (Input::getMouseButtonDown(0)) {
				state = State::pushed;
				translate(2, 2);
			}
		}
		else if (state == State::pushed) {
			if (!inRect()) {
				translate(-2, -2);
				state = State::normal;
			}
			if (Input::getMouseButtonUp(0)) {
				translate(-2, -2);
				state = State::clicked;
			}
		}
		else if (state == State::clicked) {
			onClick();
			state = State::hover;
		}
	}
}