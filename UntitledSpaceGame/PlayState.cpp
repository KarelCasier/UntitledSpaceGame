#include "PlayState.h"
#include "InputHandler.h"
#include "Game.h"


const std::string PlayState::s_playID = "PLAY";

bool PlayState::update(Uint32 dTime)
{
	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_ESCAPE))
	{
		TheGame::Instance()->getStateMachine()->pushState(new PauseState());
	}

	for (int i = 0; i < NumberOfLayers; i++)
	{
		mLayers[i]->update(dTime);
	}
	
	//Position Camera after updating location to avoid jitter of plane
	Vector2D pos( 
		mpPlayer->getPosition().m_x - (TheGame::Instance()->getWidth() / 2) + (mpPlayer->getWidth() / 2),
		mpPlayer->getPosition().m_y - (TheGame::Instance()->getHeight() / 2) + (mpPlayer->getHeight() / 2)
		);

	mUniverseLayerBot->update(dTime);
	mUniverseLayerTop->update(dTime);
	
	WorldCamera->setPosition(pos); //Center Camera on player
	ParalaxCamera->setPosition(WorldCamera->getPosition() / 2);

	return false;
}

void PlayState::render()
{
	mUniverseLayerBot->draw();
	mUniverseLayerTop->draw();

	for (int i = 0; i < NumberOfLayers; i++)
	{
		mLayers[i]->draw();
	}
}

bool PlayState::onEnter()
{
	std::cout << "Entering PlayState" << std::endl;
	//Set up Cameras
	WorldCamera = new Camera;
	ParalaxCamera = new Camera;
	UICamera = new Camera;

	//Set up Layers
	for (int i = 0; i < NumberOfLayers; i++)
	{
		mLayers.push_back(new Layer());
	}

	mUniverseLayerTop = new Universe(WorldCamera,1234);
	mUniverseLayerBot = new Universe(ParalaxCamera, 1234);

	TheTextureManager::Instance()->load("Assets/Ship.png", "Player", TheGame::Instance()->getRenderer());

	//mLayers[LAYERS::Game]->push_back(new Enemy(WorldCamera, new LoaderParams(100, 100, 100, 100, "Player",1)));

	mpPlayer = new Player(WorldCamera, new LoaderParams(100, 100, 100, 100, "Player", 1));
	mLayers[LAYERS::Game]->push_back(mpPlayer);

	//Setup camera
	Vector2D pos(
		mpPlayer->getPosition().m_x - (TheGame::Instance()->getWidth() / 2) + (mpPlayer->getWidth() / 2),
		mpPlayer->getPosition().m_y - (TheGame::Instance()->getHeight() / 2) + (mpPlayer->getHeight() / 2)
		);
	WorldCamera->setPosition(pos); //Center Camera on player
	return true;
}

bool PlayState::onExit()
{
	std::cout << "Exiting PlayState" << std::endl;
	for (int i = 0; i < NumberOfLayers; i++)
	{
		mLayers[i]->clean();
	}
	mUniverseLayerTop->clean();
	mUniverseLayerBot->clean();
	TheTextureManager::Instance()->clearFromTextureMap("Player");
	TheInputHandler::Instance()->reset();
	delete UICamera;
	delete WorldCamera;
	delete mUniverseLayerTop;
	delete mUniverseLayerBot;
	return true;
}

bool PlayState::checkCollision(SDLGameObject* o1, SDLGameObject* o2)
{
	int leftA, leftB;
	int rightA, rightB;
	int topA, topB;
	int bottomA, bottomB;

	//Calculate the sides of rect A
	leftA = o1->getPosition().getX();
	rightA = o1->getPosition().getX() + o1->getWidth();
	topA = o1->getPosition().getY();
	bottomA = o1->getPosition().getY() + o1->getHeight();

	//Calculate the sides of rect B
	leftB = o2->getPosition().getX();
	rightB = o2->getPosition().getX() + o2->getWidth();
	topB = o2->getPosition().getY();
	bottomB = o2->getPosition().getY() + o2->getHeight();

	//If any of the sides from A are outside of B
	if (bottomA <= topB){ return false; }
	if (topA >= bottomB){ return false; }
	if (rightA <= leftB){ return false; }
	if (leftA >= rightB){ return false; }

	//Else collision
	return true;
}