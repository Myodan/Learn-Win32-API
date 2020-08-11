#pragma once

#include "Button.h"

class MiniQuitBtn : public Button {
private:

public:
	MiniQuitBtn(bool active, float px, float py);
	~MiniQuitBtn();

	void onClick();
};