#pragma once

#include <string>
#include <iostream>
#include <SDL.h>

//Pure abstract class for game states
class GameState
{
public:
	virtual bool update(Uint32 dTime) = 0;
	virtual void render() = 0;

	virtual bool onEnter() = 0;
	virtual bool onExit() = 0;

	virtual std::string getStateID() const = 0;
};