#pragma once
#include "SDLGameObject.h"

class AnimatedGraphic : public SDLGameObject
{
public:

	AnimatedGraphic(Camera* camera, const LoaderParams* pParams, int numFrames, int animSpeed);

	virtual void update(Uint32 dTime);
	virtual void draw();

private:
	int mAnimSpeed;
	int mNumFrames;

};