#include "MenuState.h"
#include "TextureManager.h"
#include "Game.h"

#include "MenuButton.h"

const std::string MenuState::s_menuID = "MENU";

void MenuState::update(Uint32 dTime)
{
	for (GameObject * object : mGameObjects)
	{
		object->update(dTime);
	}
}

void MenuState::render()
{
	for (GameObject * object : mGameObjects)
	{
		object->draw();
	}
}

bool MenuState::onEnter()
{
	std::cout << "Entering MenuState" << std::endl;
	int windowWidth = TheGame::Instance()->getWidth();
	int windowHeight = TheGame::Instance()->getHeight();

	//~~~~~~~~~~~~~~~~~~~~~~Load resources~~~~~~~~~~~~~~~~~~~~~~~~~~~
	//Title
	if (!TheTextureManager::Instance()->load("Assets/UI/MenuTitle.png", "MenuTitle", TheGame::Instance()->getRenderer())) return false;
	//Play Button
	if (!TheTextureManager::Instance()->load("Assets/UI/PlayButton.png", "PlayButton", TheGame::Instance()->getRenderer())) return false;
	//Exit Button
	if (!TheTextureManager::Instance()->load("Assets/UI/ExitButton.png", "ExitButton", TheGame::Instance()->getRenderer())) return false;
	//~~~~~~~~~~~~~~~~~~~~~~Initiate Objects~~~~~~~~~~~~~~~~~~~~~~~~~
	mGameObjects.push_back(new SDLGameObject(new LoaderParams(windowWidth / 2 - (932 / 2), 100, 932, 130, "MenuTitle")));
	mGameObjects.push_back(new MenuButton(new LoaderParams(windowWidth / 2 - 175, windowHeight / 2 - 50, 350, 100, "PlayButton")));
	mGameObjects.push_back(new MenuButton(new LoaderParams(windowWidth / 2 - 175, windowHeight / 2 - 50 + 150, 350, 100, "ExitButton")));
	return true;
}

bool MenuState::onExit()
{
	std::cout << "Exiting MenuState" << std::endl;
	for (GameObject * object : mGameObjects)
	{
		object->clean();
	}
	mGameObjects.clear();
	TheTextureManager::Instance()->clearFromTextureMap("MenuTitle");
	TheTextureManager::Instance()->clearFromTextureMap("PlayButton");
	TheTextureManager::Instance()->clearFromTextureMap("ExitButton");

	return true;
}