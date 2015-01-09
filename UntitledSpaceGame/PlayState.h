#pragma once

#include "GameState.h"

#include <vector>
#include "GameObject.h"
#include "Camera.h"
#include "Player.h"
#include "Layer.h"
#include "Universe.h"

class PlayState : public GameState
{
public:
	virtual bool update(Uint32 dTime);
	virtual void render();

	virtual bool onEnter();
	virtual bool onExit();

	virtual std::string getStateID() const { return s_playID; }

	bool checkCollision(SDLGameObject* object1, SDLGameObject* object2);

private:

	enum LAYERS
	{
		Backdrop,
		Game,
		Forground,
		UI,
		NumberOfLayers
	};

	static const std::string s_playID;

	std::vector<Layer*> mLayers;

	Camera* WorldCamera;
	Camera* ParalaxCamera;
	Camera* UICamera;

	Universe* mUniverseLayerTop;
	Universe* mUniverseLayerBot;

	Player * mpPlayer;
};