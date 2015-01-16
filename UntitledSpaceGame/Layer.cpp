#include "Layer.h"
#include "CollisionHandler.h"
#include "ProjectileManager.h"

void Layer::push_back(GameObject* object)
{
	mGameObjects.push_back(object);
}

void Layer::clean()
{
	for (int i = 0; i < mGameObjects.size(); i++)
	{
		mGameObjects[i]->clean();
		delete mGameObjects[i];
	}
	mGameObjects.clear();
}

void Layer::update(Uint32 dTime)
{
	if (!mGameObjects.empty())
	{
		for (int i = 0; i < mGameObjects.size(); i++)
		{
			if (mGameObjects[i] != 0)
			{
				mGameObjects[i]->update(dTime);
			}
		}
	}
}

void Layer::draw()
{
	if (!mGameObjects.empty())
	{
		for (int i = 0; i < mGameObjects.size(); i++)
		{
			if (mGameObjects[i] != 0)
			{
				mGameObjects[i]->draw();
			}
		}
	}
}

void Layer::handleCollisions()
{
	std::vector<Projectile*>& pProjectiles = TheProjectileManager::Instance()->getProjectiles();

	for (int i = 0; i < pProjectiles.size(); i++)
	{ //Loop though all bullets
		for (int j = 0; j < mGameObjects.size(); j++)
		{
			if (checkCollision(pProjectiles.at(i), dynamic_cast<SDLGameObject*>(mGameObjects.at(j))))
			{
				std::cout << "Bullet COllision!" << std::endl;
			}
		}
	}
}