#include <iostream>
#include <windows.h>

#include "Input.h"

using namespace std;

int main() {
	while (true) {
		Input::Update();

		if (Input::GetKeyDown(VK_SPACE)) {
			cout << "�����̽��ٰ� ����" << endl;
		}

		if (Input::GetKeyUp(VK_SPACE)) {
			cout << "�����̽��ٰ� ����" << endl;
		}
	}

	return 0;
}