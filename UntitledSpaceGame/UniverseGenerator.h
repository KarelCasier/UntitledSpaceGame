#pragma once
#include <random>

#include "Vector2D.h"

struct Star
{
	Vector2D position;
	float size;
};

class UniverseGenerator
{
public:
	UniverseGenerator(int seed);

private:
	int mSeed;
};