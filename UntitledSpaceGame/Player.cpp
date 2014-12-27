#include "Player.h"
#include "InputHandler.h"

Player::Player(const LoaderParams* pParams)
: SDLGameObject(pParams)
{

}

void Player::draw(Camera* cam)
{
	SDLGameObject::draw(cam);
}

void Player::update(Uint32 dTime)
{
	//mAcceleration.setX(1);
	//mCurrentFrame = int(((SDL_GetTicks() / 100) % 6));
	handleInput();
	SDLGameObject::update(dTime);
}

void Player::handleInput()
{
	if (TheInputHandler::Instance()->getMouseButtonState(InputHandler::mouse_buttons::LEFT))
	{

	}

	//Move to mouse position
	Vector2D* mousePos = TheInputHandler::Instance()->getMousePosition();

	mVelocity = (*mousePos - mPosition) / 10;


	//Keyboard Input
	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_RIGHT))
	{
		mVelocity.setX(2);
	}
	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_LEFT))
	{
		mVelocity.setX(-2);
	}
	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_UP))
	{
		mVelocity.setY(-2);
	}
	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_DOWN))
	{
		mVelocity.setY(2);
	}


}

void Player::clean()
{

}