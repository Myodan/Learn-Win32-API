#pragma once

#include "GameObject.h"
#include "BMP.h"

class Sprite : public GameObject {
private:
	/////이미지 저장 구조체/////
	Image sprite;

	////스프라이트..삭제..판단 변수///
	bool delSprite;

public:
	Sprite(string tag, string name, bool active, float px, float py);
	~Sprite();

	///draw 함수 오버라이딩////
	void draw();

	///세터////
	void setSprite(string fileName);
	void setSprite(string fileName, int x, int y, int width, int height);
	void setSprite(Image image);

	Image * getSprite();

	///스플라이트 삭제..막기////
	void setDelSprite(bool delSprite);

	int getWidth();
	int getHeight();
};
