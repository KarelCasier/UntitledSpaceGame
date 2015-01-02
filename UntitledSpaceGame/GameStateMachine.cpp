#include "GameStateMachine.h"

void GameStateMachine::clean()
{
	while (!mGameStates.empty())
	{
		mGameStates.back()->onExit();

		delete mGameStates.back();

		mGameStates.erase(mGameStates.end());
	}
}

void GameStateMachine::update(Uint32 dTime)
{
	if (!mGameStates.empty())
	{
		mGameStates.back()->update(dTime);
	}
}

void GameStateMachine::render()
{
	if (!mGameStates.empty())
	{
		//for (GameState* state : mGameStates)
		{
			//state->render();
		}
		mGameStates.back()->render();
	}
}

void GameStateMachine::pushState(GameState *pState)
{
	mGameStates.push_back(pState);
	mGameStates.back()->onEnter();
}

void GameStateMachine::popState()
{
	if (!mGameStates.empty())
	{
		mGameStates.back()->onExit();
		mGameStates.pop_back();
	}

	//mGameStates.back()->resume();
}

void GameStateMachine::changeState(GameState *pState)
{
	if (!mGameStates.empty())
	{
		if (mGameStates.back()->getStateID() == pState->getStateID())
		{
			return; // do nothing
		}

		mGameStates.back()->onExit();
		mGameStates.pop_back();
		//clean();
	}

	// initialise it
	pState->onEnter();

	// push back our new state
	mGameStates.push_back(pState);
}
/*
void GameStateMachine::PushState(GameState* pState)
{
	mGameStates.push_back(pState);
	mGameStates.back()->onEnter();
}

void GameStateMachine::ChangeState(GameState* pState)
{
	if (!mGameStates.empty())
	{
		//Check not switching to the same state
		if (mGameStates.back()->getStateID() == pState->getStateID())
		{
			return;
		}
		//Check successful State exit
		if (mGameStates.back()->onExit())
		{
			//Delete memory used by the pointer
			delete mGameStates.back();
			//Remove the pointer from the array
			mGameStates.pop_back();

		}
	}

	//Push back new State
	mGameStates.push_back(pState);
	mGameStates.back()->onEnter();
}

void GameStateMachine::PopState()
{
	if (!mGameStates.empty())
	{
		//Check successful State exit
		if (mGameStates.back()->onExit())
		{
			//Delete memory used by the pointer
			delete mGameStates.back();
			//Remove the pointer from the array
			mGameStates.pop_back();
		}
	}
}

void GameStateMachine::update(Uint32 dTime)
{
	if (!mGameStates.empty())
	{
		mGameStates.back()->update(dTime);
	}
}

void GameStateMachine::render()
{
	if (!mGameStates.empty())
	{
		mGameStates.back()->render();
	}
}
*/