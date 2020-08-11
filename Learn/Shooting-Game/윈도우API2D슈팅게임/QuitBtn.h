#pragma once

#include "Button.h"

class QuitBtn : public Button {
private:

public:
	QuitBtn(bool active, float px, float py);
	~QuitBtn();

	void onClick();
};