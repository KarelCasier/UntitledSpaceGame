#include "SDLGameObject.h"
#include "TextureManager.h"
#include "Game.h"
#include <cmath>


SDLGameObject::SDLGameObject(Camera* camera,const LoaderParams* pParams) :
GameObject(pParams),
mPosition(pParams->getX(), pParams->getY()),
mVelocity(0.f, 0.f),
mAcceleration(0.f, 0.f),
mCamera(camera)
{
	mWidth = pParams->getWidth();
	mHeight = pParams->getHeight();
	mTextureID = pParams->getTextureID();
	mCurrentRow = 1;
	mCurrentFrame = 1;

	bEnginesFireing = false;
	mDecay = 0.9;
	mEngineThrust = 20;
	mMass = 100;
	mMaxSpeed = 20;
	mRotation = 0;
	mRotationSpeed = 2;
}

void SDLGameObject::draw()
{
	TheTextureManager::Instance()->drawFrame(mTextureID, (int)mPosition.getX(), (int)mPosition.getY(), mWidth, mHeight, mCurrentRow, mCurrentFrame, TheGame::Instance()->getRenderer(), mRotation, 255, mCamera, SDL_FLIP_NONE);
}

void SDLGameObject::update(Uint32 dTime)
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
	mVelocity += mAcceleration;
	mPosition += mVelocity*(dTime/60.f);
}

void SDLGameObject::fireEngine(bool bState)
{
	bEnginesFireing = bState;
}

void SDLGameObject::rotate(float radAngle)
{
	mRotation += radAngle;
}

void SDLGameObject::clean()
{
}