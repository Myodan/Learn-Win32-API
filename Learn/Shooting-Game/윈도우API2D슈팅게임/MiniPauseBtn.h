#pragma once

#include "Button.h"

class MiniPauseBtn : public Button {
private:

public:
	MiniPauseBtn(bool active, float px, float py);
	~MiniPauseBtn();

	void onClick();
};