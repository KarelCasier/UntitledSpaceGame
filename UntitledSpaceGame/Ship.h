#pragma once
#include "SDLGameObject.h"
#include "LoaderParams.h"
#include "Vector2D.h"
#include "Camera.h"
#include "Projectile.h"
#include <vector>
#include "Timer.h"

class Ship : public SDLGameObject
{
public:
	Ship(Camera* camera, const LoaderParams* pParams);


	virtual void draw();
	virtual void update(Uint32 dTime);
	virtual void clean();

	void fireEngine(bool bState);
	void fireGun();

	void reload();

protected:

	float mDecay;
	float mMaxSpeed;
	float mMass;
	float mEngineThrust;
	bool bEnginesFireing;
	bool bReloaded;


	int reloadTime;
	Timer reloadTimer;

	int mHitpoints;

	std::vector<Projectile*> mProjectiles;
};

