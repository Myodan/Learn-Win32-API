#pragma once

struct MousePosition { short x; short y; };

class Input {
private:
	enum State { keyDown = 0, keyDownRep = 1, keyUp = 2, keyUpRep = 3 };
	static int state[255];

public:
	static MousePosition mousePosition;

	static void init();
	static void update();

	static bool getKeyDown(int keyCode);
	static bool getKeyUp(int keyCode);
	static bool getKey(int keyCode);

	static bool getMouseButtonDown(int button);  //button ��ȣ, 0 �� ����, 1 �� ������, 2 �� ���..���콺��ư ��ȣ
	static bool getMouseButtonUp(int button);
	static bool getMouseButton(int button);
};