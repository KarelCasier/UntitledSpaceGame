#pragma once
#include "Star.h"
#include <vector>
#include <algorithm>
#include <array>
#include <random>
#include "SimplexNoise.h"

class Starfield
{
public:
	struct Quadrant
	{
		Vector2D position;
		std::vector<Star*> stars;
	};

	Starfield(Camera* Camera, int seed);
	void draw();
	void update(Uint32 dTime);

	void loadQuadrant(int x, int y);
	bool checkQuadrantState(int x, int y);
	void unloadQuadrant(int x, int y);
	Vector2D toQuadrant(int x, int y);

	void clean();


private:
	int screenWidth, screenHeight;
	std::vector<Quadrant*> quadrantsLoaded;
	int quadrantWidth, quadrantHeight;
	Camera* pCamera;
	Vector2D centerOfCamera;
	std::mt19937* pRand;
	std::uniform_real_distribution<double> dis;

};