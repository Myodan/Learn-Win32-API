#include "framework.h"

Background::Background() {

}

Background::Background(string _tag, string _name, bool _active, float _posX, float _posY) : Sprite(_tag, _name, _active, _posX, _posY) {

}

Background::~Background() {

}

void Background::Start() {
	SetSprite("Asset/¹è°æ1.bmp");
}

void Background::Update() {
	if (GetActive() == false)
		return;

}