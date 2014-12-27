#include "MenuButton.h"

MenuButton::MenuButton(Camera* camera, const LoaderParams* pParams, void (*callback)())
: SDLGameObject(camera, pParams)
, mCallback(callback)
{
	mCurrentFrame = MOUSE_OUT;
}

void MenuButton::draw()
{
	SDLGameObject::draw();
}

void MenuButton::update(Uint32 dTime)
{
	Vector2D* pMousePos = TheInputHandler::Instance()->getMousePosition(mCamera);

	if (pMousePos->getX() < (mPosition.getX() + mWidth)
		&& pMousePos->getX() > mPosition.getX()
		&& pMousePos->getY() < (mPosition.getY() + mHeight)
		&& pMousePos->getY() > mPosition.getY())
	{
		if (TheInputHandler::Instance()->getMouseButtonState(TheInputHandler::LEFT) && mbReleased)
		{
			mCurrentFrame = CLICKED;
			mCallback(); //call to the callback function
			mbReleased = false;
		}
		mCurrentFrame = MOUSE_OVER;
		mbReleased = true;
	}
	else {
		mCurrentFrame = MOUSE_OUT;
	}
}

void MenuButton::clean()
{
	SDLGameObject::clean();
}