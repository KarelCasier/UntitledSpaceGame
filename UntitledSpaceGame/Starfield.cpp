#include "Starfield.h"
#include "Game.h"
#include <math.h>

Starfield::Starfield(Camera* camera)
:pCamera(camera)
{
}

void Starfield::draw()
{
	for (int i = 0; i < mStars.size(); i++){ //Repeat for every star
		Star* s = mStars[i];
		s->draw();
	}
}

void Starfield::update(Uint32 dTime)
{
	for (int i = 0; i < mStars.size(); i++)
	{
		mStars[i]->update(dTime);
	}
}