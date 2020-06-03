#include "framework.h"

Player::Player() : Sprite() {
	speed = NULL;
	fireDelay = NULL;
	fireTimer = NULL;
	index = NULL;
}

Player::Player(string _tag, string _name, bool _active, float _posX, float _posY, float _speed, float _fireDelay) : Sprite(_tag, _name, _active, _posX, _posY) {
	speed = _speed;
	fireDelay = _fireDelay;
	fireTimer = 0;
	index = 3;
}

Player::~Player() {

}

void Player::Start() {
	for (int i = 0; i < sizeof(image) / sizeof(Image); i++) {
		MyLoadBitmap(&image[i], "Asset/ÆÒÅÒÀÌµ¿2.bmp", 64 * i, 82, 62, 80);
	}

	SetSprite("Asset/ÆÒÅÒÀÌµ¿2.bmp", 192, 62, 62, 80);
}

void Player::Update() {
	if (GetActive() == false) {
		return;
	}

	Move();
	Fire();
}

void Player::Move() {
	float dist = speed * Timer::GetDeltaTime();

	if (GetAsyncKeyState(VK_RIGHT) != 0) {
		if (index < 6) {
			index++;
		}

		if (GetPosX() <= BG_WIDTH - 62) {
			Translate(dist, 0);
		}
	}

	if (GetAsyncKeyState(VK_LEFT) != 0) {
		if (index > 0) {
			index--;
		}

		if (GetPosX() >= 0) {
			Translate(-dist, 0);
		}

	}

	if (GetAsyncKeyState(VK_DOWN) != 0) {
		if (GetPosY() <= BG_HEIGHT - 80) {
			Translate(0, dist);
		}
	}

	if (GetAsyncKeyState(VK_UP) != 0) {
		if (GetPosY() >= 0) {
			Translate(0, -dist);
		}
	}

	if (GetAsyncKeyState(VK_RIGHT) == 0 && GetAsyncKeyState(VK_LEFT) == 0) {
		if (index > 3) {
			index--;
		}
		else if (index < 3) {
			index++;
		}
		else {
			index = 3;
		}
	}

	SetSprite(&image[index]);
}

void Player::Fire() {
	if (GetAsyncKeyState(VK_SPACE) != 0) {
		if (fireTimer >= fireDelay) {
			ObjectManager::Add(new PlayerBullet("Bullet", "Bullet", true, GetPosX() + 23.0f, GetPosY() - 20.0f, 400.0f));
			fireTimer = 0;
		}
	}

	fireTimer += Timer::GetDeltaTime();
}