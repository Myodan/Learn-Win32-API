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

vector<BoxCollider *> * GameObject::GetCollider() {
	return &collider;
}

void GameObject::Start() {

}

void GameObject::Update() {
	if (GetActive() == false)
		return;

}

void GameObject::Draw() {

}

void GameObject::Translate(float dx, float dy) {
	posX += dx;
	posY += dy;

	for (int i = 0; i < collider.size(); i++) {
		BoxCollider * col = collider.at(i);
		col->Translate(dx, dy);
	}
}

void GameObject::AddBoxCollider(float x, float y, float width, float height) {
	collider.push_back(new BoxCollider(posX + x, posY + y, width, height));
}

void GameObject::DrawCollider() {
	for (int i = 0; i < collider.size(); i++) {

		BoxCollider * col = collider.at(i);

		float x = col->GetX();
		float y = col->GetY();
		float width = col->GetWidth();
		float height = col->GetHeight();

		float x0 = x;
		float y0 = y;
		float x1 = x + width;
		float y1 = y + height;

		DrawRect(x0, y0, x1, y1, 100, 255, 100);
	}
}

void GameObject::OnTrriger(GameObject * other) {
	
}