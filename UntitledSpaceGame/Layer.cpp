#include "Layer.h"

void Layer::push_back(GameObject* object)
{
	mGameObjects.push_back(object);
}

void Layer::clean()
{
	for (int i = 0; i < mGameObjects.size(); i++)
	{
		mGameObjects[i]->clean();
	}
	mGameObjects.clear();
}

void Layer::update(Uint32 dTime)
{
	if (!mGameObjects.empty())
	{
		for (int i = 0; i < mGameObjects.size(); i++)
		{
			if (mGameObjects[i] != 0)
			{
				mGameObjects[i]->update(dTime);
			}
		}
	}
}

void Layer::draw()
{
	if (!mGameObjects.empty())
	{
		for (int i = 0; i < mGameObjects.size(); i++)
		{
			if (mGameObjects[i] != 0)
			{
				mGameObjects[i]->draw();
			}
		}
	}
}