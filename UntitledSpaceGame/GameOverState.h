#pragma once

#include "GameState.h"
#include "GameObject.h"
#include <vector>
#include "Camera.h"

class GameOverState : public GameState
{
public:
	virtual void update(Uint32 dTime);
	virtual void render();

	virtual bool onEnter();
	virtual bool onExit();

	virtual std::string getStateID() const { return s_gameOverID; }

private:
	static const std::string s_gameOverID;

	std::vector<GameObject*> mGameObjects;

	Camera* UICamera;

	//callback functions
	static void exitGame();
	static void gameOverToMain();
};