#include "framework.h"

QuitBtn::QuitBtn(bool active, float px, float py)
	:Button("Asset/Title/BTN_QUIT.bmp", active, px, py) {

}

QuitBtn::~QuitBtn() {

}

void QuitBtn::onClick() {
	Application::quit();
}