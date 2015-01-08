#pragma once
#include <vector>
#include "SDLGameObject.h"
class LightTrail
{
public:



	void draw();
	void update();
	void clean();

	LightTrail(SDLGameObject* target, Camera* cam);
	~LightTrail();

	Vector2D* getNewPos();

private:

	std::vector<Vector2D*> mPrevPositions;
	SDLGameObject* pTarget;
	Camera* pCamera;
};

