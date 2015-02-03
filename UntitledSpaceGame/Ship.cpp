#include "Ship.h"
#include "TextureManager.h"
#include "Game.h"
#include <cmath>
#include "ParticleSystem.h"
#include "ProjectileManager.h"

Ship::Ship(Camera* camera, const LoaderParams* pParams, ShipType type) :
SDLGameObject(camera, pParams),
mLightTrail(this, camera),
mType(type),
pCamera(camera)
{
	enableFriction(true);
	bEnginesFireing      = false;
	
	bReloaded            = true;

	bIsAlive = true;


	ParticleSystem::ParticleType particleType;
	if (mType == ShipType::Player)
	{
		particleType = ParticleSystem::ParticleType::Player;
		mEngineThrust = 20;
		mMass = 100;
		mMaxSpeed = 20;
		reloadTime = 1 * 60;
		health = 5000;
	}
	else if (mType == ShipType::Enemy)
	{
		particleType = ParticleSystem::ParticleType::Enemy;
		mEngineThrust = 15;
		mMass = 100;
		mMaxSpeed = 20;
		reloadTime = 1 * 120;
		health = 10;
	}
	else
	{
		std::cout << "Error in Ship: ShipType undefined" << std::endl;
	}

	pParticleSystemLeft = new ParticleSystem(camera, this, Engine::LEFT, particleType);
	pParticleSystemRight = new ParticleSystem(camera, this, Engine::RIGHT, particleType);
	

	mColBox.pos = Vector2D(0, 0);
	mColBox.height = getHeight();
	mColBox.width = getWidth();
}

void Ship::draw()
{
	//mLightTrail.draw();
	pParticleSystemLeft->draw();
	pParticleSystemRight->draw();

	SDLGameObject::draw();

	/*
	SDL_SetRenderDrawColor(TheGame::Instance()->getRenderer(), 142, 226, 255, 0xFF);


		SDL_RenderDrawLine(TheGame::Instance()->getRenderer(),
			mPrevPositions.at(i)->getX() - pCamera->getPosition().getX(),
			mPrevPositions.at(i)->getY() - pCamera->getPosition().getY(),
			mPrevPositions.at(i + 1)->getX() - pCamera->getPosition().getX(),
			mPrevPositions.at(i + 1)->getY() - pCamera->getPosition().getY());
		*/
}

void Ship::update(Uint32 dTime)
{
	mLightTrail.update();
	pParticleSystemLeft->update(dTime);
	pParticleSystemRight->update(dTime);

	if (bEnginesFireing)
	{
		float fAccel = mEngineThrust / mMass;
		Vector2D accel(fAccel* std::cos((mRotation - 90)*(M_PI / 180)), fAccel* std::sin((mRotation - 90)*(M_PI / 180)));
		mAcceleration = accel;
		pParticleSystemLeft->setSpawnState(true);
		pParticleSystemRight->setSpawnState(true);
	}
	else
	{
		pParticleSystemLeft->setSpawnState(false);
		pParticleSystemRight->setSpawnState(false);
	}

	if (reloadTimer.getTicks() >= reloadTime)
	{
		reload();
	}

	SDLGameObject::update(dTime);

	if (health <= 0)
	{
		bIsAlive = false;
	}
}

void Ship::fireEngine(bool bState)
{
	bEnginesFireing = bState;
}

void Ship::fireGun()
{
	if (bReloaded)
	{
		//std::cout << "Fire" << std::endl;
		Vector2D gunPos = getPosition() + Vector2D(getWidth() / 2 - 2.5, getHeight() / 2 - 2.5);
		Vector2D positionOffset(-(getHeight() / 3 + 15) * std::cos((mRotation + 90)*(M_PI / 180)), -(getHeight() / 3 + 15) * std::sin((mRotation + 90)*(M_PI / 180)));
		gunPos += positionOffset;

		Projectile* projectile = nullptr;
		
		if (mType == ShipType::Player)
		{
			projectile = new Projectile(mCamera, new LoaderParams(gunPos.getX(), gunPos.getY(), 5, 5, "PlayerBullet", 1, LoaderParams::TAG::ALLIED));
		}
		else if (mType == ShipType::Enemy)
		{
			projectile = new Projectile(mCamera, new LoaderParams(gunPos.getX(), gunPos.getY(), 5, 5, "EnemyBullet", 1, LoaderParams::TAG::ENEMY));
		}
		else
		{
			std::cout << "Error in Ship.cpp: ShipType undefined" << std::endl;
		}
		projectile->setRotation(mRotation);

		Vector2D bulletVel(50 * std::cos((mRotation - 90)*(M_PI / 180)), 50 * std::sin((mRotation - 90)*(M_PI / 180)));
		projectile->setVelocity(bulletVel);

		TheProjectileManager::Instance()->addProjectile(projectile);

		bReloaded = false;
		reloadTimer.start();
	}
}

void Ship::reload()
{
	bReloaded = true;
	reloadTimer.stop();
}

Vector2D* Ship::getEnginePosition(Engine pos)
{
	int rotation = (getRotation()) * M_PI / 180;
	Vector2D toCenter(getWidth() / 2, getHeight() / 2);

	Vector2D* positionOffset;
	if (pos == Engine::CENTER)
	{
		positionOffset = new Vector2D(
			getHeight() / 3 * std::cos((mRotation + 90)*(M_PI / 180)),
			getHeight() / 3 * std::sin((mRotation + 90)*(M_PI / 180)));
	}
	else if (pos == Engine::LEFT)
	{
		positionOffset = new Vector2D(
			getHeight() / 2.5 * std::cos((mRotation + 90)*(M_PI / 180)) - getWidth() / 5.3 * std::sin((mRotation + 90)*(M_PI / 180)),
			getHeight() / 2.5 * std::sin((mRotation + 90)*(M_PI / 180)) + getWidth() / 5.3 * std::cos((mRotation + 90)*(M_PI / 180)));
	}
	else if (pos == Engine::RIGHT)
	{
		positionOffset = new Vector2D(
			getHeight() / 2.5 * std::cos((mRotation + 90)*(M_PI / 180)) + getWidth() / 5.3 * std::sin((mRotation + 90)*(M_PI / 180)),
			getHeight() / 2.5 * std::sin((mRotation + 90)*(M_PI / 180)) - getWidth() / 5.3 * std::cos((mRotation + 90)*(M_PI / 180)));
	}
	else
	{
		std::cout << "Error, non existent engine position" << std::endl;
		exit(1);
	}

	//Vector2D* temp = new Vector2D(positionOffset->getX(), positionOffset->getY());
	//positionOffset->setX(temp->getX() * std::cosf(rotation) - temp->getY() * std::sinf(rotation));
	//positionOffset->setY(temp->getX() * std::sinf(rotation) + temp->getY() * std::cosf(rotation));

	//Vector2D* finalPositionOffset = new Vector2D(positionOffset->getX() * std::cosf(rotation) - positionOffset->getY() * std::sinf(rotation), positionOffset->getY() * std::cosf(rotation) + positionOffset->getX() * std::sinf(rotation));
	*positionOffset += getPosition();
	*positionOffset += toCenter;
	//*positionOffset += *finalPositionOffset;
	//delete finalPositionOffset;

	return positionOffset;
}

void Ship::clean()
{
	mLightTrail.clean();
	pParticleSystemLeft->clean();
	pParticleSystemRight->clean();
	delete pParticleSystemLeft;
	delete pParticleSystemRight;
}