#pragma once
#include "GameObject.h"
#include "Enemy.h"
#include "Player.h"
#include <vector>

class Layer
{
public:

	void update(Uint32 dTime);
	void draw();
	void clean();

	void push_back(GameObject* object);

	std::vector<GameObject*> mGameObjects;
};