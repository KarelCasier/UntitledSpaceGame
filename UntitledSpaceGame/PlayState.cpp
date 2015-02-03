#include "PlayState.h"
#include "InputHandler.h"
#include "Game.h"
#include "ProjectileManager.h"


const std::string PlayState::s_playID = "PLAY";

bool PlayState::update(Uint32 dTime)
{
	mEnemySpawner->update();

	TheProjectileManager::Instance()->update(dTime);

	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_ESCAPE))
	{
		TheGame::Instance()->getStateMachine()->pushState(new PauseState());
	}

	for (int i = 0; i < Layer::NumberOfLayers; i++)
	{
		mLayers[i]->update(dTime);
	}
	
	//Position Camera after updating location to avoid jitter of plane
	Vector2D pos( 
		mpPlayer->getPosition().m_x - (TheGame::Instance()->getWidth() / 2) + (mpPlayer->getWidth() / 2),
		mpPlayer->getPosition().m_y - (TheGame::Instance()->getHeight() / 2) + (mpPlayer->getHeight() / 2)
		);

	mUniverseLayerBot->update(dTime);
	mUniverseLayerTop->update(dTime);
	
	WorldCamera->setPosition(pos); //Center Camera on player
	ParalaxCameraMidground->setPosition(WorldCamera->getPosition() / 1.5);
	ParalaxCameraBackground->setPosition(ParalaxCameraMidground->getPosition() / 2);

	//check Collisions
	mLayers[Layer::Game]->handleCollisions();

	return false;
}

void PlayState::render()
{
	mUniverseLayerBot->draw();
	mUniverseLayerTop->draw();

	for (int i = 0; i < Layer::NumberOfLayers; i++)
	{
		mLayers[i]->draw();
	}

	TheProjectileManager::Instance()->draw();
}

bool PlayState::onEnter()
{
	std::cout << "Entering PlayState" << std::endl;
	//Set up Cameras
	WorldCamera					= new Camera;
	ParalaxCameraBackground     = new Camera;
	ParalaxCameraMidground		= new Camera;
	UICamera					 = new Camera;

	//Set up Layers
	for (int i        = 0; i < Layer::NumberOfLayers; i++)
	{
		mLayers.push_back(new Layer());
	}

	mUniverseLayerTop = new Universe(ParalaxCameraMidground,1234);
	mUniverseLayerBot = new Universe(ParalaxCameraBackground, 1234);

	TheTextureManager::Instance()->load("Assets/EnemyShip.png", "EnemyShip", TheGame::Instance()->getRenderer());
	TheTextureManager::Instance()->load("Assets/Ship.png",      "Player",		TheGame::Instance()->getRenderer());

	//mLayers[LAYERS::Game]->push_back(new Enemy(WorldCamera, new LoaderParams(100, 100, 100, 100, "Player",1)));

	mpPlayer = new Player(WorldCamera, new LoaderParams(0, 0, 100, 100, "Player", .7, LoaderParams::ALLIED));
	mLayers[Layer::Game]->push_back(mpPlayer);

	//mLayers[Layer::Game]->push_back(new Enemy(WorldCamera, new LoaderParams(500, 500, 100, 100, "EnemyShip", .5, LoaderParams::ENEMY), mpPlayer));
	//mLayers[Layer::Game]->push_back(new Enemy(WorldCamera, new LoaderParams(5000, 500, 100, 100, "EnemyShip", .5, LoaderParams::ENEMY), mpPlayer));
	//mLayers[Layer::Game]->push_back(new Enemy(WorldCamera, new LoaderParams(-500, 5000, 100, 100, "EnemyShip", .5, LoaderParams::ENEMY), mpPlayer));
	//mLayers[Layer::Game]->push_back(new Enemy(WorldCamera, new LoaderParams(5000, 5500, 100, 100, "EnemyShip", .5, LoaderParams::ENEMY), mpPlayer));
	//mLayers[Layer::Game]->push_back(new Enemy(WorldCamera, new LoaderParams(1000, 50000, 100, 100, "EnemyShip", .5, LoaderParams::ENEMY), mpPlayer));
	//mLayers[Layer::Game]->push_back(new Enemy(WorldCamera, new LoaderParams(900, 2000, 100, 100, "EnemyShip", .5, LoaderParams::ENEMY), mpPlayer));

	mEnemySpawner = new EnemySpawner(mLayers[Layer::Game], WorldCamera, mpPlayer);

	//Setup camera
	Vector2D pos(
		mpPlayer->getPosition().m_x - (TheGame::Instance()->getWidth() / 2) + (mpPlayer->getWidth() / 2),
		mpPlayer->getPosition().m_y - (TheGame::Instance()->getHeight() / 2) + (mpPlayer->getHeight() / 2)
		);
	WorldCamera->setPosition(pos); //Center Camera on player
	return true;
}

bool PlayState::onExit()
{
	std::cout << "Exiting PlayState" << std::endl;
	for (int i = 0; i < Layer::NumberOfLayers; i++)
	{
		mLayers[i]->clean();
	}
	mUniverseLayerTop->clean();
	mUniverseLayerBot->clean();
	TheTextureManager::Instance()->clearFromTextureMap("Player");
	TheInputHandler::Instance()->reset();
	TheProjectileManager::Instance()->clean();
	delete ParalaxCameraBackground;
	delete ParalaxCameraMidground;
	delete UICamera;
	delete WorldCamera;
	delete mUniverseLayerTop;
	delete mUniverseLayerBot;
	delete mEnemySpawner;
	return true;
}