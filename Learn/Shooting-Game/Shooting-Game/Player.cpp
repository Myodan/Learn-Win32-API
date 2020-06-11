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
	AddBoxCollider( 9, 43, 44, 14);
	AddBoxCollider(27,  8,  8, 65);
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

	if (Input::GetKey(VK_RIGHT)) {
		if (index < 6) {
			index++;
		}

		if (GetPosX() <= BG_WIDTH - 62) {
			Translate(dist, 0);
		}
	}

	if (Input::GetKey(VK_LEFT)) {
		if (index > 0) {
			index--;
		}

		if (GetPosX() >= 0) {
			Translate(-dist, 0);
		}

	}

	if (Input::GetKey(VK_DOWN)) {
		if (GetPosY() <= BG_HEIGHT - 80) {
			Translate(0, dist);
		}
	}

	if (Input::GetKey(VK_UP)) {
		if (GetPosY() >= 0) {
			Translate(0, -dist);
		}
	}

	if (Input::GetKey(VK_RIGHT) == false && Input::GetKey(VK_LEFT) == false) {
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
	if (Input::GetKey(VK_SPACE)) {
		if (fireTimer >= fireDelay) {
			ObjectManager::Instantiate(new PlayerBullet("Bullet", "BulletC", true, GetPosX() + 8.0f, GetPosY() - 40.0f, 650.0f, 1));
			ObjectManager::Instantiate(new PlayerBullet("Bullet", "BulletL", true, GetPosX() + 23.0f, GetPosY() - 40.0f, 650.0f, 2));
			ObjectManager::Instantiate(new PlayerBullet("Bullet", "BulletR", true, GetPosX() + 38.0f, GetPosY() - 40.0f, 650.0f, 3));
			fireTimer = 0;
		}
	}

	fireTimer += Timer::GetDeltaTime();
}

void Player::OnTrriger(GameObject * other) {
	if (other->GetTag() == "Enemy") {
		ObjectManager::Destroy(this);
	}
}