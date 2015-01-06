#pragma once

#include "SDLGameObject.h"

class Particle : public SDLGameObject
{
public:
	Particle(Camera* camera, LoaderParams* pParams, Uint32 life);

	virtual void draw();
	virtual void update(Uint32 dTime);
	virtual void clean();

	bool isDead();

private:
	Uint32 mLifetime;
	int mLifetimeLeft;
};