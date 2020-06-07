#include "framework.h"

void Random::Init() {
	srand((unsigned int)time(NULL));
}

int Random::Range(int min, int max) {
	return rand() % (max - min + 1) + min;
}