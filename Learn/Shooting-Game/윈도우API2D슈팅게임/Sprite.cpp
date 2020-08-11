#include "framework.h"

Sprite::Sprite(string tag, string name, bool active, float px, float py)
	:GameObject(tag, name, active, px, py) {

	this->delSprite = true;
}

Sprite::~Sprite() {
	if (delSprite == true) {
		delete[] sprite.argb;
	}
}

void Sprite::draw() {
	float px = getPx();
	float py = getPy();

	drawBMP(px, py, &sprite);
}

void Sprite::setSprite(string fileName) {
	readBMP(fileName.data(), &sprite);
}

void Sprite::setSprite(string fileName, int x, int y, int width, int height) {
	readBMPRect(fileName.data(), &sprite, x, y, width, height);
}

void Sprite::setSprite(Image image) {
	this->sprite = image;
}

void Sprite::setDelSprite(bool delSprite) {
	this->delSprite = delSprite;
}

Image * Sprite::getSprite() {
	return &sprite;
}

int Sprite::getWidth() {
	return sprite.width;
}

int Sprite::getHeight() {
	return sprite.height;
}