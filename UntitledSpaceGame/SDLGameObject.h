#pragma once
#include "GameObject.h"
#include "LoaderParams.h"
#include "Vector2D.h"
#include "Camera.h"

class SDLGameObject : public GameObject
{
public:
	SDLGameObject(Camera* camera, const LoaderParams* pParams);

	struct CollisionBox
	{
		Vector2D pos;
		int width;
		int height;
	};
	

	virtual void draw();
	virtual void update(Uint32 dTime);
	virtual void clean();

	Vector2D& getPosition() { return mPosition; }
	Vector2D* getCenteredPosition() { return new Vector2D(mPosition.getX() + mScaledWidth / 2, mPosition.getY() + mScaledWidth / 2); }

	Camera* getCamera() { return mCamera; }
	void setCamera(Camera* camera) { mCamera = camera; }

	void setVelocity(Vector2D& vel) { mVelocity = vel; }

	int getWidth() { return mScaledWidth; }
	int getHeight() { return mScaledHeight; }

	float getAlpha() { return (float)mAlpha/255.f; }
	void setAlpha(float between0and1) { mAlpha = (int)(between0and1 * 255); }

	float getScale() { return mScale; }
	void setScale(float scale) {
		mScale = scale;
		mScaledWidth = mWidth * mScale;
		mScaledHeight = mHeight * mScale;
	}

	bool hasFriction() { return bHasFriction; }
	void enableFriction(bool state) { bHasFriction = state; }

	int getRotation() { return mRotation; }
	void setRotation(int newRotation) { mRotation = newRotation; }

	void rotate(float radAngle);

	CollisionBox& getCollisionBox() { return mColBox; }
	void setCollisionBox(CollisionBox newBox) { mColBox = newBox; }

	LoaderParams::TAG getTag() { return mTag; }

protected:

	int mWidth;
	int mHeight;
	int mScaledWidth;
	int mScaledHeight;
	int mCurrentRow;
	int mCurrentFrame;
	int mAlpha;
	float mScale;
	int mRotation;
	int mRotationSpeed;

	LoaderParams::TAG mTag;

	Camera* mCamera;
	std::string mTextureID;

	Vector2D mPosition;
	Vector2D mVelocity;
	float mDecay;
	bool bHasFriction;
	Vector2D mAcceleration;

	CollisionBox mColBox;
};

