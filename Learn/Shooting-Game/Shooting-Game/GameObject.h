#pragma once

#include <iostream>
#include <string>

using namespace std;

class GameObject {
private:
	string tag;
	string name;
	bool active;
	float posX;
	float posY;

public:
	GameObject();
	GameObject(string _tag, string _name, bool _active, float _posX, float _posY);
	virtual ~GameObject();

	string GetTag();
	string GetName();
	bool GetActive();
	float GetPosX();
	float GetPosY();

	virtual void Start();
	virtual	void Update();
	virtual void Draw();

	void Translate(float _deltaX, float _deltaY);
};