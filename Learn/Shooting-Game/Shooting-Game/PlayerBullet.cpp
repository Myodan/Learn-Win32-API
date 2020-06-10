#include "framework.h"

PlayerBullet::PlayerBullet() : Sprite() {
	speed = NULL;
	index = NULL;
	type = NULL;
}

PlayerBullet::PlayerBullet(string _tag, string _name, bool _active, float _posX, float _posY, float _speed, int _type) : Sprite(_tag, _name, _active, _posX, _posY) {
	speed = _speed;
	index = 0;
	type = _type;
}

PlayerBullet::~PlayerBullet() {

}

void PlayerBullet::Start() {
	for (int i = 0; i < sizeof(image) / sizeof(Image); i++) {
		MyLoadBitmap(&image[i], "Asset/ÆÒÅÒºí¸´.bmp", 17 * i, 0, 16, 48);
	}

	SetSprite(&image[0]);
	AddBoxCollider(3, 10, 10, 35);
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

	switch (type) {
	case 1:
	{
		Translate(0, -dist);
	}
	break;
	case 2:
	{
		Translate(-dist / 5, -dist);
	}
	break;
	case 3:
	{
		Translate(dist / 5, -dist);
	}
	break;
	}
	
}

void PlayerBullet::OnTrriger(GameObject * other) {

}