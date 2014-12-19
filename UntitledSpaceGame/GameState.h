#include <string>

//Pure abstract class for gamestates
class GameState
{
public:
	virtual void update() = 0;
	virtual void redner() = 0;

	virtual bool onEnter() = 0;
	virtual bool onExit() = 0;

	virtual std::string getStateID() const = 0;
};