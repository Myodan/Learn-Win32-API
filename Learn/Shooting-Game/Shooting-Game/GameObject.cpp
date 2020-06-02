#include "framework.h"

GameObject::GameObject(){
	tag = "";
	name = "";
	active = NULL;
	posX = NULL;
	posY = NULL;
}

GameObject::GameObject(string _tag, string _name, bool _active, float _posX, float _posY){
	tag = _tag;
	name = _name;
	active = _active;
	posX = _posX;
	posY = _posY;
}

GameObject::~GameObject(){

}

string GameObject::GetTag(){
	return tag;
}

string GameObject::GetName(){
	return name;
}

bool GameObject::GetActive(){
	return active;
}

float GameObject::GetPosX(){
	return posX;
}

float GameObject::GetPosY(){
	return posY;
}

void GameObject::Start(){

}

void GameObject::Update(){
	if(GetActive() == false)
		return;

}

void GameObject::Draw(){

}

void GameObject::Translate(float _deltaX, float _deltaY){
	posX += _deltaX;
	posY += _deltaY;
}