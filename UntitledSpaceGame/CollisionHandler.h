#pragma once
#include "SDLGameObject.h"
#include "Vector2D.h"
#include <math.h>

/**
* Check if SDLGameObjects intersects
* @param object1
* @param object2
* @return bool isTouching
*/
bool checkCollision(SDLGameObject* object1, SDLGameObject* object2);
double crossProduct(Vector2D& a, Vector2D& b);
/**
* Check if bounding boxes do intersect. If one bounding box
* touches the other, they do intersect.
* @param a0, a1 first line
* @param b0, b1 second line
* @return <code>true</code> if they intersect,
*         <code>false</code> otherwise.
*/
bool lines_doBoundingBoxesIntersect(Vector2D& a0, Vector2D& a1, Vector2D& b0, Vector2D& b1);
/**
* Checks if a Point is on a line
* @param a0, a1 line
* @param b point
* @return <code>true</code> if point is on line, otherwise
*         <code>false</code>
*/
bool isPointOnLine(Vector2D& a0, Vector2D& a1, Vector2D& b);
/**
* Checks if a point is right of a line. If the point is on the
* line, it is not right of the line.
* @param a0, a1 line
* @param b the point
* @return <code>true</code> if the point is right of the line,
*         <code>false</code> otherwise
*/
bool isPointRightOfLine(Vector2D& a0, Vector2D& a1, Vector2D& b);

float sign(Vector2D& p1, Vector2D& p2, Vector2D& p3);

bool PointInTriangle(Vector2D& pt, Vector2D& v1, Vector2D& v2, Vector2D& v3);