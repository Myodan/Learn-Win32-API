#include "BoxCollider.h"

BoxCollider::BoxCollider()
{
	this->x = 0;
	this->y = 0;

	this->width  = 0;
	this->height = 0;
}

BoxCollider::BoxCollider(float x, float y, float width, float height)
{
	this->x = x;
	this->y = y;

	this->width  = width;
	this->height = height;
}

BoxCollider::~BoxCollider()
{}

float BoxCollider::getX()
{
	return x;
}

float BoxCollider::getY()
{
	return y;
}

float BoxCollider::getWidth()
{
	return width;
}

float BoxCollider::getHeight()
{
	return height;
}

void BoxCollider::translate(float dx, float dy)
{
	x = x + dx;
	y = y + dy;
}