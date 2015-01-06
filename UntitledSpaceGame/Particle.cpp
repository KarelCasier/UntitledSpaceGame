#include "Particle.h"

Particle::Particle(Camera* camera, LoaderParams* pParams, Uint32 life)
:SDLGameObject(camera, pParams)
, mLifetime(life)
, mLifetimeLeft(life)
{

}

void Particle::draw()
{
	//std::cout << "Draw";
	SDLGameObject::draw();
}

void Particle::update(Uint32 dTime)
{
	mLifetimeLeft -= dTime;
	setAlpha((float)mLifetimeLeft / (float)mLifetime);
	SDLGameObject::update(dTime);
}

void Particle::clean()
{
	SDLGameObject::clean();;
}

bool Particle::isDead()
{
	if (mLifetimeLeft <= 0)
	{
		return true;
	}
	return false;
}