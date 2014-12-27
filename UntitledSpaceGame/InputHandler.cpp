#include "InputHandler.h"
#include <iostream>
#include "Camera.h"

InputHandler* InputHandler::s_pInstance = 0;

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
	for (int i = 0; i < 3; i++) // Set each mouse state to false: left, middle, right
	{
		mMouseButtonStates.push_back(false);
	}

	mMousePosition = new Vector2D(0.f, 0.f);
	relativeMousePosition = new Vector2D(0.f, 0.f);
}

void InputHandler::handleEvents(SDL_Event &e)
{
	switch (e.type)
	{
	case SDL_MOUSEBUTTONDOWN:
		onMouseButtonDown(e);
		break;
	case SDL_MOUSEBUTTONUP:
		onMouseButtonUp(e);
		break;
	case SDL_MOUSEMOTION:
		onMouseMove(e);
		break;
	case SDL_KEYDOWN:
		onKeyDown();
		break;
	case SDL_KEYUP:
		onKeyUp();
		break;
	default:
		break;
	}

}
void InputHandler::onMouseButtonDown(SDL_Event &e)
{
	switch (e.button.button)
	{
	case SDL_BUTTON_LEFT:
		mMouseButtonStates[LEFT] = true;
		break;
	case SDL_BUTTON_MIDDLE:
		mMouseButtonStates[MIDDLE] = true;
		break;
	case SDL_BUTTON_RIGHT:
		mMouseButtonStates[RIGHT] = true;
	default:
		std::cout << "Mouse Button not mapped (pressed)" << std::endl;
		break;
	}
}

void InputHandler::onMouseButtonUp(SDL_Event &e)
{
	switch (e.button.button)
	{
	case SDL_BUTTON_LEFT:
		mMouseButtonStates[LEFT] = false;
		break;
	case SDL_BUTTON_MIDDLE:
		mMouseButtonStates[MIDDLE] = false;
		break;
	case SDL_BUTTON_RIGHT:
		mMouseButtonStates[RIGHT] = false;
	default:
		std::cout << "Mouse Button not mapped (released)" << std::endl;
		break;
	}
}

void InputHandler::onMouseMove(SDL_Event& e)
{
	mMousePosition->setX(e.motion.x);
	mMousePosition->setY(e.motion.y);
}

Vector2D* InputHandler::getMousePosition(Camera* camera)
{
	relativeMousePosition->m_x = mMousePosition->getX() + camera->getPosition().m_x;
	relativeMousePosition->m_y = mMousePosition->getY() + camera->getPosition().m_y;
	return relativeMousePosition;
}

void InputHandler::onKeyDown()
{
	mKeyStates = SDL_GetKeyboardState(0);  //Update keyboard states
}

void InputHandler::onKeyUp()
{
	mKeyStates = SDL_GetKeyboardState(0);  //Update keyboard states
}

bool InputHandler::isKeyDown(SDL_Scancode key)
{
	if (mKeyStates != 0) //Check if any key is pressed
	{
		if (mKeyStates[key]) //Check if specific key is pressed
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	return false;
}

void InputHandler::reset()
{
	for (bool state : mMouseButtonStates)
	{
		state = false;
	}
}

InputHandler::~InputHandler()
{
	delete mMousePosition;
	delete relativeMousePosition;
}
