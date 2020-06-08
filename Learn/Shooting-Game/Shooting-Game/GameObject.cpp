#include "framework.h"

GameObject::GameObject() {
	tag = "";
	name = "";
	active = 0;
	posX = 0;
	posY = 0;
}


GameObject::GameObject(string _tag, string _name, bool _active, float _posX, float _posY) {
	tag = _tag;
	name = _name;
	active = _active;
	posX = _posX;
	posY = _posY;
}

GameObject::~GameObject() {

}

string GameObject::GetTag() {
	return tag;
}

string GameObject::GetName() {
	return name;
}

bool GameObject::GetActive() {
	return active;
}

float GameObject::GetPosX() {
	return posX;
}

float GameObject::GetPosY() {
	return posY;
}

void GameObject::Start() {

}

void GameObject::Update() {
	if (GetActive() == false)
		return;

}

void GameObject::Draw() {

}

void GameObject::Translate(float _deltaX, float _deltaY) {
	posX += _deltaX;
	posY += _deltaY;
}

void GameObject::AddBoxCollider(float x, float y, float width, float height) {
	collider = BoxCollider(x, y, width, height);
}

void GameObject::DrawCollider() {

	float x0 = GetPosX() + collider.GetX();
	float y0 = GetPosY() + collider.GetY();
	float x1 = x0 + collider.GetWidth();
	float y1 = y0 + collider.GetHeight();

	DrawRect(x0, y0, x1, y1, 100, 255, 100);
}