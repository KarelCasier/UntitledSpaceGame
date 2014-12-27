#pragma once
#include "GameObject.h"
#include "LoaderParams.h"
#include "Vector2D.h"

class SDLGameObject : public GameObject
{
public:
	SDLGameObject(const LoaderParams* pParams);
	

	virtual void draw(Camera* cam);
	virtual void update(Uint32 dTime);
	virtual void clean();

	Vector2D getPosition() { return mPosition; }

protected:

	int mWidth;
	int mHeight;
	int mCurrentRow;
	int mCurrentFrame;
	std::string mTextureID;
	
	Vector2D mPosition;
	Vector2D mVelocity;
	Vector2D mAcceleration;
};

