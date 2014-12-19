#pragma once
#include "SDLGameObject.h"

class Player : public SDLGameObject
{
public:

	Player(const LoaderParams* pParams);

	void draw();
	void update(Uint32 dTime);
	void handleInput();
	void clean();
};