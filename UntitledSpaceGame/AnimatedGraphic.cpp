#include "AnimatedGraphic.h"

AnimatedGraphic::AnimatedGraphic(Camera* camera, const LoaderParams* pParams, int numFrames, int animSpeed) 
: SDLGameObject(camera, pParams)
, mAnimSpeed(animSpeed)
, mNumFrames(numFrames)
{
}

void AnimatedGraphic::update(Uint32 dTime)
{
	mCurrentFrame = int(((SDL_GetTicks() / (1000 / mAnimSpeed)) % mNumFrames));

	SDLGameObject::update(dTime);
}

void AnimatedGraphic::draw()
{
	SDLGameObject::draw();
}