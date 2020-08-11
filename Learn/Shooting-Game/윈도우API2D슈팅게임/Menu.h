#pragma once

#include "Button.h"

class Menu : public Sprite {
private:
public:
	Menu(bool active, float px, float py);
	virtual ~Menu();

	void start();
};

class ItemResume : public Button {
private:
public:
	ItemResume(bool active, float px, float py);
	virtual ~ItemResume();

	void onClick();
};

class ItemRetry : public Button {
private:
public:
	ItemRetry(bool active, float px, float py);
	virtual ~ItemRetry();

	void onClick();
};

class ItemTitle : public Button {
private:
public:
	ItemTitle(bool active, float px, float py);
	virtual ~ItemTitle();

	void onClick();
};

class ItemQuit : public Button {
private:
public:
	ItemQuit(bool active, float px, float py);
	virtual ~ItemQuit();

	void onClick();
};