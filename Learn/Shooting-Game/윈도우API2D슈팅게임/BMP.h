#pragma once

struct Image {
	int width;
	int height;
	unsigned int * argb;
};

int readBMP(const char * fileName, Image * img);
int readBMPRect(const char * fileName, Image * img, int x, int y, int width, int height);

void drawBMP(float px, float py, Image * img);
void drawBMP(float px, float py, Image * img, float fillAmount);