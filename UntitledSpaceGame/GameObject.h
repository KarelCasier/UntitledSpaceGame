#pragma once
#include "LoaderParams.h"
#include <SDL.h>
#include "Camera.h"

class GameObject
{
public:
	virtual void draw(Camera* cam) = 0;
	virtual void update(Uint32 dTime) = 0;
	virtual void clean() = 0;

protected:

	GameObject(const LoaderParams* pParams) {}
	virtual ~GameObject() {}
};