#pragma once
#include "SDLGameObject.h"

class Player : public SDLGameObject
{
public:

	Player(Camera* camera, const LoaderParams* pParams);

	void draw();
	void update(Uint32 dTime);
	void handleInput();
	void clean();
};