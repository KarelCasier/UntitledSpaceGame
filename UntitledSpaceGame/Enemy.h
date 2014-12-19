#pragma once
#include "SDLGameObject.h"

class Enemy : public SDLGameObject
{
public:

	Enemy(const LoaderParams* pParams);

	void draw();
	void update(Uint32 dTime);
	void clean();
};