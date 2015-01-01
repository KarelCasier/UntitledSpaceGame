#pragma once
#include "GameObject.h"
#include "LoaderParams.h"
#include "Vector2D.h"
#include "Camera.h"

class SDLGameObject : public GameObject
{
public:
	SDLGameObject(Camera* camera, const LoaderParams* pParams);
	

	virtual void draw();
	virtual void update(Uint32 dTime);
	virtual void clean();

	Vector2D& getPosition() { return mPosition; }
	Camera* getCamera() { return mCamera; }
	void setCamera(Camera* camera) { mCamera = camera; }

	int getWidth() { return mWidth; }
	int getHeight() { return mHeight; }

	float getAlpha() { return (float)mAlpha/255.f; }
	void setAlpha(float between0and1) { mAlpha = (int)(between0and1 * 255); }

	float getScale() { return mScale; }
	void setScale(float scale) { mScale = scale; }

	void rotate(float radAngle);

protected:

	int mWidth;
	int mHeight;
	int mCurrentRow;
	int mCurrentFrame;
	int mAlpha;
	float mScale;
	int mRotation;
	int mRotationSpeed;

	Camera* mCamera;
	std::string mTextureID;
	
	Vector2D mPosition;
	Vector2D mVelocity;
	Vector2D mAcceleration;
};

