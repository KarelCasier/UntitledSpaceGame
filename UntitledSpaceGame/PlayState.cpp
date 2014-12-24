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

	TheTextureManager::Instance()->load("Assets/Ship.png", "Player", TheGame::Instance()->getRenderer());
	mGameObjects.push_back(new Player(new LoaderParams(100, 100, 166, 138, "Player")));

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
	return true;
}