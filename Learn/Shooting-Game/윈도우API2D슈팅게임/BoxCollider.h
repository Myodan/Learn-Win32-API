#pragma once

class BoxCollider
{
private:
	///�ڽ� ��ǥ�� ����///
	float x, y;          //���� ���� ��ǥ
	float width, height; //���� ����, ���� ����

public:

	BoxCollider();
	BoxCollider(float x, float y, float width, float height);

	~BoxCollider();

	/////�ڽ� �浹ü ����////
	float getX();
	float getY();
	float getWidth();
	float getHeight();

	/////�ڽ� �浹ü..�̵� �Լ�//////
	void translate(float dx, float dy);
};