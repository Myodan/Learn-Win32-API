#pragma once

#include <stdlib.h>
#include <time.h>

class Random {
private:
	
public:
	static void Init();
	static int Range(int min, int max);
};