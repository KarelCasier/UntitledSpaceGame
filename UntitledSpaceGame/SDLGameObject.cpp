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
	mScale = pParams->getScale();
	mTag = pParams->getTag();
	mCurrentRow = 1;
	mCurrentFrame = 1;

	mScaledWidth = mWidth * mScale;
	mScaledHeight = mHeight * mScale;

	mRotation = 0;
	mRotationSpeed = 2;
	mAlpha = 255; //Full opacity
}

void SDLGameObject::draw()
{
	TheTextureManager::Instance()->drawFrame(mTextureID, (int)mPosition.getX(), (int)mPosition.getY(), mWidth, mHeight, mScale, mCurrentRow, mCurrentFrame, TheGame::Instance()->getRenderer(), mRotation, mAlpha, mCamera, SDL_FLIP_NONE);
}

void SDLGameObject::update(Uint32 dTime)
{
	mVelocity += mAcceleration;
	mPosition += mVelocity*(dTime/60.f);
}

void SDLGameObject::rotate(float radAngle)
{
	mRotation += radAngle;
}

void SDLGameObject::clean()
{
}