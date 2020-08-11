#include "framework.h"

MiniPauseBtn::MiniPauseBtn(bool active, float px, float py)
	:Button("Asset/UI/btnPause.bmp", active, px, py) {

}

MiniPauseBtn::~MiniPauseBtn() {

}

void MiniPauseBtn::onClick() {
	GameManager::setPaused(!GameManager::getPaused());
}