#include "framework.h"

MiniQuitBtn::MiniQuitBtn(bool active, float px, float py)
	:Button("Asset/UI/btnExit.bmp", active, px, py) {

}

MiniQuitBtn::~MiniQuitBtn() {

}

void MiniQuitBtn::onClick() {
	Application::quit();
}