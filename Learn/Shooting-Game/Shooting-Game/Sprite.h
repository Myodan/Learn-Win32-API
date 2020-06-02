#pragma once

#include "bitmap.h"

#include "GameObject.h"

using namespace std;

class Sprite : public GameObject{
private:
	Image *sprite;

public:
	Sprite();
	Sprite(string _tag, string _name, bool _active, float _posX, float _posY);
	virtual ~Sprite();

	Image *GetSprite();

	void SetSprite(string _path);
	void SetSprite(string _path, int _x, int _y, int _width, int _height);
	void SetSprite(Image *image);

	void Draw();
};