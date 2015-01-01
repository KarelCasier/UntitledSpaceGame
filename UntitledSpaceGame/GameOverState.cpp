#include "GameOverState.h"
#include "TextureManager.h"
#include "Game.h"
#include "MenuButton.h"
#include "InputHandler.h"

const std::string GameOverState::s_gameOverID = "GAMEOVER";

void GameOverState::update(Uint32 dTime)
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

	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_ESCAPE))
	{
		//TheGame::Instance()->getStateMachine()->popState();
	}
}

void GameOverState::render()
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

bool GameOverState::onEnter()
{
	std::cout << "Entering GameOverState" << std::endl;
	int windowWidth = TheGame::Instance()->getWidth();
	int windowHeight = TheGame::Instance()->getHeight();
	//Set up Camera
	UICamera = new Camera;
	//~~~~~~~~~~~~~~~~~~~~~~Load resources~~~~~~~~~~~~~~~~~~~~~~~~~~~
	//Title
	//if (!TheTextureManager::Instance()->load("Assets/UI/MenuTitle.png", "MenuTitle", TheGame::Instance()->getRenderer())) return false;
	//Resume Button
	if (!TheTextureManager::Instance()->load("Assets/UI/MenuButton.png", "MenuButton", TheGame::Instance()->getRenderer())) return false;
	//Menu Button
	if (!TheTextureManager::Instance()->load("Assets/UI/ExitButton.png", "ExitButton", TheGame::Instance()->getRenderer())) return false;

	//~~~~~~~~~~~~~~~~~~~~~~Initiate Objects~~~~~~~~~~~~~~~~~~~~~~~~~
	//mGameObjects.push_back(new SDLGameObject(new LoaderParams(windowWidth / 2 - (932 / 2), 100, 932, 130, "MenuTitle")));
	mGameObjects.push_back(new MenuButton(UICamera, new LoaderParams(windowWidth / 2 - 175, windowHeight / 2 - 50, 350, 100, "MenuButton"), gameOverToMain));
	mGameObjects.push_back(new MenuButton(UICamera, new LoaderParams(windowWidth / 2 - 175, windowHeight / 2 - 50 + 150, 350, 100, "ExitButton"), exitGame));
	return true;
}

bool GameOverState::onExit()
{
	std::cout << "Exiting GameOverState" << std::endl;
	for (GameObject * object : mGameObjects)
	{
		object->clean();
	}
	mGameObjects.clear();
	TheTextureManager::Instance()->clearFromTextureMap("ExitButton");
	TheTextureManager::Instance()->clearFromTextureMap("MenuButton");
	TheInputHandler::Instance()->reset();
	delete UICamera;
	return true;
}

void GameOverState::exitGame()
{
	std::cout << "Exit Button Clicked" << std::endl;
	TheGame::Instance()->quit();
}

void GameOverState::gameOverToMain()
{
	std::cout << "Menu Button Pressed" << std::endl;
	TheGame::Instance()->getStateMachine()->changeState(new MenuState());
}