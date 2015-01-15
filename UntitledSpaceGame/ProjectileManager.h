#pragma once
#include "Projectile.h"
#include <vector>

class ProjectileManager
{
public:
	ProjectileManager();

	static ProjectileManager* Instance()
	{
		if (s_pInstance == 0)
		{
			s_pInstance = new ProjectileManager();
		}

		return s_pInstance;
	}

	void draw();
	void update(Uint32 dTime);
	void clean();


	void addProjectile(Projectile* projectile);
	void destroyProjectile(Projectile* projectile);

private:
	static ProjectileManager* s_pInstance;
	std::vector<Projectile*> mProjectiles;
};

typedef ProjectileManager TheProjectileManager;
