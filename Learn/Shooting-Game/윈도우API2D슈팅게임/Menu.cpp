#include "framework.h"

Menu::Menu(bool active, float px, float py) : Sprite("UI", "Menu", active, px, py){

}

Menu::~Menu() {

}

void Menu::start() {
	setSprite("Asset/UI/menubackground.bmp");

	addChildObj(new ItemResume(false, 5, 59 * 0 + 5), 8);
	addChildObj(new ItemRetry(false, 5, 59 * 1 + 5), 8);
	addChildObj(new ItemTitle(false, 5, 59 * 2 + 5), 8);
	addChildObj(new ItemQuit(false, 5, 59 * 3 + 5), 8);
}

#pragma region ItemResume

ItemResume::ItemResume(bool active, float px, float py) :
	Button("Asset/UI/resume.bmp", active, px, py) {

}

ItemResume::~ItemResume() {

}

void ItemResume::onClick() {
	GameManager::setPaused(false);
}

#pragma endregion

#pragma region ItemRetry

ItemRetry::ItemRetry(bool active, float px, float py) :
	Button("Asset/UI/retry.bmp", active, px, py) {

}

ItemRetry::~ItemRetry() {

}

void ItemRetry::onClick() {
	Time::setTimeScale(1.0f);
	SceneManager::loadScene(new GameScene());
}

#pragma endregion

#pragma region ItemTitle

ItemTitle::ItemTitle(bool active, float px, float py) :
	Button("Asset/UI/title.bmp", active, px, py) {

}

ItemTitle::~ItemTitle() {

}

void ItemTitle::onClick() {
	SceneManager::loadScene(new TitleScene());
	GameManager::setPaused(false);
}

#pragma endregion

#pragma region ItemQuit

ItemQuit::ItemQuit(bool active, float px, float py) :
	Button("Asset/UI/quit.bmp", active, px, py) {

}

ItemQuit::~ItemQuit() {

}

void ItemQuit::onClick() {
	Application::quit();
}

#pragma endregion