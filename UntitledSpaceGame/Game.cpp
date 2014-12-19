#include "Game.h"
#include <iostream>

Game* Game::s_pInstance = 0;

const Uint32 FPS = 60.f;
const Uint32 TimePerFrame = 1000.0f / FPS;

Game::Game()
	:m_pWindow(0),
	m_pRenderer(0)
{
}

//Called by main() to setup Game
bool Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen)
{
	int flags = 0;

	// store the game width and height
	mGameWidth = width;
	mGameHeight = height;

	if (fullscreen)
	{
		flags = SDL_WINDOW_FULLSCREEN;
	}

	// attempt to initialize SDL
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		std::cout << "SDL Initialized!\n";
		// initialize the window
		m_pWindow = SDL_CreateWindow(title, xpos, ypos, width, height, flags);

		if (m_pWindow != 0) // window init success
		{
			std::cout << "window creation success\n";
			m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, SDL_RENDERER_ACCELERATED);

			if (m_pRenderer != 0) // renderer init success
			{
				std::cout << "renderer creation success\n";
				SDL_SetRenderDrawColor(m_pRenderer, 0, 0, 0, 255);
			}
			else
			{
				std::cout << "renderer init fail\n";
				return false; // renderer init fail
			}
		}
		else
		{
			std::cout << "window init fail\n";
			return false; // window init fail
		}
	}
	else
	{
		std::cout << "SDL init fail\n";
		return false; // SDL init fail
	}
	return true;
}

//Called by main() after init
void Game::run()
{
	TheTextureManager::Instance()->load("Assets/Ship.png", "Player", m_pRenderer);
	//Set up game objects
	mGameObjects.push_back(new Player(new LoaderParams(100, 100, 127, 324, "character")));
	mGameObjects.push_back(new Enemy(new LoaderParams(500, 500, 127, 324, "character")));
	running = true;


	Uint32 frameStart = 0;
	Uint32 frameTime = 0;
	Uint32 timeSinceLastUpdate = 0;
	while (TheGame::Instance()->isRunning())
	{
		frameStart = SDL_GetTicks();
		timeSinceLastUpdate += frameTime;
		while (timeSinceLastUpdate > TimePerFrame)
		{
			timeSinceLastUpdate -= TimePerFrame;

			TheGame::Instance()->processEvents();
			TheGame::Instance()->update(TimePerFrame);
		}

		TheGame::Instance()->render();
		
		frameTime = SDL_GetTicks() - frameStart;

		//if (frameTime< DELAY_TIME)
		//{
		//	SDL_Delay((int)(DELAY_TIME - frameTime));
		//}
	}
SDL_Quit();
}

void Game::render()
{
	SDL_SetRenderDrawColor(m_pRenderer, 50, 50, 50, 255);
	SDL_RenderClear(m_pRenderer);

	for (GameObject* gameObject : mGameObjects)
	{
		gameObject->draw();
	}

	SDL_RenderPresent(m_pRenderer);
}

void Game::update(Uint32 dTime)
{
	for (GameObject* gameObject : mGameObjects)
	{
		gameObject->update(dTime);
	}

}

void Game::processEvents()
{
	//SDL_Event& e

}