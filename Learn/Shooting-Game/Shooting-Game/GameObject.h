#pragma once

#include <iostream>
#include <string>

#include "BoxCollider.h"

using namespace std;

class GameObject {
private:
	string tag;
	string name;
	bool active;
	float posX;
	float posY;
	BoxCollider collider;

public:
	GameObject();
	GameObject(string _tag, string _name, bool _active, float _posX, float _posY);
	virtual ~GameObject();

	string GetTag();
	string GetName();
	bool GetActive();
	float GetPosX();
	float GetPosY();
	BoxCollider GetCollider();

	void AddBoxCollider(float x, float y, float width, float height);

	virtual void Start();
	virtual	void Update();
	virtual void Draw();

	virtual void DrawCollider();

	void Translate(float _deltaX, float _deltaY);

	virtual void OnTrriger(GameObject * other);
};