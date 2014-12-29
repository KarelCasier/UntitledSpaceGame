#pragma once
#include "Ship.h"

class Player : public Ship
{
public:

	Player(Camera* camera, const LoaderParams* pParams);

	void draw();
	void update(Uint32 dTime);
	void handleInput();
	void clean();
};