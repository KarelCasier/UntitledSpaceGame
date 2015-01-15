#include "Projectile.h"

Projectile::Projectile(Camera* camera, LoaderParams* pParams)
: SDLGameObject(camera, pParams)
, pCamera(camera)
{

}

void Projectile::update(Uint32 dTime)
{
	SDLGameObject::update(dTime);
}

void Projectile::draw()
{
	if (pCamera->isOnSrceen(getPosition()))
	{
		SDLGameObject::draw();
	}
}

void Projectile::clean()
{

}