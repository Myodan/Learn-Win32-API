#pragma once

class GameManager {
private:
	static int  ayacoCount;
	static int  stealthCount;
	static bool bossDead;
	static int  playerLife;
	static bool paused;
	static int  score;

	static GameObject * uiMenu;
	static GameObject * uiScoreText;
	static GameObject * uiEnergyBar;
	static GameObject * uiEnergyBarText;
	static GameObject * uiHealthBar;
	static GameObject * uiHealthBarText;
	static GameObject * uiPlayerLifeIcon[3];
	static GameObject * uiBombIcon[5];

public:
	static void init();
	static void initUI();

	static int  getAyacoCount();
	static int  getStealthCount();

	static void setAyacoCount(int ayacoCount);
	static void incAyacoCount();
	static void decAyacoCount();

	static void setStealthCount(int stealthCount);
	static void incStealthCount();
	static void decStealthCount();

	static void setBossDead();
	static bool getBossDead();

	static void setPaused(bool paused);
	static bool getPaused();

	static void addScore(int value);
	static void playerRespawn();
	static void playerLifeIconRefresh(int playerLife);
	static void bombIconRefresh(int bombNum);
	static void energyBarRefresh(float fillAmount);
	static void healthBarRefresh(float fillAmount);
};