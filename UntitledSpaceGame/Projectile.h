#pragma once

#include "SDLGameObject.h"

class Projectile : public SDLGameObject
{
public:

	enum Type
	{
		REGULAR,
		MISSLE
	};

	Projectile(Camera* camera, LoaderParams* pParams);

	virtual void update(Uint32 dTime);
	virtual void draw();
	virtual void clean();

	bool isGuided() { return mType == MISSLE; }
	Type getType() { return mType; }


private:

	Type mType;


};