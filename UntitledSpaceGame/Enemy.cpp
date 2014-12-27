#include "Enemy.h"

Enemy::Enemy(const LoaderParams* pParams)
: SDLGameObject(pParams)
{
}

void Enemy::draw(Camera* cam)
{
	SDLGameObject::draw(cam);
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