#pragma once

#include "GameState.h"
#include <vector>

class GameStateMachine
{
public:
	void pushState(GameState *pState);
	void changeState(GameState *pState);
	void popState();
	void clean();

	void update(Uint32 dTime);
	void render();

private:
	std::vector<GameState*> mGameStates;
};