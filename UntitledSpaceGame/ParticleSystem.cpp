#include "ParticleSystem.h"
#include "TextureManager.h"
#include "Game.h"
#include <math.h>

ParticleSystem::ParticleSystem(Camera* camera, SDLGameObject* target)
:pCamera(camera)
, pTarget(target)
{
	mSpawnTime = 1;
	TheTextureManager::Instance()->load("Assets/Particle.png", "Particle", TheGame::Instance()->getRenderer());
	mSpawnTimer.start();
}

void ParticleSystem::draw()
{
	for (int i = 0; i < mParticles.size(); i++)
	{
		mParticles[i]->draw();
	}
}

void ParticleSystem::update(Uint32 dTime)
{
	if (mSpawnTimer.getTicks() >= mSpawnTime)
	{
		int rotation = pTarget->getRotation() * M_PI / 180;

		Vector2D spawnPos = pTarget->getPosition() + Vector2D(pTarget->getWidth() / 2 - 5, pTarget->getHeight() / 2 - 5);
		Vector2D moveSpawn = Vector2D(0, pTarget->getHeight() / 2.7);

		//Rotate vector
		float xpos = moveSpawn.getX() * std::cos(rotation) - moveSpawn.getY() * std::sin(rotation);
		float ypos = moveSpawn.getY() * std::cos(rotation) + moveSpawn.getX() * std::sin(rotation);

		//x = ((x - x_origin) * cos(angle)) - ((y_origin - y) * sin(angle)) + x_origin
		//y = ((y_origin - y) * cos(angle)) - ((x - x_origin) * sin(angle)) + y_origin
		//x' = x cos f - y sin f
		//y' = y cos f + x sin f

		//Spawn new particle
		Particle* newParticle = new Particle(pCamera, new LoaderParams(
			spawnPos.getX() + xpos,
			spawnPos.getY() + ypos,
			10, 10, "Particle", 1), 10* 60);

		newParticle->setRotation(pTarget->getRotation());

		mParticles.push_back(newParticle);

		mSpawnTimer.start();
	}

	for (int i = 0; i < mParticles.size(); i++)
	{
		mParticles[i]->update(dTime);

		if (mParticles[i]->isDead()) //Remove particle if dead
		{
			mParticles[i]->clean();
			delete mParticles[i];
			mParticles.erase(mParticles.begin() + i);
		}
	}
}

void ParticleSystem::clean()
{
	for (int i = 0; i < mParticles.size(); i++)
	{
		mParticles[i]->clean();
		delete mParticles[i];
	}
	mParticles.clear();
}