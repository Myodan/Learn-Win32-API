#pragma once

#include "GameObject.h"

class SpawnManager : public GameObject {
private:
	float spawnTimer;
	float spawnDelay;

	int pat[10][5] = { {0,0,1,0,0},
					   {0,1,0,1,0},
					   {1,0,0,0,1},
					   {0,0,2,0,0},
					   {1,0,0,0,1},

					   {0,1,0,1,0},
					   {1,0,1,0,1},
					   {0,0,2,0,0},
					   {1,0,0,0,0},
					   {1,0,0,0,1}
	};

	int index;

public:
	SpawnManager(float px, float py);
	~SpawnManager();

	void update();
};
