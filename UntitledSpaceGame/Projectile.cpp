#include "Projectile.h"

Projectile::Projectile(Camera* camera, LoaderParams* pParams)
: SDLGameObject(camera, pParams)
{

}

void Projectile::update(Uint32 dTime)
{
	SDLGameObject::update(dTime);
}

void Projectile::draw()
{
	SDLGameObject::draw();
}

void Projectile::clean()
{

}