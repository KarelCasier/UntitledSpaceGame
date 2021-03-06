#pragma once

#include "GameState.h"
#include "GameObject.h"
#include <vector>
#include "Camera.h"

class PauseState : public GameState
{
public:
	virtual bool update(Uint32 dTime);
	virtual void render();

	virtual bool onEnter();
	virtual bool onExit();

	virtual std::string getStateID() const { return s_pauseID; }

private:
	static const std::string s_pauseID;

	std::vector<GameObject*> mGameObjects;

	Camera* UICamera;

	//callback functions
	static void resumePlay();
	static void pauseToMain();
};