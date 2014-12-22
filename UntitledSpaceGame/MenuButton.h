#pragma once

#include "SDLGameObject.h"

#include "LoaderParams.h"
#include "InputHandler.h"

class MenuButton : public SDLGameObject
{
public:

	MenuButton(const LoaderParams* pParams);

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
};