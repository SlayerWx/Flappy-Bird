#include "Player.h"
#include "raylib.h"
const float Player::maxFlappingTime = 0.6f;
const float Player::gravity = 170.0f;
Player::Player()
{
	myBody.height = 30.0f;
	myBody.width = 30.0f;
	myBody.x = 50.0f;
	myBody.y = 0.0f;
	flappingTime = 0.0f;
	speed = 160.0f;
	myState = FALLING;
}
Player::~Player()
{
}
void Player::input()
{
	if (IsKeyReleased(KEY_SPACE))
	{
		flappingTime = 0.0f;
		myState = FLAPPING;
	}
}
void Player::move()
{
	flapping();
	falling();
}
void Player::drawMe()
{
	DrawRectangle(static_cast<int>(myBody.x), static_cast<int>(myBody.y), 
		static_cast<int>(myBody.width), 
		static_cast<int>(myBody.height), YELLOW);
}
void Player::setPosition(Vector2 myNewPosition)
{
	myBody.x = myNewPosition.x;
	myBody.y = myNewPosition.y;
}
Vector2 Player::getPosition()
{
	return {myBody.x,myBody.y};
}
BirdState Player::getBirdState()
{
	return myState;
}
void Player::setBirdState(BirdState myNewState)
{
	myState = myNewState;
}
void Player::flapping()
{
	if (myState == FLAPPING)
	{
		setPosition({ myBody.x,myBody.y -= speed * GetFrameTime() });
		flappingTime += GetFrameTime();
		if (flappingTime > maxFlappingTime)
		{
			myState = FALLING;
			flappingTime = 0.0f;
		}
	}
}
void Player::falling()
{
	if (myState == FALLING)
	{
		setPosition({ myBody.x,myBody.y+= gravity * GetFrameTime()});
	}
}