#pragma once

#include <string>

class LoaderParams
{
public:

	LoaderParams(int x, int y, int width, int height, std::string textureID) : mX(x), mY(y), mWidth(width), mHeight(height), mTextureID(textureID)
	{
	}
	int getX() const { return mX; }
	int getY() const { return mY; }
	int getWidth() const { return mWidth; }
	int getHeight() const { return mHeight; }
	std::string getTextureID() const { return mTextureID; }

private:

	int mX;
	int mY;
	int mWidth;
	int mHeight;
	std::string mTextureID;
};