#include "framework.h"

PlayerBullet::PlayerBullet() : Sprite() {
	speed = NULL;
	index = NULL;
}

PlayerBullet::PlayerBullet(string _tag, string _name, bool _active, float _posX, float _posY, float _speed) : Sprite(_tag, _name, _active, _posX, _posY) {
	speed = _speed;
	index = 0;
}

PlayerBullet::~PlayerBullet() {

}

void PlayerBullet::Start() {
	for (int i = 0; i < sizeof(image) / sizeof(Image); i++) {
		MyLoadBitmap(&image[i], "Asset/ÆÒÅÒºí¸´.bmp", 17 * i, 0, 16, 48);
	}

	SetSprite(&image[0]);
}

void PlayerBullet::Update() {
	if (GetPosY() <= -30.0f) {
		ObjectManager::Delete(this);
		return;
	}

	if (index != 8) {
		SetSprite(&image[index++]);
	}

	float dist = speed * Timer::GetDeltaTime();
	Translate(0, -dist);
}