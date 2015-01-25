#include "CollisionHandler.h"


bool checkCollision(SDLGameObject* o1, SDLGameObject* o2)
{
	int leftA, leftB;
	int rightA, rightB;
	int topA, topB;
	int bottomA, bottomB;

	SDLGameObject::CollisionBox& o1Box = o1->getCollisionBox();
	SDLGameObject::CollisionBox& o2Box = o2->getCollisionBox();

	//Calculate the sides of rect A
	leftA = o1->getPosition().getX() + o1Box.pos.getX();
	rightA = o1->getPosition().getX() + o1Box.pos.getX() + o1Box.width;
	topA = o1->getPosition().getY() + o1Box.pos.getY();
	bottomA = o1->getPosition().getY() + o1Box.pos.getY() + o1Box.height;

	//Calculate the sides of rect B
	leftB = o2->getPosition().getX() + o2Box.pos.getX();
	rightB = o2->getPosition().getX() + o2Box.pos.getX() + o2Box.width;
	topB = o2->getPosition().getY() + o2Box.pos.getY();
	bottomB = o2->getPosition().getY() + o2Box.pos.getY() + o2Box.height;

	//If any of the sides from A are outside of B
	if (bottomA <= topB){ return false; }
	if (topA >= bottomB){ return false; }
	if (rightA <= leftB){ return false; }
	if (leftA >= rightB){ return false; }

	//Else collision
	return true;
}

//bool checkCollision(SDLGameObject* object1, SDLGameObject* object2)
//{
//	//Check type
//	//if (object1->getTag() == object2->getTag)
//	{
//		//return false; //Objects of same type do not collide
//	}
//
//	Vector2D posA = object1->getPosition();
//	Vector2D posB = object2->getPosition();
//
//	int widthA = object1->getWidth();
//	int widthB = object2->getWidth();
//
//	int heightA = object1->getHeight();
//	int heightB = object2->getHeight();
//
//	if (posA.getX() > posB.getX() && posA.getX() < posB.getX() + widthB &&
//		posB.getY() > posB.getY() && posA.getY() < posB.getY() + heightB)
//	{ //Top left corner of A in B
//		return true;
//	}
//
//	if (posA.getX() + widthA > posB.getX() && posA.getX() + widthA < posB.getX() &&
//		posB.getY() + widthA > posB.getY() && posA.getY() + widthA < posB.getY())
//	{ //Bottom right corner of A in B
//		return true;
//	}
//
//	return false;
//
//}