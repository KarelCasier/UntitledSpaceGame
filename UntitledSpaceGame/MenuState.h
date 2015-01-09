#pragma once

#include "GameState.h"
#include "GameObject.h"
#include <vector>
#include "Camera.h"
#include "Universe.h"

class MenuState : public GameState
{
public:
	virtual bool update(Uint32 dTime);
	virtual void render();

	virtual bool onEnter();
	virtual bool onExit();

	virtual std::string getStateID() const { return s_menuID; }

private:
	static const std::string s_menuID;

	std::vector<GameObject*> mGameObjects;

	Camera *UICamera;
	Camera *BackgroundCamera;

	Universe* backgroundUniverse;

	Vector2D moveCamera;


	//callback functions
	static void menuToPlay();
	static void exitFromMenu();
};