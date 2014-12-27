#pragma once

#include "SDLGameObject.h"

#include "LoaderParams.h"
#include "InputHandler.h"

class MenuButton : public SDLGameObject
{
public:

	MenuButton(Camera* camera, const LoaderParams* pParams, void (*callback)());

	virtual void draw();
	virtual void update(Uint32 dTime);
	virtual void clean();

private:

	enum buton_states
	{
		MOUSE_OUT = 1,
		MOUSE_OVER = 2,
		CLICKED = 3
	};

	//Function pointer for click callback
	void(*mCallback)();

	bool mbReleased;
};