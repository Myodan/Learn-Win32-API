#include "framework.h"

int  GameManager::ayacoCount = 0;
int  GameManager::stealthCount = 0;
bool GameManager::bossDead = false;
int  GameManager::playerLife = 3;
bool GameManager::paused = false;
int  GameManager::score = 0;

GameObject * GameManager::uiMenu = nullptr;
GameObject * GameManager::uiScoreText = nullptr;
GameObject * GameManager::uiEnergyBar = nullptr;
GameObject * GameManager::uiEnergyBarText = nullptr;
GameObject * GameManager::uiHealthBar = nullptr;
GameObject * GameManager::uiHealthBarText = nullptr;
GameObject * GameManager::uiPlayerLifeIcon[3] = { nullptr, };
GameObject * GameManager::uiBombIcon[5] = { nullptr, };

void GameManager::init() {
	ayacoCount = 0;
	stealthCount = 0;
	bossDead = false;
	playerLife = 3;
	paused = false;
}

void GameManager::initUI() {
	if (uiMenu != nullptr) {
		delete uiMenu;
	}

	if (uiEnergyBar != nullptr) {
		delete uiEnergyBar;
	}

	if (*uiPlayerLifeIcon != nullptr) {
		for (int i = 0; i < 3; i++) {
			delete uiPlayerLifeIcon[i];
		}
	}

	if (*uiBombIcon != nullptr) {
		for (int i = 0; i < 5; i++) {
			delete uiBombIcon[i];
		}
	}

	ObjectManager::addGameObject(new MiniQuitBtn(true, BG_WIDTH - 60, 10), 8);
	ObjectManager::addGameObject(new MiniPauseBtn(true, BG_WIDTH - 115, 10), 8);


	/* UI 메뉴 */
	uiMenu = new  Menu(false, BG_WIDTH / 2 - (int)245 / 2, BG_HEIGHT / 2 - (int)241 / 2);
	ObjectManager::addGameObject(uiMenu, 8);

	/* UI 점수 */
	uiScoreText = new Text(L"점수 /  0", 24, 0x00ffffff, 2, 2);
	ObjectManager::addGameObject(uiScoreText, 8);

	/* UI 체력바 */
	uiHealthBar = new EnergyBar(50, 28);
	ObjectManager::addGameObject(uiHealthBar, 8);
	uiHealthBarText = new Text(L"체력 /", 24, 0x00ffffff, 2, 30);
	ObjectManager::addGameObject(uiHealthBarText, 8);

	/* UI 마나바 */
	uiEnergyBar = new EnergyBar(50, 56);
	ObjectManager::addGameObject(uiEnergyBar, 8);
	uiEnergyBarText = new Text(L"마나 /", 24, 0x00ffffff, 2, 58);
	ObjectManager::addGameObject(uiEnergyBarText, 8);

	for (int i = 0; i < GameManager::playerLife; i++) {
		uiPlayerLifeIcon[i] = new PlayerLifeIcon((float)50 * i + 5, (float)80);
		ObjectManager::addGameObject(uiPlayerLifeIcon[i], 8);
	}

	for (int i = 0; i < 5; i++) {
		uiBombIcon[i] = new BombIcon((float)27 * i + 5, (float)BG_HEIGHT - 45);
		ObjectManager::addGameObject(uiBombIcon[i], 8);
	}
}

int GameManager::getAyacoCount() {
	return ayacoCount;
}

int GameManager::getStealthCount() {
	return stealthCount;
}

void GameManager::setAyacoCount(int ayacoCount) {
	GameManager::ayacoCount = ayacoCount;
}

void GameManager::incAyacoCount() {
	ayacoCount++;
}

void GameManager::decAyacoCount() {
	ayacoCount--;
}

void GameManager::setStealthCount(int stealthCount) {
	GameManager::stealthCount = stealthCount;
}

void GameManager::incStealthCount() {
	stealthCount++;
}

void GameManager::decStealthCount() {
	stealthCount--;
}

void GameManager::setBossDead() {
	bossDead = true;
}

bool GameManager::getBossDead() {
	return bossDead;
}

void GameManager::setPaused(bool paused) {
	GameManager::paused = paused;
	Time::setTimeScale(!paused);
	uiMenu->setActive(paused);
}

bool GameManager::getPaused() {
	return paused;
}


void GameManager::playerRespawn() {
	if (!playerLife) {
		ObjectManager::addGameObject(new GameOverSprite(BG_WIDTH / 2 - 210, BG_HEIGHT / 2 - 81), 5);
		Time::setTimeScale(0);
		return;
	}

	playerLifeIconRefresh(--playerLife);
	ObjectManager::addGameObject(new Player(200, 800), 2);
}

void GameManager::playerLifeIconRefresh(int playerLife) {
	for (int i = 0; i < 3; i++) {
		uiPlayerLifeIcon[i]->setActive(playerLife > i ? true : false);
	}
}

void GameManager::bombIconRefresh(int bombNum) {
	for (int i = 0; i < 5; i++) {
		uiBombIcon[i]->setActive(bombNum > i ? true : false);
	}
}

void GameManager::energyBarRefresh(float fillAmount) {
	if (fillAmount < 0) {
		return;
	}

	((EnergyBar *)uiEnergyBar)->setFillAmount(fillAmount);
	((EnergyBar *)uiEnergyBar)->setValue(fillAmount * 100);
}

void GameManager::healthBarRefresh(float fillAmount) {
	if (fillAmount < 0) {
		return;
	}

	((EnergyBar *)uiHealthBar)->setFillAmount(fillAmount);
	((EnergyBar *)uiHealthBar)->setValue(fillAmount * 100);
}

void GameManager::addScore(int value) {
	GameManager::score += value;
	((Text *)uiScoreText)->setText(L"점수 /  " + to_wstring(GameManager::score));
}