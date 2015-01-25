#pragma once
#include "Ship.h"

class Enemy : public Ship
{
public:

	Enemy(Camera* camera, const LoaderParams* pParams, SDLGameObject* target);

	void draw();
	void update(Uint32 dTime);
	void computeAI();
	void clean();

	bool checkTargetinFOV();

private:
	SDLGameObject* pTarget;
	Camera* pCamera;
	Vector2D fovLeft;
	Vector2D fovRight;
};