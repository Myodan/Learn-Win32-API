#include "framework.h"

Ayako::Ayako(string _tag, string _name, bool _active, float _posX, float _posY, float _animDelay) :
	Animation(_tag, _name, _active, _posX, _posY, _animDelay) {
	state = down;
	speed = 0.0f; //100.0f;
	downPosY = 80;
}

Ayako::~Ayako() {

}

void Ayako::Start() {
	SetSpriteSet(CreateImgSet("Asset/Àû±â1.bmp", 2, 1, { 0, 280, 200, 420 }, { 1, 1, 9, 2 }));
	downPosY = downPosY + Random::Range(-50, 50);
	AddBoxCollider(0, 0, 190, 137);
}

void Ayako::Update() {
	float d = speed * Timer::GetDeltaTime();

	if (state == right) {
		Translate(d, 0);

		if (GetPosX() > BG_WIDTH - 190) {
			state = left;
		}
	}
	else if (state == left) {

		Translate(-d, 0);

		if (GetPosX() < 0) {
			state = right;
		}
	}
	else if (state == down) {

		Translate(0, d);
		if (GetPosY() > downPosY) {
			state = (State)Random::Range(1, 2);
		}
	}
}

void Ayako::OnTrriger() {

}
