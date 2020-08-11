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

	static bool getMouseButtonDown(int button);  //button 번호, 0 은 왼쪽, 1 은 오른쪽, 2 는 가운데..마우스버튼 번호
	static bool getMouseButtonUp(int button);
	static bool getMouseButton(int button);
};