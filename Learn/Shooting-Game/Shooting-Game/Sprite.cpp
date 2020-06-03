#include "framework.h"

Sprite::Sprite() : GameObject(){
	sprite = new Image();
}

Sprite::Sprite(string _tag, string _name, bool _active, float _posX, float _posY) : GameObject(_tag, _name, _active, _posX, _posY){
	sprite = new Image();
}

Sprite::~Sprite(){
	delete[] sprite->argb;
}

Image *Sprite::GetSprite(){
	return sprite;
}

void Sprite::SetSprite(string _path){
	MyLoadBitmap(sprite, _path.data());
}

void Sprite::SetSprite(string _path, int _x, int _y, int _width, int _height){
	MyLoadBitmap(sprite, _path.data(), _x, _y, _width, _height);
}

void Sprite::SetSprite(Image *image){
	sprite = image;
}

void Sprite::Draw(){
	if(GetActive() == false){
		return;
	}

	MyDrawBitmap(sprite, GetPosX(), GetPosY());
}