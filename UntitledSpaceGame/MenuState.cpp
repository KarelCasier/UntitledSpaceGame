#include "MenuState.h"

const std::string MenuState::s_menuID = "MENU";

void MenuState::update(Uint32 dTime)
{

}

void MenuState::render()
{

}

bool MenuState::onEnter()
{
	std::cout << "Entering MenuState" << std::endl;
	return true;
}

bool MenuState::onExit()
{
	std::cout << "Exiting MenuState" << std::endl;
	return true;
}