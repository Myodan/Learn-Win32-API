#include "framework.h"

BoxCollider::BoxCollider() {
	this->x = 0;
	this->y = 0;
	this->width = 0;
	this->height = 0;
}

BoxCollider::BoxCollider(float x, float y, float width, float height) {
	this->x = x;
	this->y = y;
	this->width = width;
	this->height = height;
}

BoxCollider::~BoxCollider() {

}

float BoxCollider::GetX() {
	return x;
}

float BoxCollider::GetY() {
	return y;
}

float BoxCollider::GetWidth() {
	return width;
}

float BoxCollider::GetHeight() {
	return height;
}