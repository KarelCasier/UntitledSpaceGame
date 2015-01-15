#include "ProjectileManager.h"
#include <algorithm>
#include "TextureManager.h"
#include "Game.h"

ProjectileManager* ProjectileManager::s_pInstance = 0;

ProjectileManager::ProjectileManager()
{
	TheTextureManager::Instance()->load("Assets/Bullet.png", "Bullet", TheGame::Instance()->getRenderer());
}

void ProjectileManager::draw()
{
	for (Projectile* projectile : mProjectiles)
	{
		projectile->draw();
	}
}

void ProjectileManager::update(Uint32 dTime)
{
	for (Projectile* projectile : mProjectiles)
	{
		projectile->update(dTime);
	}
}

void ProjectileManager::addProjectile(Projectile* projectile)
{
	mProjectiles.push_back(projectile);
}

void ProjectileManager::destroyProjectile(Projectile* projectile)
{
	//Find and remove projectile
	auto iter = std::remove(mProjectiles.begin(), mProjectiles.end(), projectile);
	delete *iter;
	mProjectiles.erase(iter, mProjectiles.end());
}

void ProjectileManager::clean()
{
	for (Projectile* projectile : mProjectiles)
	{
		projectile->clean();
		delete projectile;
	}
	mProjectiles.clear();
}