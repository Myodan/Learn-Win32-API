#include "framework.h"

GameObject::GameObject() {
	tag = "";
	name = "";
	active = 0;
	posX = 0;
	posY = 0;
	alive = true;
}


GameObject::GameObject(string _tag, string _name, bool _active, float _posX, float _posY) {
	tag = _tag;
	name = _name;
	active = _active;
	posX = _posX;
	posY = _posY;
	alive = true;
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

bool GameObject::GetAlive() {
	return alive;
}

float GameObject::GetPosX() {
	return posX;
}

float GameObject::GetPosY() {
	return posY;
}

void GameObject::SetDead() {
	alive = false;
}

BoxCollider GameObject::GetCollider() {
	return collider;
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

	DrawRect((int)x0, (int)y0, (int)x1, (int)y1, 100, 255, 100);
}

void GameObject::OnTrriger(GameObject * other) {
	
}