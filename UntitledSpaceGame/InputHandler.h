#pragma once
#include <SDL.h>
#include <vector>
#include "Vector2D.h"
#include "Camera.h"

class InputHandler
{
public:

	enum mouse_buttons
	{
		LEFT = 0,
		MIDDLE = 1,
		RIGHT = 2
	};

	static InputHandler* Instance()
	{
		if (s_pInstance == 0)
		{
			s_pInstance = new InputHandler();
			return s_pInstance;
		}
		return s_pInstance;
	}

	void update();
	void handleEvents(SDL_Event& e);
	void clean();

	bool getMouseButtonState(int buttonNumber) { return mMouseButtonStates[buttonNumber]; }
	Vector2D* getMousePosition(Camera* camera);
	bool isKeyDown(SDL_Scancode key);

	void reset();

	//void initialiseJoysticks();
	//bool joysticksInitialised() {return mbJoysticksInitialised;}

private:

	//bool mbJoysticksInitialised;

	InputHandler();
	~InputHandler();

	//std::vector<SDL_Joystick*> m_joysticks;
	std::vector<bool> mMouseButtonStates;

	Vector2D* mMousePosition;
	Vector2D* relativeMousePosition;

	const Uint8* mKeyStates;

	//Private functions to handle input events

	// handle keyboard events
	void onKeyDown();
	void onKeyUp();
	// handle mouse events
	void onMouseMove(SDL_Event& e);
	void onMouseButtonDown(SDL_Event& e);
	void onMouseButtonUp(SDL_Event& e);

	Vector2D prevCamPos;

	static InputHandler* s_pInstance;
};

typedef InputHandler TheInputHandler;