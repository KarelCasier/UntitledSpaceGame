#include "Enemy.h"
#include <cmath>

Enemy::Enemy(Camera* camera, const LoaderParams* pParams, SDLGameObject* target)
: Ship(camera, pParams)
, pTarget(target)
{
	fireEngine(true);
	enableFriction(true);
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
	computeAI();
	Ship::update(dTime);
}

void Enemy::computeAI()
{
	//rotate ship to direction of target
	Vector2D targetPos = pTarget->getPosition();
	Vector2D pos = getPosition();
	float preferredRotation = std::atan2(static_cast<float>(pos.getY() - targetPos.getY()) , static_cast<float>(pos.getX() - targetPos.getX())) * (180.f/M_PI) - 90;
	
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