#include "Player.h"

Player::Player(const LoaderParams* pParams)
: SDLGameObject(pParams)
{

}

void Player::draw()
{
	SDLGameObject::draw();
}

void Player::update(Uint32 dTime)
{
	mAcceleration.setX(1);
	//mCurrentFrame = int(((SDL_GetTicks() / 100) % 6));
	SDLGameObject::update(dTime);
}

void Player::clean()
{

}