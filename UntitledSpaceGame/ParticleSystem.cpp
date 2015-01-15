#include "ParticleSystem.h"
#include "TextureManager.h"
#include "Game.h"
#include <math.h>
#include "Ship.h"

ParticleSystem::ParticleSystem(Camera* camera, SDLGameObject* target, Ship::Engine enignePosition)
:pCamera(camera)
, pTarget(target)
, mEnginePositon(enignePosition)
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
	if (mSpawnTimer.getTicks() >= mSpawnTime && isEnabled())
	{
		Vector2D* pos;

		if (dynamic_cast<Ship*>(pTarget))
		{
			pos = static_cast<Ship*>(pTarget)->getEnginePosition(mEnginePositon);
		}
		else
		{
			pos = pTarget->getCenteredPosition();//new Vector2D(pTarget->getPosition());
		}

		//x = ((x - x_origin) * cos(angle)) - ((y_origin - y) * sin(angle)) + x_origin
		//y = ((y_origin - y) * cos(angle)) - ((x - x_origin) * sin(angle)) + y_origin
		//x' = x cos f - y sin f
		//y' = y cos f + x sin f

		//Spawn new particle
		Particle* newParticle = new Particle(pCamera, new LoaderParams(
			pos->getX()-5,
			pos->getY()-5,
			10, 10, "Particle", 1), 10* 60);
		float ejectSpeed = -10.0;
		newParticle->setVelocity(Vector2D(ejectSpeed* std::cos((pTarget->getRotation() - 90)*(M_PI / 180)), ejectSpeed* std::sin((pTarget->getRotation() - 90)*(M_PI / 180))));
		newParticle->enableFriction(true);

		delete pos;

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