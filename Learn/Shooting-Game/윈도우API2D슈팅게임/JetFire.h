#pragma once

#include "Animation.h"

class JetFire : public Animation{
private:
public:
	JetFire(float px, float py);
	virtual ~JetFire();

	void start();
};