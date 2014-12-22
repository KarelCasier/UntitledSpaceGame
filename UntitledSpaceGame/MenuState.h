#pragma once

#include "GameState.h"
#include "GameObject.h"
#include <vector>

class MenuState : public GameState
{
public:
	virtual void update(Uint32 dTime);
	virtual void render();

	virtual bool onEnter();
	virtual bool onExit();

	virtual std::string getStateID() const { return s_menuID; }

private:
	static const std::string s_menuID;

	std::vector<GameObject*> mGameObjects;
};