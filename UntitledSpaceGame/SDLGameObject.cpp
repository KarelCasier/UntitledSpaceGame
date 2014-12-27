#include "SDLGameObject.h"
#include "TextureManager.h"
#include "Game.h"


SDLGameObject::SDLGameObject(const LoaderParams* pParams) :
GameObject(pParams),
mPosition(pParams->getX(), pParams->getY()),
mVelocity(0.f, 0.f),
mAcceleration(0.f, 0.f)
{
	mWidth = pParams->getWidth();
	mHeight = pParams->getHeight();
	mTextureID = pParams->getTextureID();
	mCurrentRow = 1;
	mCurrentFrame = 1;
}

void SDLGameObject::draw(Camera* cam)
{
	TheTextureManager::Instance()->drawFrame(mTextureID, (int)mPosition.getX(), (int)mPosition.getY(), mWidth, mHeight, mCurrentRow, mCurrentFrame, TheGame::Instance()->getRenderer(), 0, 255, cam, SDL_FLIP_NONE);
}

void SDLGameObject::update(Uint32 dTime)
{
	mVelocity += mAcceleration;
	mPosition += mVelocity*(dTime/60.f);
}

void SDLGameObject::clean()
{

}