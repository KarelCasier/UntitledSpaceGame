#pragma once

#include <vector>
#include "Particle.h"
#include "Timer.h"

class ParticleSystem
{
public:
	ParticleSystem(Camera* camera, SDLGameObject* target);

	void draw();
	void update(Uint32 dTime);
	void clean();

private:
	Camera* pCamera;
	Timer mSpawnTimer;
	Uint32 mSpawnTime;
	SDLGameObject* pTarget;
	std::vector<Particle*> mParticles;
};