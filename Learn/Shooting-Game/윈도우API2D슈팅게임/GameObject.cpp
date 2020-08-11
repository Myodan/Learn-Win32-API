#include "framework.h"

GameObject::GameObject(string tag, string name, bool active, float px, float py) {
	this->tag = tag;
	this->name = name;
	this->active = active;
	this->alive = true;

	this->px = px;
	this->py = py;
	this->parent = nullptr;
}

GameObject::~GameObject() {

}

void GameObject::start() {

}

void GameObject::update() {

}

void GameObject::draw() {

}

void GameObject::drawCollider() {
	for (int i = 0; i < collider.size(); i++) {
		BoxCollider c = collider.at(i);

		float x = c.getX();
		float y = c.getY();

		float width = c.getWidth();
		float height = c.getHeight();

		float x0 = x;
		float y0 = y;
		float x1 = x + width;
		float y1 = y + height;

		drawRect((int)x0, (int)y0, (int)x1, (int)y1, 255, 0, 0);
	}
}

string GameObject::getTag() {
	return tag;
}

string GameObject::getName() {
	return name;
}

bool GameObject::getActive() {
	return active;
}

bool GameObject::getAlive() {
	return alive;
}

GameObject * GameObject::getParent() {
	return parent;
}

float GameObject::getPx() {
	return px;
}

float GameObject::getPy() {
	return py;
}

void GameObject::setTag(string tag) {
	this->tag = tag;
}

void GameObject::setName(string name) {
	this->name = name;
}

void GameObject::setActive(bool active) {
	this->active = active;
	for (int i = 0; i < childObjs.size(); i++) {
		childObjs.at(i)->setActive(active);
	}
}

void GameObject::setDead() {
	this->alive = false;

	if (parent) {
		parent->deleteChildObj(this);
	}
		
	while (childObjs.size()) {
		childObjs.at(0)->setDead();
	}
}

void GameObject::setParent(GameObject * obj) {
	parent = obj;
}

void GameObject::translate(float dx, float dy) {
	px = px + dx;
	py = py + dy;

	for (int i = 0; i < collider.size(); i++) {
		collider.at(i).translate(dx, dy);
	}

	for (int i = 0; i < childObjs.size(); i++) {
		childObjs.at(i)->translate(dx, dy);
	}
}

void GameObject::addBoxCollider(float x, float y, float width, float height) {
	collider.push_back(BoxCollider(px + x, py + y, width, height));
}

void GameObject::addChildObj(GameObject * obj, int order) {
	childObjs.push_back(obj);
	ObjectManager::addGameObject(obj, order);
	obj->parent = this;
	obj->translate(px, py);
}

void GameObject::deleteChildObj(GameObject * obj) {
	for (int i = 0; i < childObjs.size(); i++) {
		if (childObjs.at(i) == obj) {
			childObjs.erase(childObjs.begin() + i);
			return;
		}
	}
}

vector<BoxCollider> GameObject::getCollider() {
	return collider;
}

vector<GameObject *> * GameObject::getChildObjs() {
	return &childObjs;
}

GameObject * GameObject::getChildObj(string tag) {
	for (int i = 0; i < childObjs.size(); i++) {
		GameObject * obj = childObjs.at(i);
		if (obj->getTag() == tag) {
			return obj;
		}
	}

	return nullptr;
}

GameObject * GameObject::getChildObjByName(string name) {
	for (int i = 0; i < childObjs.size(); i++) {
		GameObject * obj = childObjs.at(i);
		if (obj->getName() == name) {
			return obj;
		}
	}

	return nullptr;
}

void GameObject::onTrigger(GameObject * other) {
}