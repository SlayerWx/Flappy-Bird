#include "Sky.h"
Sky::Sky(Texture2D newBackground1,Texture2D newBackground2)
{
	for (int i = 0; i < backgroundLayers; i++)
	{
		backGround[i] = NULL;
	}
	backGround[0] = new BackGround(newBackground1, { 0,0 }, background1Speed);
	backGround[1] = new BackGround(newBackground2, { 0,0 }, background2Speed);
}
Sky::~Sky()
{
	for (int i = 0; i < backgroundLayers; i++)
	{
		if (backGround[i]) delete backGround[i];
	}
}
void Sky::update()
{
	parallax();
}
void Sky::drawMe()
{
	for (int i = 0; i < backgroundLayers; i++)
	{
		backGround[i]->drawMe();
	}
}
void Sky::parallax()
{
	for (int i = 0; i < backgroundLayers; i++)
	{
		backGround[i]->move();
	}
}