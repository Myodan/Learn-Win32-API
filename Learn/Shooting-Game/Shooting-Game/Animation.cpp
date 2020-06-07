#include "framework.h"

Animation::Animation(string _tag, string _name, bool _active, float _posX, float _posY, float _animDelay) : Sprite(_tag, _name, _active, _posX, _posY) {
	index = 0;
	animDelay = _animDelay;
	animTimer = 0;
}
Animation::~Animation() {

}

void Animation::Draw() {
	Sprite::Draw();

	animTimer = animTimer + Timer::GetDeltaTime();

	if (animTimer < animDelay) {
		return;
	}

	SetSprite(&spriteSet[index++]);

	if (index >= _msize(spriteSet) / sizeof(Image)) {
		index = 0;
	}

	animTimer = 0;
}

Image * Animation::CreateImgSet(string path, int numX, int numY, RECT position, RECT border) {
	int size = numX * numY;
	Image * newImgSet = new Image[size];

	for (int i = 0; i < numY; i++) {
		for (int j = 0; j < numX; j++) {
			int width = position.right - position.left;
			int height = position.bottom - position.top;

			cout << width * j << ", " << height * i << ", " << width << ", " << height << endl;
			MyLoadBitmap(
				&newImgSet[numX * i + j],
				path.data(),
				position.left + width * j + border.left,
				position.top + height * i + border.top,
				width - border.right - border.left,
				height - border.bottom - border.top
			);
		}
	}

	return newImgSet;
}

void Animation::SetSpriteSet(Image * img) {
	spriteSet = img;
}