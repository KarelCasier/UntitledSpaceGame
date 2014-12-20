#include "PlayState.h"

const std::string PlayState::s_playID = "PLAY";

void PlayState::update(Uint32 dTime)
{

}

void PlayState::render()
{

}

bool PlayState::onEnter()
{
	std::cout << "Entering PlayState" << std::endl;
	return true;
}

bool PlayState::onExit()
{
	std::cout << "Exiting PlayState" << std::endl;
	return true;
}