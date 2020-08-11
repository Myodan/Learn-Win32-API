#pragma once

#include "Button.h"

class StartBtn : public Button {
private:
public:
	StartBtn(bool active, float px, float py);
	~StartBtn();

	void onClick();
};