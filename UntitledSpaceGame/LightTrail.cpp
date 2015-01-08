#include "LightTrail.h"
#include "Game.h"


LightTrail::LightTrail(SDLGameObject* target, Camera* cam)
	:pTarget(target)
	, pCamera(cam)
{
	mPrevPositions.push_back(getNewPos());
	
}


LightTrail::~LightTrail()
{
}


void LightTrail::draw()
{
	if (mPrevPositions.size() < 4)
		return;

	SDL_SetRenderDrawColor(TheGame::Instance()->getRenderer(), 0xFF, 0xFF, 0x00, 0xFF);
	for (int i = 0; i <= mPrevPositions.size() - 2; i++)
	{
		SDL_RenderDrawLine(TheGame::Instance()->getRenderer(),
			mPrevPositions.at(i)->getX() - pCamera->getPosition().getX(), 
			mPrevPositions.at(i)->getY() - pCamera->getPosition().getY(),
			mPrevPositions.at(i + 1)->getX() - pCamera->getPosition().getX(), 
			mPrevPositions.at(i + 1)->getY() - pCamera->getPosition().getY());
	}
}

Vector2D* LightTrail::getNewPos()
{
	if (dynamic_cast<Ship*>(pTarget))
	{
		return static_cast<Ship*>(pTarget)->getEnginePosition();
	}
	else
	{
		pTarget->getCenteredPosition();//new Vector2D(pTarget->getPosition());
	}
}

void LightTrail::update()
{
	if (mPrevPositions.size() < 100)
	{
		//Fill initial positions

				mPrevPositions.push_back(getNewPos());
		
	}
	else
	{
		//delete front and add new position to back
			delete mPrevPositions.at(0);
			mPrevPositions.erase(mPrevPositions.begin());
			mPrevPositions.push_back(getNewPos());
	}
}
void LightTrail::clean()
{

}