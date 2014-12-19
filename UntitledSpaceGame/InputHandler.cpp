#include "InputHandler.h"
#include <iostream>
/*
void InputHandler::initialiseJoysticks()
{
	if (SDL_WasInit(SDL_INIT_JOYSTICK) == 0)
	{
		SDL_InitSubSystem(SDL_INIT_JOYSTICK);
	}
	if (SDL_NumJoysticks() > 0)
	{
		for (int i = 0; i < SDL_NumJoysticks(); i++)
		{
			SDL_Joystick* joy = SDL_JoystickOpen(i);

			if (SDL_JoystickOpened(i) == 1)
			{
				m_joysticks.push_back(joy);
			}
			else {
				std::cout << SDL_GetError();
			}
		}
		SDL_JoystickEventState(SDL_ENABLE);
		//mbJoysticksInitialised = true;

		std::cout << "Initialised " << m_joysticks.size() << "joystick(s)";
	}
	else {
		mbJoysticksInitialised = false;
	}
}
*/
InputHandler::InputHandler()
//:mbJoysticksInitialised(false)
{
}


InputHandler::~InputHandler()
{
}
