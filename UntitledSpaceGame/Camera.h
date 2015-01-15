#pragma once
#include "Vector2D.h"

class Camera
{
public:
	Camera();
	~Camera();

	void update(Vector2D velocity);
	void setTarget(Vector2D* target) { mTarget = target; }
	void setPosition(Vector2D position) { mPosition = position; }
	bool isOnSrceen(Vector2D position);

	Vector2D getPosition();
private:

	//Camera Target
	Vector2D* mTarget;

	//Camera Position
	Vector2D mPosition;
};