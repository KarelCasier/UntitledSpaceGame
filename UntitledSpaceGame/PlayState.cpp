#include "PlayState.h"
#include "InputHandler.h"
#include "Game.h"


const std::string PlayState::s_playID = "PLAY";

void PlayState::update(Uint32 dTime)
{
	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_ESCAPE))
	{
		TheGame::Instance()->getStateMachine()->pushState(new PauseState());
	}
	//std::cout << "Player: [" << mpPlayer->getPosition().getX() << "," << mpPlayer->getPosition().getY() << "]" << std::endl;
	//std::cout << "Camera: [" << WorldCamera->getPosition().m_x << "," << WorldCamera->getPosition().m_y << "]" << std::endl;
	//WorldCamera->setTarget(&testLoc);
	//std::cout << "Location: <" << TheCamera::Instance()->getPosition().m_x << "," << TheCamera::Instance()->getPosition().m_y << ">" << std::endl;

	if (!mGameObjects.empty())
	{
		for (int i = 0; i < mGameObjects.size(); i++)
		{
			if (mGameObjects[i] != 0)
			{
				mGameObjects[i]->update(dTime);
			}
		}
	}
	//Position Camera after updating location to avoid jittering
	Vector2D pos( 
		mpPlayer->getPosition().m_x - (TheGame::Instance()->getWidth() / 2) + (mpPlayer->getWidth() / 2),
		mpPlayer->getPosition().m_y - (TheGame::Instance()->getHeight() / 2) + (mpPlayer->getHeight() / 2)
		);
	WorldCamera->setPosition(pos); //Center Camera on player
}

void PlayState::render()
{
	if (!mGameObjects.empty())
	{
		for (int i = 0; i < mGameObjects.size(); i++)
		{
			if (mGameObjects[i] != 0)
			{
				mGameObjects[i]->draw();
			}
		}
	}
}

bool PlayState::onEnter()
{
	std::cout << "Entering PlayState" << std::endl;
	//Set up Cameras
	WorldCamera = new Camera;
	UICamera = new Camera;

	TheTextureManager::Instance()->load("Assets/Ship.png", "Player", TheGame::Instance()->getRenderer());

	mGameObjects.push_back(new Enemy(WorldCamera, new LoaderParams(100, 100, 100, 100, "Player")));
	mpPlayer = new Player(WorldCamera, new LoaderParams(100, 100, 100, 100, "Player"));
	mGameObjects.push_back(mpPlayer);

	return true;
}

bool PlayState::onExit()
{
	std::cout << "Exiting PlayState" << std::endl;
	for (int i = 0; i < mGameObjects.size(); i++)
	{
		mGameObjects[i]->clean();
	}
	mGameObjects.clear();
	TheTextureManager::Instance()->clearFromTextureMap("Player");
	TheInputHandler::Instance()->reset();
	delete UICamera;
	delete WorldCamera;;
	return true;
}