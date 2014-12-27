#include "Camera.h"
#include "Game.h"

Camera::Camera()
:mTarget(0)
,mPosition(0,0)
{
}

Camera::~Camera()
{
	delete mTarget;
}
const Vector2D Camera::getPosition() const
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