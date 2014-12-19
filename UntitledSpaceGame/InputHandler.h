#pragma once
#include <SDL.h>
#include <vector>

class InputHandler
{
public:

	static InputHandler* Instance()
	{
		if (s_pInstance == 0)
		{
			s_pInstance = new InputHandler();
		}
		return s_pInstance;
	}

	void update();
	void clean();

	//void initialiseJoysticks();
	//bool joysticksInitialised() {return mbJoysticksInitialised;}

private:

	//bool mbJoysticksInitialised;

	InputHandler();
	~InputHandler();

	//std::vector<SDL_Joystick*> m_joysticks;

	static InputHandler* s_pInstance;
};

typedef InputHandler TheInputHandler;