#include "Camera.h"
#include "Game.h"

Camera::Camera()
:mTarget(NULL)
,mPosition(0,0)
{
}

Camera::~Camera()
{
}
Vector2D Camera::getPosition()
{
	if (mTarget != 0)
	{
		Vector2D pos(mTarget->m_x - (TheGame::Instance()->getWidth() / 2), mTarget->m_y - (TheGame::Instance()->getHeight() / 2));

		return pos;
	}
	return mPosition;
}

void Camera::update(Vector2D velocity)
{
	mPosition += velocity;

	if (mPosition.m_x < 0)
	{
		//mPosition.m_x = 0;
	}
}

bool Camera::isOnSrceen(Vector2D position)
{
	if (position.getX() >(getPosition().getX() - 10) && //Buffer of 10 px
		position.getX() < (getPosition().getX() + TheGame::Instance()->getWidth()) &&
		position.getY() > (getPosition().getY() - 10) &&
		position.getY() < (getPosition().getY() + TheGame::Instance()->getHeight()))
	{
		return true;
	}
	return false;
}