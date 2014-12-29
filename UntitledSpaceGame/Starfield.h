#pragma once
#include "Star.h"
#include <vector>
#include <algorithm>


class Starfield
{
public:
	Starfield(Camera* Camera);
	void draw();
	void update(Uint32 dTime);

	std::vector<Star*> getStarfield(){ return mStars; }

	void AddStar(Star* star) { mStars.push_back(star); }
	Star* GetStar(int i) { return mStars[i]; }
	void removeStar(Star* star) { 
		//Find and remove star
		auto iter = std::remove(mStars.begin(), mStars.end(), star);
		delete *iter;
		mStars.erase(iter, mStars.end());
	}

private:
	std::vector<Star*> mStars;
	Camera* pCamera;

};