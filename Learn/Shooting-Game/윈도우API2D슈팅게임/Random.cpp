#include "framework.h"

void Random::init() {
	srand((unsigned int)time(nullptr));
}

int Random::range(int min, int max) {
	int r = rand() % (max - min + 1) + min;
	return r;
}