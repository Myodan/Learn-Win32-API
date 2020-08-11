#pragma once

class BoxCollider
{
private:
	///박스 좌표와 길이///
	float x, y;          //왼쪽 상태 좌표
	float width, height; //가로 길이, 세로 길이

public:

	BoxCollider();
	BoxCollider(float x, float y, float width, float height);

	~BoxCollider();

	/////박스 충돌체 게터////
	float getX();
	float getY();
	float getWidth();
	float getHeight();

	/////박스 충돌체..이동 함수//////
	void translate(float dx, float dy);
};