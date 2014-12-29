#include "Universe.h"
#include "Game.h"
#include <iostream>


Universe::Universe(Camera* camera,int seed)
:pCamera(camera)
,mStarfield(camera, seed)
{
	
}

void Universe::draw()
{
	mStarfield.draw();
}

void Universe::update(Uint32 dTime)
{
	mStarfield.update(dTime);
}
