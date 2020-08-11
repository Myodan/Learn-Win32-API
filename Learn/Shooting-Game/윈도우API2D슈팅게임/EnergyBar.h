#pragma once

#include "Sprite.h"
#include "Text.h"

class EnergyBar : public Sprite {
private:
	Image bar;
	float fillAmount;
	Text * valueText;

public:
	EnergyBar(float px, float py);
	~EnergyBar();

	void start();
	void draw();

	void setFillAmount(float fillAmount);
	float getFillAmount();

	void setValue(float value);
};