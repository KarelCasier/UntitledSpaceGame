#pragma once

#include "GameState.h"

#include <vector>
#include "GameObject.h"
#include "Camera.h"
#include "Player.h"

class PlayState : public GameState
{
public:
	virtual void update(Uint32 dTime);
	virtual void render();

	virtual bool onEnter();
	virtual bool onExit();

	virtual std::string getStateID() const { return s_playID; }

private:
	static const std::string s_playID;

	std::vector<GameObject*> mGameObjects;

	Camera* WorldCamera;
	Camera* UICamera;

	Vector2D testLoc;
	Player * mpPlayer;
};