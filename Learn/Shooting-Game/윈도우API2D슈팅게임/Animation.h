#pragma once

#include <vector>
#include "Sprite.h"

#define MAX_ANIM 16

using namespace std;

class Animation : public Sprite {
private:
	vector<Image> image[MAX_ANIM];

	int index;
	int anim;

	float animTimer;
	float animDelay;

	bool loop;

public:
	Animation(string tag, string name, bool active, float px, float py);
	~Animation();

	void addSprite(const char * fileName);
	void addSprite(const char * fileName, int x, int y, int width, int height);
	void addSprite(const char * fileName, int anim);
	void addSprite(const char * fileName, int x, int y, int width, int height, int anim);

	void setAnimDelay(float animDelay);
	void setLoop(bool loop);
	void setAnim(int anim);

	int getAnim();

	void draw();
};