#include "framework.h"

SpawnManager::SpawnManager(float px, float py)
	:GameObject("스폰매니저", "스폰매니저", true, px, py) {
	this->spawnTimer = 0;
	this->spawnDelay = 5;
	this->index = 0;
}

SpawnManager::~SpawnManager() {

}

void SpawnManager::update() {
	int ayaco = GameManager::getAyacoCount();
	int stealth = GameManager::getStealthCount();

	if (GameManager::getAyacoCount() < 3 && stealth == 0) {
		spawnTimer = spawnTimer + Time::getDeltaTime();

		if (spawnTimer > spawnDelay) {
			float px = getPx();
			float py = getPy();

			float x[5] = { -295, -195, -95, 5, 105 };

			for (int i = 0; i < 5; i++) {
				int type = pat[index][i];
				if (type == 1) {
					ObjectManager::addGameObject(new Ayako(px + x[i], py), 2);
					GameManager::incAyacoCount();
				}
				else if (type == 2) {
					ObjectManager::addGameObject(new Stealth(px + x[i], py), 2);
					GameManager::incStealthCount();
				}
			}

			index++;

			if (index >= 10) {
				ObjectManager::addGameObject(new Boss(-6, -200), 3);
				ObjectManager::destroy(this);
			}

			spawnTimer = 0;
		}
	}
}