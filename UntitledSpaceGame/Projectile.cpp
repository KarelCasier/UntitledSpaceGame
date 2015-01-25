#include "Projectile.h"
#include "ProjectileManager.h"

Projectile::Projectile(Camera* camera, LoaderParams* pParams)
: SDLGameObject(camera, pParams)
, pCamera(camera)
{
	isDeleting = false;
}

void Projectile::update(Uint32 dTime)
{
	if (!isDeleting)
	{
		if (pCamera->isOnSrceen(getPosition()))
		{
			SDLGameObject::update(dTime);
		}
		else
		{
			isDeleting = true;
			TheProjectileManager::Instance()->destroyProjectile(this);
		}
	}
	
}

void Projectile::draw()
{
	SDLGameObject::draw();
}

void Projectile::clean()
{
	SDLGameObject::clean();
}