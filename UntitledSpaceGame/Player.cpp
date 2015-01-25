#include "Player.h"
#include "InputHandler.h"

Player::Player(Camera* camera, const LoaderParams* pParams)
: Ship(camera, pParams)
{

}

void Player::draw()
{
	Ship::draw();
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

	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_SPACE))
	{
		fireGun();
	}



	//Keyboard Input
	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_RIGHT) || TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_D))
	{
		rotate(mRotationSpeed);
	}
	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_LEFT) || TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_A))
	{
		rotate(-mRotationSpeed);
	}
	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_UP) || TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_W))
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
	Ship::clean();
}