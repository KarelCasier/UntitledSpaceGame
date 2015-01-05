#include "Universe.h"
#include "Game.h"
#include <iostream>


Universe::Universe(Camera* camera,int seed)
:pCamera(camera)
,mStarfield(camera, seed)
{
	pRand = new std::mt19937(0);
	TheTextureManager::Instance()->load("Assets/StarWAura.png", "Star", TheGame::Instance()->getRenderer());
}

void Universe::draw()
{
	mStarfield.draw();
}

void Universe::update(Uint32 dTime)
{
	//Generate new stars

	mStarfield.update(dTime);
}

void Universe::clean()
{
	mStarfield.clean();
	TheTextureManager::Instance()->clearFromTextureMap("Star");
}