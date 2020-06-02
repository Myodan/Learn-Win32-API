#pragma once

#include <stdio.h>
#include <windows.h>

#include "graphic.h"

typedef struct image{
	int width;
	int height;
	unsigned int *argb;
} Image;

int MyLoadBitmap(Image *img, const char *path);
int MyLoadBitmap(Image *img, const char *path, int x, int y, int width, int height);
void MyDrawBitmap(Image *img, float px, float py);