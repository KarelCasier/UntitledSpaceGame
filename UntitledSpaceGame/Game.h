#pragma once

#include <SDL.h>
#include "TextureManager.h"
#include "SDLGameObject.h"
#include "Player.h"
#include "Enemy.h"
#include "TextureManager.h"
#include <vector>

#include "GameStateMachine.h"
#include "MenuState.h"
#include "PlayState.h"

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
	void quit();

	// make the constructor private
private:

	Game();
	// create the s_pInstance member variable
	static Game* s_pInstance;

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

	GameStateMachine* mpGameStateMachine;;

	SDL_Surface* testSurface = NULL;

	std::vector<GameObject*> mGameObjects;


};
// create the typedef
typedef Game TheGame;