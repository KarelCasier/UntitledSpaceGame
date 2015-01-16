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
	//for (Projectile* projectile : mProjectiles)
	for (int i = 0; i < mProjectiles.size(); i++)
	{
		mProjectiles.at(i)->update(dTime);
	}
	destroyProjectilesInQueue();
}

void ProjectileManager::addProjectile(Projectile* projectile)
{
	mProjectiles.push_back(projectile);
}

void ProjectileManager::destroyProjectile(Projectile* projectile)
{
	//Find, remove, add projectile to the remove queue
	//auto iter = std::remove(mProjectiles.begin(), mProjectiles.end(), projectile);
	//mProjectilesToDestroy.push(*iter);
	//mProjectiles.erase(iter, mProjectiles.end());

	for (int i = 0; i < mProjectiles.size(); i++)
	{
		if (mProjectiles.at(i) == projectile)
		{
			Projectile * toDelete = mProjectiles.at(i);
			mProjectilesToDestroy.push_back(toDelete);
			mProjectiles.erase(mProjectiles.begin() + i);
		}
	}
	
}

void ProjectileManager::destroyProjectilesInQueue()
{
	while (!mProjectilesToDestroy.empty())
	{

		Projectile* toDelete = mProjectilesToDestroy.back();
		mProjectilesToDestroy.pop_back();
		if (toDelete != nullptr)
		{
			toDelete->clean();
			delete toDelete;
			toDelete = nullptr;
		}
	}
}

void ProjectileManager::clean()
{
	destroyProjectilesInQueue();
	for (Projectile* projectile : mProjectiles)
	{
		projectile->clean();
		delete projectile;
	}
	mProjectiles.clear();
}