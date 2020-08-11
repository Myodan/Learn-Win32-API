#include "framework.h"

int Input::state[255];
MousePosition Input::mousePosition;

void Input::init() {
	for (int i = 0; i < 255; i++) {
		state[i] = keyUpRep;
	}

	mousePosition = { 0, 0 };
}

void Input::update() {
	//////Ű ���� ������Ʈ/////
	for (int key = 1; key < 255; key++) {

		if (state[key] == keyUpRep) {
			//cout << "Ű�� ��� ���� " << endl;

			if (GetAsyncKeyState(key) != 0) {
				state[key] = keyDown;
			}
		}
		else if (state[key] == keyDown) {

			//cout << "Ű�� �ѹ� ����" << endl;

			if (GetAsyncKeyState(key) != 0) {
				state[key] = keyDownRep;
			}
			else {
				state[key] = keyUp;
			}
		}
		else if (state[key] == keyDownRep) {

			//cout << "Ű�� ��� ����" << endl;

			if (GetAsyncKeyState(key) == 0) {
				state[key] = keyUp;
			}
		}
		else if (state[key] == keyUp) {

			//cout << "Ű�� �ѹ� ���� " << endl;

			if (GetAsyncKeyState(key) == 0) {
				state[key] = keyUpRep;
			}
			else {
				state[key] = keyDown;
			}
		}
	}


}

bool Input::getKeyDown(int keyCode) {
	if (state[keyCode] == keyDown) {
		return true;
	}
	else {
		return false;
	}
}

bool Input::getKeyUp(int keyCode) {
	if (state[keyCode] == keyUp) {
		return true;
	}
	else {
		return false;
	}
}

bool Input::getKey(int keyCode) {
	if (state[keyCode] == keyDown || state[keyCode] == keyDownRep) {
		return true;
	}
	else {
		return false;
	}
}

bool Input::getMouseButtonDown(int button)  //button ��ȣ, 0 �� ����, 1 �� ������, 2 �� ���..���콺��ư ��ȣ
{
	if (button == 0) {
		return getKeyDown(VK_LBUTTON);
	}
	else if (button == 1) {

		return getKeyDown(VK_RBUTTON);
	}
	else if (button == 2) {

		return getKeyDown(VK_MBUTTON);
	}
	else {
		return false;
	}
}

bool Input::getMouseButtonUp(int button) {
	if (button == 0) {
		return getKeyUp(VK_LBUTTON);
	}
	else if (button == 1) {

		return getKeyUp(VK_RBUTTON);
	}
	else if (button == 2) {

		return getKeyUp(VK_MBUTTON);
	}
	else {
		return false;
	}
}

bool Input::getMouseButton(int button) {
	if (button == 0) {
		return getKey(VK_LBUTTON);
	}
	else if (button == 1) {

		return getKey(VK_RBUTTON);
	}
	else if (button == 2) {

		return getKey(VK_MBUTTON);
	}
	else {
		return false;
	}
}
