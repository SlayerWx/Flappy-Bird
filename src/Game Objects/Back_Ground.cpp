#include "Back_Ground.h"
BackGround::BackGround(Texture2D myNewSkin, Vector2 myNewPosition, float speed)
{
	mySkin = myNewSkin;
	myPosition1 = myNewPosition;
	myPosition2.x = myPosition1.x + mySkin.width;
	myPosition2.y = 0;
	mySpeed = speed;
}

BackGround::~BackGround()
{
}
void BackGround::move()
{
	if (static_cast<int>(myPosition1.x) + mySkin.width < 0)
	{
		myPosition1.x = static_cast<float>(GetScreenWidth());
	}
	if (static_cast<int>(myPosition2.x) + mySkin.width < 0)
	{
		myPosition2.x = static_cast<float>(GetScreenWidth());
	}
	myPosition1.x -= mySpeed * GetFrameTime();
	myPosition2.x -= mySpeed * GetFrameTime();
}
void BackGround::drawMe()
{
	DrawTexture(mySkin, static_cast<int>(myPosition1.x), 
						static_cast<int>(myPosition1.y), WHITE);
	DrawTexture(mySkin, static_cast<int>(myPosition2.x),
		static_cast<int>(myPosition2.y), WHITE);
}
void BackGround::setPosition1(Vector2 newPosition)
{
	myPosition1 = newPosition;
}

Vector2 BackGround::getPosition1()
{
	return myPosition1;
}
void BackGround::setPosition2(Vector2 newPosition)
{
	myPosition1 = newPosition;
}

Vector2 BackGround::getPosition2()
{
	return myPosition2;
}