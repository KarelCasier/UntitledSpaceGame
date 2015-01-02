#pragma once
#include "Ship.h"

class Player : public Ship
{
public:

	Player(Camera* camera, const LoaderParams* pParams);

	virtual void draw();
	virtual void update(Uint32 dTime);
	void handleInput();
	virtual void clean();
};