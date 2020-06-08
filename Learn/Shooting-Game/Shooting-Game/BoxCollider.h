#pragma once

class BoxCollider {
private:
	float x;
	float y;
	float width;
	float height;

public:
	BoxCollider();
	BoxCollider(float x, float y, float width, float height);
	virtual ~BoxCollider();

	float GetX();
	float GetY();
	float GetWidth();
	float GetHeight();
};