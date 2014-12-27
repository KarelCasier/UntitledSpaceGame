#include "Enemy.h"

Enemy::Enemy(Camera* camera, const LoaderParams* pParams)
: SDLGameObject(camera, pParams)
{
}

void Enemy::draw()
{
	SDLGameObject::draw();
}

void Enemy::update(Uint32 dTime)
{
	//mAcceleration.setX(1);
	//mAcceleration.setY(1);
	///mCurrentFrame = int(((SDL_GetTicks() / 100) % 6));
	SDLGameObject::update(dTime);
}

void Enemy::clean()
{

}