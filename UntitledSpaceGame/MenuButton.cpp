#include "MenuButton.h"

MenuButton::MenuButton(const LoaderParams* pParams)
: SDLGameObject(pParams)
{
	mCurrentFrame = MOUSE_OUT;
}

void MenuButton::draw()
{
	SDLGameObject::draw();
}

void MenuButton::update(Uint32 dTime)
{
	Vector2D* pMousePos = TheInputHandler::Instance()->getMousePosition();

	if (pMousePos->getX() < (mPosition.getX() + mWidth)
		&& pMousePos->getX() > mPosition.getX()
		&& pMousePos->getY() < (mPosition.getY() + mHeight)
		&& pMousePos->getY() > mPosition.getY())
	{
		mCurrentFrame = MOUSE_OVER;

		if (TheInputHandler::Instance()->getMouseButtonState(TheInputHandler::LEFT))
		{
			mCurrentFrame = CLICKED;
		}
	}
	else {
		mCurrentFrame = MOUSE_OUT;
	}
}