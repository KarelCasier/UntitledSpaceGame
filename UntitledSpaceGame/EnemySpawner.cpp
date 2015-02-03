#include "EnemySpawner.h"


EnemySpawner::EnemySpawner(Layer* gameLayer, Camera* cam, Player* player)
:pGameLayer(gameLayer)
, pCamera(cam)
, pPlayer(player)
{
	spawnTime = 75 * 60;

	spawnTimer.start();

	locX = 0;
	locY = 0;

	winHeight = TheGame::Instance()->getHeight();
	winWidth = TheGame::Instance()->getWidth();
}

void EnemySpawner::update()
{
	if (spawnTimer.getTicks() >= spawnTime)
	{
		spawnEnemy();
		spawnTimer.start();
	}
}

void EnemySpawner::spawnEnemy()
{
	Vector2D pos = pCamera->getPosition() - Vector2D(200, 200);


	pGameLayer->push_back(new Enemy(pCamera, new LoaderParams(pos.getX() +(spawnX[locX]), pos.getY() + (spawnY(locY]), 100, 100, "EnemyShip", .5, LoaderParams::ENEMY), pPlayer));

	locX++;
	locY++;

	if (locX >= 3)
	{
		locX = 0;
	}

	if (locY >= 3)
	{
		locY = 0;
	}

}