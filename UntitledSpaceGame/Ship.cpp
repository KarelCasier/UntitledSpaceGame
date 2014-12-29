#include "Ship.h"
#include "TextureManager.h"
#include "Game.h"
#include <cmath>


Ship::Ship(Camera* camera, const LoaderParams* pParams) :
SDLGameObject(camera, pParams)
{

	bEnginesFireing = false;
	mDecay = 0.9;
	mEngineThrust = 20;
	mMass = 100;
	mMaxSpeed = 20;

}

void Ship::draw()
{
	SDLGameObject::draw();
}

void Ship::update(Uint32 dTime)
{
	if (bEnginesFireing)
	{
		float fAccel = mEngineThrust / mMass;
		Vector2D accel(fAccel* std::cos((mRotation - 90)*(M_PI / 180)), fAccel* std::sin((mRotation - 90)*(M_PI / 180)));
		mAcceleration = accel;
	}
	else
	{
		//Vector2D accel(mDecay, mDecay);
		mAcceleration *= mDecay;
		mVelocity *= ((1 - mDecay) / 1.1 + mDecay);
	}
	
	SDLGameObject::update(dTime);
}

void Ship::fireEngine(bool bState)
{
	bEnginesFireing = bState;
}


void Ship::clean()
{
}