#pragma once

#include "GameObject.h"
#include "BMP.h"

class Sprite : public GameObject {
private:
	/////�̹��� ���� ����ü/////
	Image sprite;

	////��������Ʈ..����..�Ǵ� ����///
	bool delSprite;

public:
	Sprite(string tag, string name, bool active, float px, float py);
	~Sprite();

	///draw �Լ� �������̵�////
	void draw();

	///����////
	void setSprite(string fileName);
	void setSprite(string fileName, int x, int y, int width, int height);
	void setSprite(Image image);

	Image * getSprite();

	///���ö���Ʈ ����..����////
	void setDelSprite(bool delSprite);

	int getWidth();
	int getHeight();
};
