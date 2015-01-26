#pragma once

#include <vector>
#include "Particle.h"
#include "Timer.h"
#include "Ship.h"

class ParticleSystem
{
public:
	enum ParticleType
	{
		Player,
		Enemy
	};

	ParticleSystem(Camera* camera, SDLGameObject* target, Ship::Engine enginePosition, ParticleType type);

	void draw();
	void update(Uint32 dTime);
	void clean();

	bool isEnabled() { return bIsEnabled; }
	void setSpawnState(bool newState) { bIsEnabled = newState; }

private:
	Camera* pCamera;
	Timer mSpawnTimer;
	Uint32 mSpawnTime;
	SDLGameObject* pTarget;
	std::vector<Particle*> mParticles;
	bool bIsEnabled;
	Ship::Engine mEnginePositon;
	
	ParticleType mType;
};