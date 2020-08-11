#pragma once

#include <string>
#include <vector>

#include "BoxCollider.h"

using namespace std;

class GameObject {
private:
	string tag;
	string name;
	bool active;
	bool alive;

	float px, py;

	vector<BoxCollider> collider;
	GameObject * parent;
	vector<GameObject *> childObjs;

public:
	GameObject(string tag, string name, bool active, float px, float py);
	virtual ~GameObject();

	virtual void start();
	virtual void update();
	virtual void draw();

	void drawCollider();

	string getTag();
	string getName();
	bool getActive();
	bool getAlive();
	GameObject * getParent();

	float getPx();
	float getPy();

	void setTag(string tag);
	void setName(string name);
	void setActive(bool active);
	void setDead();
	void setParent(GameObject * obj);

	void addBoxCollider(float x, float y, float width, float height);
	void addChildObj(GameObject * obj, int order);
	void deleteChildObj(GameObject * obj);

	vector<BoxCollider> getCollider();
	vector<GameObject *> * getChildObjs();
	GameObject * getChildObj(string tag);
	GameObject * getChildObjByName(string name);

	void translate(float dx, float dy);

	virtual void onTrigger(GameObject * other);
};
