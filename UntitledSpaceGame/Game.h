#pragma once

#include <SDL.h>
#include "TextureManager.h"
#include "SDLGameObject.h"
#include "Player.h"
#include "Enemy.h"
#include "TextureManager.h"
#include <vector>

class Game
{
public:

	// create the public instance function
	static Game* Instance()
	{
		if (s_pInstance == 0)
		{
			s_pInstance = new Game();
			return s_pInstance;
		}
		return s_pInstance;
	}

	SDL_Renderer* getRenderer() const { return m_pRenderer; }

	bool init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);
	void run();
	bool isRunning() { return running; }

	// make the constructor private
private:

	Game();
	// create the s_pInstance member variable
	static Game* s_pInstance;
	// create the typedef

private:

	void update(Uint32 dTime);
	void processEvents();
	void render();

private:

	bool running;

	int mGameWidth;
	int mGameHeight;

	SDL_Window* m_pWindow;
	SDL_Renderer* m_pRenderer;

	SDL_Surface* testSurface = NULL;

	std::vector<GameObject*> mGameObjects;


};

typedef Game TheGame;