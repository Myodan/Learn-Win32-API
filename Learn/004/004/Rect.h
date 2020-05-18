#pragma once

#include <iostream>

class Rect {
private:
	int left, top;
	int right, bottom;

public:
	Rect();
	Rect(int left, int top, int right, int bottom);
	virtual ~Rect();

	int GetLeft();
	int GetTop();
	int GetRight();
	int GetBottom();
};