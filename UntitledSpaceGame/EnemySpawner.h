#pragma once

#include "Enemy.h"
#include "Layer.h"
#include "Camera.h"
#include "Timer.h"
#include "Player.h"
#include "Game.h"

class EnemySpawner
{
public:
	EnemySpawner(Layer* gameLayer, Camera* cam, Player* player);

	void update();

	void spawnEnemy();


private:
	Layer* pGameLayer;
	Camera* pCamera;
	Timer spawnTimer;

	Uint32 spawnTime;

	Player* pPlayer;

	int spawnX[3] = { 1, 2, 3 };
	int spawnY[3] = { 2, 1, 3 };

	int locX;
	int locY;

	int winHeight, winWidth;
};

