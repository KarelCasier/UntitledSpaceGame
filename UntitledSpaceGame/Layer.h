#pragma once
#include "GameObject.h"
#include "Enemy.h"
#include "Player.h"
#include <vector>

class Layer
{
public:

	enum LAYERS
	{
		Backdrop,
		Game,
		Forground,
		UI,
		NumberOfLayers
	};

	void update(Uint32 dTime);
	void draw();
	void clean();

	void handleCollisions();

	void push_back(GameObject* object);

	std::vector<GameObject*> mGameObjects;
};