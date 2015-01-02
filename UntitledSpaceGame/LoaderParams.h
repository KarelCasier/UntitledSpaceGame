#pragma once

#include <string>

class LoaderParams
{
public:
	enum TAG
	{
		DEFAULT,
		UI,
		ALLIEDBULLET,
		ENEMYBULLET
	};

	LoaderParams(int x, int y, int width, int height, std::string textureID, float scale = 1.0, TAG tag = TAG::DEFAULT) 
		: mX(x), mY(y), mWidth(width), mHeight(height), mTextureID(textureID), mScale(scale), mTag(tag)
	{
	}
	int getX() const { return mX; }
	int getY() const { return mY; }
	int getWidth() const { return mWidth; }
	int getHeight() const { return mHeight; }
	float getScale() const { return mScale; }
	TAG getTag() const { return mTag; }
	std::string getTextureID() const { return mTextureID; }

private:

	int mX;
	int mY;
	int mWidth;
	int mHeight;
	float mScale;
	TAG mTag;
	std::string mTextureID;
};