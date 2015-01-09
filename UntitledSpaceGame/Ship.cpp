#include "Ship.h"
#include "TextureManager.h"
#include "Game.h"
#include <cmath>


Ship::Ship(Camera* camera, const LoaderParams* pParams) :
SDLGameObject(camera, pParams),
mLightTrail(this, camera)
{

	enableFriction(true);
	bEnginesFireing = false;
	mEngineThrust = 20;
	mMass = 100;
	mMaxSpeed = 20;
	reloadTime = 1 * 60; //1 second
	bReloaded = true;
	TheTextureManager::Instance()->load("Assets/Bullet.png", "Bullet", TheGame::Instance()->getRenderer());
	pParticleSystem = new ParticleSystem(camera, this);
}

void Ship::draw()
{
	//mLightTrail.draw();
	pParticleSystem->draw();

	for (int i = 0; i < mProjectiles.size();i++)
	{
		
		mProjectiles[i]->draw();
	}

	SDLGameObject::draw();
}

void Ship::update(Uint32 dTime)
{
	mLightTrail.update();
	pParticleSystem->update(dTime);

	if (bEnginesFireing)
	{
		float fAccel = mEngineThrust / mMass;
		Vector2D accel(fAccel* std::cos((mRotation - 90)*(M_PI / 180)), fAccel* std::sin((mRotation - 90)*(M_PI / 180)));
		mAcceleration = accel;
	}

	for (Projectile * projectile : mProjectiles)
	{
		projectile->update(dTime);
	}
	
	if (reloadTimer.getTicks() >= reloadTime)
	{
		reload();
	}

	SDLGameObject::update(dTime);
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
		Vector2D gunPos = getPosition() + Vector2D(getWidth() / 2, getHeight() / 2);
		Projectile* proj = new Projectile(mCamera, new LoaderParams(gunPos.getX(), gunPos.getY(), 10, 10, "Bullet", 1, LoaderParams::TAG::ALLIEDBULLET));
		proj->setVelocity(Vector2D(0, 0));
		mProjectiles.push_back(proj);

		bReloaded = false;
		reloadTimer.start();
	}
}

void Ship::reload()
{
	bReloaded = true;
	reloadTimer.stop();
}

Vector2D* Ship::getEnginePosition()
{
	int rotation = (getRotation()) * M_PI / 180;
	Vector2D toCenter(getWidth() / 2, getHeight() / 2);
	Vector2D* positionOffset = new Vector2D(getHeight() / 3 * std::cos((mRotation + 90)*(M_PI / 180)), getHeight() / 3 * std::sin((mRotation + 90)*(M_PI / 180)));
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
	pParticleSystem->clean();
	for (int i = 0; i < mProjectiles.size(); i++)
	{
		mProjectiles[i]->clean();
		delete mProjectiles[i];
	}
	mProjectiles.clear();
}