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

	//std::vector<Star*> getStarfield(){ return mStars; }

	//void AddStar(Star* star) { mStars.push_back(star); }
	//Star* GetStar(int i) { return mStars[i]; }
	//void removeStar(Star* star) { 
		//Find and remove star
		//auto iter = std::remove(mStars.begin(), mStars.end(), star);
		//delete *iter;
		//mStars.erase(iter, mStars.end());
	//}
	void loadQuadrant(int x, int y);
	bool checkQuadrantState(int x, int y);
	void unloadQuadrant(int x, int y);
	Vector2D toQuadrant(int x, int y);


private:
	std::vector<Quadrant*> quadrantsLoaded;
	int quadrantWidth, quadrantHeight;
	Camera* pCamera;
	Vector2D centerOfCamera;
	std::mt19937* pRand;
	std::uniform_real_distribution<double> dis;

};