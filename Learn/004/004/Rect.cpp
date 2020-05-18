#include "Rect.h"

Rect::Rect() {
	this->left = NULL;
	this->top = NULL;
	this->right = NULL;
	this->bottom = NULL;
}

Rect::Rect(int left, int top, int right, int bottom) {
	this->left = left;
	this->top = top;
	this->right = right;
	this->bottom = bottom;
}

Rect::~Rect() {

}

int Rect::GetLeft() {
	return left;
}

int Rect::GetTop() {
	return top;
}

int Rect::GetRight() {
	return right;
}

int Rect::GetBottom() {
	return bottom;
}