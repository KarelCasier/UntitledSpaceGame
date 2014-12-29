#include "Player.h"
#include "InputHandler.h"

Player::Player(Camera* camera, const LoaderParams* pParams)
: Ship(camera, pParams)
{

}

void Player::draw()
{
	SDLGameObject::draw();
}

void Player::update(Uint32 dTime)
{
	//mAcceleration.setX(1);
	//mCurrentFrame = int(((SDL_GetTicks() / 100) % 6));
	handleInput();
	Ship::update(dTime);
}

void Player::handleInput()
{
	if (TheInputHandler::Instance()->getMouseButtonState(InputHandler::mouse_buttons::LEFT))
	{

	}



	//Keyboard Input
	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_RIGHT))
	{
		rotate(mRotationSpeed);
	}
	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_LEFT))
	{
		rotate(-mRotationSpeed);
	}
	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_UP))
	{
		fireEngine(true);
	}
	else
	{
		fireEngine(false);
	}
	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_DOWN))
	{
	 //mVelocity.setY(2);
	}


}

void Player::clean()
{

}