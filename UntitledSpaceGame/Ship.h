#pragma once
#include "SDLGameObject.h"
#include "LoaderParams.h"
#include "Vector2D.h"
#include "Camera.h"
#include "Projectile.h"
#include <vector>
#include "Timer.h"

#include "LightTrail.h"

class ParticleSystem;

class Ship : public SDLGameObject
{
public:

	enum ShipType
	{
		Player,
		Enemy
	};

	enum Engine
	{
		CENTER,
		LEFT,
		RIGHT
	};

	Ship(Camera* camera, const LoaderParams* pParams, ShipType type);


	virtual void draw();
	virtual void update(Uint32 dTime);
	virtual void clean();

	void fireEngine(bool bState);
	void fireGun();

	void damage(int dmg)
	{
		health -= dmg;
	}

	Vector2D* getEnginePosition(Engine pos);

	void reload();

	bool isAlive()
	{
		return bIsAlive;
	}

protected:

	float mMaxSpeed;
	float mMass;
	float mEngineThrust;
	bool bEnginesFireing;
	bool bReloaded;

	int health;

	bool bIsAlive;

	Camera* pCamera;
	ShipType mType;


	int reloadTime;
	Timer reloadTimer;

	int mHitpoints;
	LightTrail mLightTrail;
	ParticleSystem* pParticleSystemLeft;
	ParticleSystem* pParticleSystemRight;
};

