#include "framework.h"

Player::Player(float px, float py) :
	Sprite("ÇÃ·¹ÀÌ¾î", "ÇÃ·¹ÀÌ¾î", true, px, py) {
	this->state = State::spawn;
	this->health = 100.0f;
	this->speed = 200.0f;
	this->power = 0;
	this->bombNum = 2;

	this->index = 3;

	this->fireTimer = 0.0f;
	this->fireDelay = 0.2f;

	this->shadowTimer = 0.0f;
	this->shadowDelay = 5.0f;

	this->shieldTimer = 0.0f;
	this->shieldHoldingTime = 3.0f;

	this->bombTimer = 0.0f;
	this->bombDelay = 1.5f;
}

Player::~Player() {

}

int Player::getPower() {
	return power;
}

void Player::setPower(int power) {
	this->power = power;
}

void Player::start() {
	GameManager::bombIconRefresh(bombNum);
	GameManager::healthBarRefresh(health / 100.0f);
	GameManager::energyBarRefresh(shadowTimer / shadowDelay);

	for (int i = 0; i < 7; i++) {
		readBMPRect("Asset/ÆÒÅÒÀÌµ¿2.bmp", &image[i], 64 * i, 0, 62, 80);
	}
	setSprite("Asset/ÆÒÅÒÀÌµ¿2.bmp", 192, 0, 62, 80);

	addBoxCollider(19, 8, 24, 65);
	addBoxCollider(9, 40, 44, 18);

	addChildObj(new JetFire(25, 70), 2);
	addChildObj(new Shield(-12, -10), 2);
}

void Player::update() {
	if (GameManager::getPaused()) {
		return;
	}

	if (state == State::spawn) {
		translate(0, -speed * Time::getDeltaTime());

		if (getPy() < 600.0f) {
			state = State::idle;
		}
	}
	else if (state == State::idle) {
		move();
		fire();
		shadow();
		shield();
		bomb();
	}

	if (GameManager::getBossDead()) {
		ObjectManager::addGameObject(new GoHome(getPx(), getPy()), 3);
		onDeath();
	}
}

void Player::fire() {
	if (Input::getKey(VK_SPACE) == true) {
		fireTimer = fireTimer + Time::getDeltaTime();

		if (fireTimer > fireDelay) {
			float px = getPx() + 25;
			float py = getPy() - 1;

			switch (power) {
			case 0:
			{
				ObjectManager::addGameObject(new PlayerBullet(px, py, 0), 3);
			}
			break;
			case 1:
			{
				ObjectManager::addGameObject(new PlayerBullet(px - 5, py, 0), 2);
				ObjectManager::addGameObject(new PlayerBullet(px + 5, py, 0), 2);
			}
			break;
			case 2:
			{
				ObjectManager::addGameObject(new PlayerBullet(px - 10, py, 1), 2);
				ObjectManager::addGameObject(new PlayerBullet(px, py - 5, 0), 2);
				ObjectManager::addGameObject(new PlayerBullet(px + 10, py, 2), 2);
			}
			break;
			default:
			{

			}
			break;
			}
			fireTimer = 0;
		}

	}
}

void Player::move() {
	float d = speed * Time::getDeltaTime();

	if (Input::getKey(VK_RIGHT) == true) {
		index++;

		if (index > 6) {
			index = 6;
		}

		setSprite(image[index]);

		if (getPx() < BG_WIDTH - 64) {
			translate(d, 0);
		}
	}

	if (Input::getKey(VK_LEFT) == true) {
		index--;

		if (index < 0) {
			index = 0;
		}

		setSprite(image[index]);

		if (getPx() > -2) {
			translate(-d, 0);
		}
	}

	if (Input::getKey(VK_RIGHT) != true && Input::getKey(VK_LEFT) != true) {
		index = 3;
		setSprite(image[index]);
	}

	if (Input::getKey(VK_UP) == true) {
		if (getPy() > 0) {
			translate(0, -d);
		}
	}

	if (Input::getKey(VK_DOWN) == true) {
		if (getPy() < BG_HEIGHT - 80) {
			translate(0, d);
		}
	}
}

void Player::shadow() {
	GameManager::energyBarRefresh(shadowTimer / shadowDelay);
	if (shadowTimer <= shadowDelay) {
		shadowTimer += Time::getDeltaTime();
	}

	if (shadowTimer > shadowDelay && Input::getKeyDown('Z')) {
		float px = getPx();
		float py = getPy();

		ObjectManager::addGameObject(new PlayerShadow(px - 17, py - 40), 1);
		shadowTimer = 0.0f;
	}
}

void Player::shield() {
	shieldTimer += Time::getDeltaTime();

	if (shieldTimer > shieldHoldingTime) {
		getChildObj("Shield")->setActive(false);
	}

	if (Input::getKeyDown(VK_F2)) {
		getChildObj("Shield")->setActive(true);
		shieldTimer = 0;
	}
}

void Player::bomb() {
	if (!bombNum) {
		return;
	}

	if (bombTimer <= bombDelay) {
		bombTimer += Time::getDeltaTime();
	}

	if (bombTimer > bombDelay && Input::getKeyDown('X')) {
		ObjectManager::addGameObject(new PlayerBomb(getPx() + 16, getPy() - 20), 3);
		bombTimer = 0.0f;
		GameManager::bombIconRefresh(--bombNum);
	}
}

void Player::onDeath() {
	if (!GameManager::getBossDead()) {
		ObjectManager::addGameObject(new ShipExp(getPx() - 69.0f, getPy() - 60.0f), 3);
		GameManager::playerRespawn();
	}
	ObjectManager::destroy(this);
}

void Player::onTrigger(GameObject * other) {
	if (state == State::spawn) {
		return;
	}

	string tag = other->getTag();

	// Enemy
	if (tag == "¾Æ¾ßÄÚ" || tag == "½ºÅÚ½º" || tag == "º¸½º") {
		onDeath();
	}
	// Bullet
	else if (tag == "¾Æ¾ßÄÚºí¸´" || tag == "½ºÅÚ½ººí¸´") {
		health -= 5.0f;
		GameManager::healthBarRefresh(health / 100.0f);

		if (health <= 0) {
			onDeath();
		}
	}
	else if (tag == "¾ÆÀÌÅÛ") {
		string name = other->getName();

		if (name == "ÃÑ¾Ë") {
			if (power < 2) {
				power++;
			}
			else {
				GameManager::addScore(10);
			}
		}
		else if (name == "ÆøÅº") {
			if (bombNum < 5) {
				GameManager::bombIconRefresh(++bombNum);
			}
			else {
				GameManager::addScore(10);
			}
		}
	}
}