#include "CollisionHandler.h"

double crossProduct(Vector2D& a, Vector2D& b)
{
	return (a.getX() * b.getY() - b.getX() * a.getY());
}

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

/**
* Check if bounding boxes do intersect. If one bounding box
* touches the other, they do intersect.
* @param a0, a1 first line
* @param b0, b1 second line
* @return <code>true</code> if they intersect,
*         <code>false</code> otherwise.
*/
bool lines_doBoundingBoxesIntersect(Vector2D& a0, Vector2D& a1, Vector2D& b0, Vector2D& b1) {
	return a0.getX() <= b1.getX()
		&& a1.getX() >= b0.getX()
		&& a0.getY() <= b1.getY()
		&& a1.getY() >= b0.getY();
}

/**
* Checks if a Point is on a line
* @param a0, a1 line
* @param b point
* @return <code>true</code> if point is on line, otherwise
*         <code>false</code>
*/
bool isPointOnLine(Vector2D& a0, Vector2D& a1, Vector2D& b) {
	double EPSILON = 0.000001;
	// Move the image, so that a.first is on (0|0)
	Vector2D aTmp[2] {Vector2D(0, 0), Vector2D(a1.getX() - a0.getX(), a1.getY() - a0.getY())};
	Vector2D bTmp = Vector2D(b.getX() - a0.getX(), b.getY() - a0.getY());
	double r = crossProduct(aTmp[1], bTmp);
	return abs(r) < EPSILON;
}

/**
* Checks if a point is right of a line. If the point is on the
* line, it is not right of the line.
* @param a0, a1 line
* @param b the point
* @return <code>true</code> if the point is right of the line,
*         <code>false</code> otherwise
*/
bool isPointRightOfLine(Vector2D& a0, Vector2D& a1, Vector2D& b) {
	// Move the image, so that a.first is on (0|0)
	Vector2D aTmp[2] = { Vector2D(0, 0), Vector2D(a1.getX() - a0.getX(), a1.getY() - a0.getY()) };
	Vector2D bTmp = Vector2D(b.getX() - a0.getX(), b.getY() - a0.getY());
	return crossProduct(aTmp[1], bTmp) < 0;
}

float sign(Vector2D& p1, Vector2D& p2, Vector2D& p3)
{
	return (p1.getX() - p3.getX()) * (p2.getY() - p3.getY()) - (p2.getX() - p3.getX()) * (p1.getY() - p3.getY());
}

bool PointInTriangle(Vector2D& pt, Vector2D& v1, Vector2D& v2, Vector2D& v3)
{
	bool b1, b2, b3;

	b1 = sign(pt, v1, v2) < 0.0f;
	b2 = sign(pt, v2, v3) < 0.0f;
	b3 = sign(pt, v3, v1) < 0.0f;

	return ((b1 == b2) && (b2 == b3));
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