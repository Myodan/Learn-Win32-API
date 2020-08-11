#include "framework.h"

EnergyBar::EnergyBar(float px, float py)
	:Sprite("UI", "에너지바", true, px, py) {

	readBMP("Asset/UI/HP.bmp", &bar);
	fillAmount = 0.0f;
	valueText = new Text(L"100", 20, 0x00ffffff, 82, 5);
	addChildObj(valueText, 9);
}

EnergyBar::~EnergyBar() {
	delete[] bar.argb;
}

void EnergyBar::start() {
	setSprite("Asset/UI/HP_Bar.bmp");
}

void EnergyBar::draw() {
	Sprite::draw();
	drawBMP(getPx() + 2, getPy() + 3, &bar, fillAmount);
}

void EnergyBar::setFillAmount(float fillAmount) {
	this->fillAmount = fillAmount;
}

float EnergyBar::getFillAmount() {
	return fillAmount;
}

void EnergyBar::setValue(float value) {
	valueText->setText(to_wstring((int)value));
}