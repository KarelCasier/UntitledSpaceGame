#pragma once
#include "SDLGameObject.h"

class Star : public SDLGameObject
{
public:
	Star(Camera* camera, LoaderParams * pParams, int size)
		: SDLGameObject(camera, pParams)
		, mSize(size)
	{

	}

	float getSize(){
		//Returns the star's radius as a decimal number between 0 and 1
		return (float)(mSize / 1000);
	}

	float getRadiusPx(){
		//Returns the star's radius in pixels
		return (float)4 * getSize(); //4px is the biggest radius a star can have
	}

private:
	int mSize;

};