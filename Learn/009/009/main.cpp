#include <iostream>
#include <windows.h>

#include "Input.h"

using namespace std;

int main() {
	while (true) {
		Input::Update();

		if (Input::GetKeyDown(VK_SPACE)) {
			cout << "스페이스바가 눌림" << endl;
		}

		if (Input::GetKeyUp(VK_SPACE)) {
			cout << "스페이스바가 놓임" << endl;
		}
	}

	return 0;
}