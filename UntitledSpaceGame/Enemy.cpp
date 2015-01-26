#include "Enemy.h"
#include <cmath>
#include "CollisionHandler.h"
#include "Game.h"

Enemy::Enemy(Camera* camera, const LoaderParams* pParams, SDLGameObject* target)
: Ship(camera, pParams)
, pTarget(target)
, pCamera(camera)
{
	fireEngine(true);
	enableFriction(true);

	fovLeft  = Vector2D(-30, 300);
	fovRight = Vector2D(30, 300);
}

void Enemy::draw()
{
	Ship::draw();
}

void Enemy::update(Uint32 dTime)
{
	//mAcceleration.setX(1);
	//mAcceleration.setY(1);
	///mCurrentFrame = int(((SDL_GetTicks() / 100) % 6));
	if (checkTargetinFOV())
	{
		fireGun();
	}
	computeAI();
	Ship::update(dTime);
}

void Enemy::computeAI()
{
	//rotate ship to direction of target
	Vector2D targetPos = pTarget->getPosition();
	Vector2D pos = getPosition();
	float preferredRotation = std::atan2(static_cast<float>(pos.getY() - targetPos.getY() - pTarget->getHeight()/2) , static_cast<float>(pos.getX() - targetPos.getX() - pTarget->getWidth()/2)) * (180.f/M_PI) - 90;
	
	int differenceTollerance = 10;
	if (std::abs(preferredRotation - getRotation()) > differenceTollerance)
	{
		if (preferredRotation > getRotation())
		{
			rotate(2);
		}
		else
		{
			rotate(-2);
		}
	}
	//setRotation(preferredRotation);
	//std::cout << preferredRotation << " | " << getRotation() << std::endl;
}

void Enemy::clean()
{
	Ship::clean();
}

bool Enemy::checkTargetinFOV()
{
	Vector2D centerOffset(getWidth()/2, getHeight()/2);
	centerOffset += getPosition();
	
	Vector2D LeftPositionOffset = Vector2D(
		-700 * std::cos((mRotation + 90)*(M_PI / 180)) - getWidth() / 2 * std::sin((mRotation + 90)*(M_PI / 180)),
		-700 * std::sin((mRotation + 90)*(M_PI / 180)) + getWidth() / 2 * std::cos((mRotation + 90)*(M_PI / 180)));

	Vector2D RightPositionOffset = Vector2D(
		-700 * std::cos((mRotation + 90)*(M_PI / 180)) - -getWidth() / 2 * std::sin((mRotation + 90)*(M_PI / 180)),
		-700 * std::sin((mRotation + 90)*(M_PI / 180)) + -getWidth() / 2 * std::cos((mRotation + 90)*(M_PI / 180)));

	LeftPositionOffset += centerOffset;
	RightPositionOffset += centerOffset;

	/*
	SDL_SetRenderDrawColor(TheGame::Instance()->getRenderer(), 142, 226, 255, 0xFF);
	SDL_RenderDrawLine(TheGame::Instance()->getRenderer(),
		getPosition().getX() + getWidth()/2 - pCamera->getPosition().getX(),
		getPosition().getY() + getHeight()/2 - pCamera->getPosition().getY(),
		LeftPositionOffset.getX() - pCamera->getPosition().getX(),
		LeftPositionOffset.getY() - pCamera->getPosition().getY());

	SDL_RenderDrawLine(TheGame::Instance()->getRenderer(),
		getPosition().getX() + getWidth() / 2 - pCamera->getPosition().getX(),
		getPosition().getY() + getHeight() / 2 - pCamera->getPosition().getY(),
		RightPositionOffset.getX() - pCamera->getPosition().getX(),
		RightPositionOffset.getY() - pCamera->getPosition().getY());
	*/
	

	if (PointInTriangle(pTarget->getPosition() + Vector2D(pTarget->getWidth() / 2, pTarget->getHeight() / 2), getPosition() + Vector2D(getWidth() / 2, getHeight() / 2), LeftPositionOffset, RightPositionOffset))
	{
		return true;
	}
	return false;
}