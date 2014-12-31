#include <iostream>
#include "Game.h"
#include <stdexcept>

int main(int argc, char** argv)
{
	try
	{
		//std::cout << "Game Initializing...\n";
		if (TheGame::Instance()->init("Untitled Space Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1440, 900,false))
		{
			//std::cout << "Game Initialized!\n";
			TheGame::Instance()->run();
		}
		else
		{
			std::cout << "Game Initializing Failed - " << SDL_GetError() << "\n";
			return -1;
		}

		std::cout << "Game Closing.../n";
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
		return 1;
	}

	return 0;
}