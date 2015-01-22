#include "Starfield.h"
#include "Game.h"
#include <math.h>

Starfield::Starfield(Camera* camera, int seed)
:pCamera(camera)
, dis(0.0,1.0)
, screenWidth(TheGame::Instance()->getWidth())
, screenHeight(TheGame::Instance()->getHeight())
{
	pRand = new std::mt19937(0);
	//Set up quadrants
	quadrantWidth = 500;
	quadrantHeight = 500;
}

void Starfield::draw()
{
	for (int i = 0; i < quadrantsLoaded.size(); i++)
	{ //Repeat for every quad
		for (int j = 0; j < quadrantsLoaded[i]->stars.size(); j++)
		{ //Every star in every quad
			Vector2D starPos = quadrantsLoaded[i]->stars[j]->getPosition();
			if (pCamera->isOnSrceen(starPos))
			{// On screen
				quadrantsLoaded[i]->stars[j]->draw();
			}
		}
	}
}

void Starfield::update(Uint32 dTime)
{
	centerOfCamera = Vector2D(pCamera->getPosition().getX() + screenWidth / 2, pCamera->getPosition().getY() + screenHeight / 2);
	//Determine quadrant in
	Vector2D pos = toQuadrant(centerOfCamera.getX(), centerOfCamera.getY());

	//Load unloaded quadrants around center of camera
	for (int i = -3; i < 3; i++)
	{
		for (int j = -2; j < 2; j++)
		{
			if (!checkQuadrantState(pos.getX() + i, pos.getY() + j))
			{
				//Load quadrant
				loadQuadrant(pos.getX() + i, pos.getY() + j);
			}
		}
	}
	

	//Unload quadrants not close to you
	for (int i = 0; i < quadrantsLoaded.size(); i++)
	{
		if (std::abs(quadrantsLoaded[i]->position.getX() - pos.getX()) > 3)
		{
			if (std::abs(quadrantsLoaded[i]->position.getX() - pos.getY()) > 3)
			{
				unloadQuadrant(quadrantsLoaded[i]->position.getX(), quadrantsLoaded[i]->position.getY());
			}
		}
	}
}

bool Starfield::checkQuadrantState(int x, int y)
{
	for (int i = 0; i < quadrantsLoaded.size(); i++)
	{
		if (quadrantsLoaded[i]->position.getX() == x && quadrantsLoaded[i]->position.getY() == y)
			return true;
	}
	return false;
}

void Starfield::loadQuadrant(int x, int y)
{
	//Generate stars
	Quadrant* newQuad = new Quadrant();
	newQuad->position = Vector2D(x, y);
	quadrantsLoaded.push_back(newQuad);
	//std::cout << "Quad:[" << x << "," << y << "] Loaded" << std::endl;
	int numStarsAttempt = 30;

	
	for (int i = 0; i < numStarsAttempt; i++)
	{ 
		int starX = (newQuad->position.getX() + (dis(*pRand))) * quadrantWidth;
		int starY = (newQuad->position.getY() + (dis(*pRand))) * quadrantHeight;

		float danger = scaled_octave_noise_2d(4, .2, 10, 0.0, 1.0, starX, starY);
		if (danger < .3)
		{
			newQuad->stars.push_back(new Star(pCamera, new LoaderParams(
				starX, //X-Pos
				starY, //Y-Pos
				20, 20, "Star",
				(dis(*pRand))/3 //Scale
				), 1));

			newQuad->stars.back()->setAlpha(1 / danger);
		}
	}
}
void Starfield::unloadQuadrant(int x, int y)
{
	for (int i = 0; i < quadrantsLoaded.size(); i++)
	{
		if (quadrantsLoaded[i]->position.getX() == x && quadrantsLoaded[i]->position.getY() == y)
		{// Found Quad
			for (int j = 0; j < quadrantsLoaded[i]->stars.size(); j++)
			{ //Every star in every quad
				delete quadrantsLoaded[i]->stars[j];
			}
			quadrantsLoaded[i]->stars.clear();
			delete quadrantsLoaded[i];
			quadrantsLoaded.erase(quadrantsLoaded.begin() + i);
			//std::cout << "Quad:[" << x << "," << y << "] Unloaded" << std::endl;
		}
	}
}

Vector2D Starfield::toQuadrant(int x, int y)
{
	return Vector2D(static_cast<int>(std::floor(x / quadrantWidth)), static_cast<int>(std::floor(y / quadrantHeight)));
}

void Starfield::clean()
{
	while (!quadrantsLoaded.empty())
	{
		unloadQuadrant(quadrantsLoaded[0]->position.getX(), quadrantsLoaded[0]->position.getY());
	}
}