#include "framework.h"

Animation::Animation(string tag, string name, bool active, float px, float py)
	:Sprite(tag, name, active, px, py) {
	this->index = 0;
	this->anim = 0;

	this->animTimer = 0.0f;
	this->animDelay = 0.05f;

	this->loop = true;
}

Animation::~Animation() {
	////스프라이트..삭제 방지하기//////////
	setDelSprite(false);

	for (int a = 0; a < MAX_ANIM; a++) {
		for (int i = 0; i < image[a].size(); i++) {
			Image img = image[a].at(i);
			delete[] img.argb;
		}
	}

}


void Animation::addSprite(const char * fileName) {
	Image img;
	readBMP(fileName, &img);
	image[0].push_back(img);

	if (image[0].size() == 1) {
		setSprite(image[0].at(0));
	}
}

void Animation::addSprite(const char * fileName, int x, int y, int width, int height) {
	Image img;

	readBMPRect(fileName, &img, x, y, width, height);
	image[0].push_back(img);

	if (image[0].size() == 1)   //첫번째 애니메이션 이미지는 스프라이트에..지정함
	{
		setSprite(image[0].at(0));
	}
}


void Animation::addSprite(const char * fileName, int anim) {
	Image img;
	readBMP(fileName, &img);
	image[anim].push_back(img);

	if (image[0].size() == 1) {
		setSprite(image[0].at(0));
	}
}

void Animation::addSprite(const char * fileName, int x, int y, int width, int height, int anim) {
	Image img;

	readBMPRect(fileName, &img, x, y, width, height);
	image[anim].push_back(img);

	if (image[0].size() == 1)
	{
		setSprite(image[0].at(0));
	}
}

void Animation::setAnimDelay(float animDelay) {
	this->animDelay = animDelay;
}

void Animation::setLoop(bool loop) {
	this->loop = loop;
}

void Animation::setAnim(int anim) {
	if (this->anim != anim) {
		this->anim = anim;
		this->index = 0;
	}
}

int Animation::getAnim() {
	return anim;
}

void Animation::draw() {
	animTimer = animTimer + Time::getDeltaTime();

	if (animTimer >= animDelay) {
		setSprite(image[anim].at(index));

		index++;

		if (index >= image[anim].size()) {
			if (loop == true) {
				index = 0;  //처음 이미지부터..다시 시작
			}
			else {
				index = (int)image[anim].size() - 1; //마지막 .. 이미지로..계속 유지
			}
		}

		animTimer = 0;
	}

	//////부모 클래스(Sprite)의 draw를 강제(명시적으로)..호출하기///////
	Sprite::draw();
}