#pragma once

#include "GameState.h"
#include <vector>

class GameStateMachine
{
public:
	void PushState(GameState *pState);
	void ChangeState(GameState *pState);
	void PopState();

	void update(Uint32 dTime);
	void render();

private:
	std::vector<GameState*> mGameStates;
};