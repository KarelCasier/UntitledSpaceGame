#pragma once
#include <random>

#include "Vector2D.h"
#include "SimplexNoise.h"
#include "StarfieldSequence.h"

class Universe
{
public:
	Universe(Camera* camera, int seed);

	void draw();
	void update(Uint32 dTime);

private:
	int mSeed;

	StarfieldSequence mStarfield;
	Camera* pCamera;

};