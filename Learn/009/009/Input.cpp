#include "Input.h"

char Input::keyState[255] = { upRep, };

Input::Input() {

}

Input::~Input() {

}

void Input::Update() {
	for (int key = 1; key < 255; key++) {
		if (keyState[key] == upRep) {
			if (GetAsyncKeyState(key) != 0) {
				keyState[key] = down;
			}
		}
		else if (keyState[key] == down) {
			if (GetAsyncKeyState(key) != 0) {
				keyState[key] = downRep;
			}
			else {
				keyState[key] = up;
			}
		}
		else if (keyState[key] == downRep) {
			if (GetAsyncKeyState(key) == 0) {
				keyState[key] = up;
			}
		}
		else if (keyState[key] == up) {
			if (GetAsyncKeyState(key) == 0) {
				keyState[key] = upRep;
			}
			else {
				keyState[key] = down;
			}
		}
	}
}

bool Input::GetKeyDown(char keyCode) {
	if (keyState[keyCode] == down) {
		return true;
	}

	return false;
}

bool Input::GetKeyUp(char keyCode) {
	if (keyState[keyCode] == up) {
		return true;
	}

	return false;
}

bool Input::GetKeyDownRep(char keyCode) {
	if (keyState[keyCode] == down || keyState[keyCode] == downRep) {
		return true;
	}

	return false;
}