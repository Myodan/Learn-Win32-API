#pragma once

#include "Animation.h"

class Rotor : public Animation {
private:
	float hp;

public:
	Rotor(float px, float py);
	~Rotor();

	void start();

	void onTrigger(GameObject * other);

	void die();
};

