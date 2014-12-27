#include "PauseState.h"
#include "TextureManager.h"
#include "Game.h"
#include "MenuButton.h"

const std::string PauseState::s_pauseID = "PAUSE";

void PauseState::update(Uint32 dTime)
{
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

void PauseState::render()
{
	if (!mGameObjects.empty())
	{
		for (int i = 0; i < mGameObjects.size(); i++)
		{
			if (mGameObjects[i] != 0)
			{
				mGameObjects[i]->draw(UICamera);
			}
		}
	}
}

bool PauseState::onEnter()
{
	std::cout << "Entering PauseState" << std::endl;
	int windowWidth = TheGame::Instance()->getWidth();
	int windowHeight = TheGame::Instance()->getHeight();
	//Set up Camera
	UICamera = new Camera;
	//~~~~~~~~~~~~~~~~~~~~~~Load resources~~~~~~~~~~~~~~~~~~~~~~~~~~~
	//Title
	//if (!TheTextureManager::Instance()->load("Assets/UI/MenuTitle.png", "MenuTitle", TheGame::Instance()->getRenderer())) return false;
	//Resume Button
	if (!TheTextureManager::Instance()->load("Assets/UI/ResumeButton.png", "ResumeButton", TheGame::Instance()->getRenderer())) return false;
	//Menu Button
	if (!TheTextureManager::Instance()->load("Assets/UI/MenuButton.png", "MenuButton", TheGame::Instance()->getRenderer())) return false;

	//~~~~~~~~~~~~~~~~~~~~~~Initiate Objects~~~~~~~~~~~~~~~~~~~~~~~~~
	//mGameObjects.push_back(new SDLGameObject(new LoaderParams(windowWidth / 2 - (932 / 2), 100, 932, 130, "MenuTitle")));
	mGameObjects.push_back(new MenuButton(new LoaderParams(windowWidth / 2 - 175, windowHeight / 2 - 50, 350, 100, "ResumeButton"), resumePlay));
	mGameObjects.push_back(new MenuButton(new LoaderParams(windowWidth / 2 - 175, windowHeight / 2 - 50 + 150, 350, 100, "MenuButton"), pauseToMain));
	return true;
}

bool PauseState::onExit()
{
	std::cout << "Exiting PauseState" << std::endl;
	for (GameObject * object : mGameObjects)
	{
		object->clean();
	}
	mGameObjects.clear();
	TheTextureManager::Instance()->clearFromTextureMap("ResumeButton");
	TheTextureManager::Instance()->clearFromTextureMap("MenuButton");
	TheInputHandler::Instance()->reset();
	delete UICamera;
	return true;
}

void PauseState::resumePlay()
{
	std::cout << "Resume Button Clicked" << std::endl;
	TheGame::Instance()->getStateMachine()->popState();
}

void PauseState::pauseToMain()
{
	std::cout << "Exit Button Pressed" << std::endl;
	TheGame::Instance()->getStateMachine()->changeState(new MenuState());
}