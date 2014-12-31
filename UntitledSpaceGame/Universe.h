#pragma once
#include <random>

#include "Vector2D.h"
#include "Starfield.h"

class Universe
{
public:
	Universe(Camera* camera, int seed);

	void draw();
	void update(Uint32 dTime);

private:
	int mSeed;

	Starfield mStarfield;
	Camera* pCamera;

	std::mt19937 * pRand;

};