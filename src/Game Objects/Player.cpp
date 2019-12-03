#include "Player.h"
#include "raylib.h"
const float Player::maxFlappingTime = 0.4f;
const float Player::gravity = 130.0f;
const float Player::drawnCorrection = 8.0f;
bool Player::pause = false;
Player::Player(Texture2D myNewSkin,float birdHeight,float birdWidth)
{
	myBody.height = birdHeight;
	myBody.width = birdWidth;
	myBody.x = 50.0f;
	speed = 160.0f;
	mySkin = myNewSkin;
	reset();
}
Player::~Player()
{
}
void Player::input()
{
	if (IsKeyReleased(KEY_SPACE) && !pause)
	{
		flappingTime = 0.0f;
		myState = FLAPPING;
	}
	if (IsKeyReleased(KEY_ENTER))
	{
		pause = !pause;
	}
}
void Player::move()
{
	if (!pause)
	{
		flapping();
		falling();
	}
}
void Player::drawMe()
{
#if DEBUG
	DrawRectangle(static_cast<int>(myBody.x), static_cast<int>(myBody.y), 
		static_cast<int>(myBody.width), 
		static_cast<int>(myBody.height), YELLOW);
#endif
	DrawTexture(mySkin, static_cast<int>(myBody.x - drawnCorrection), static_cast<int>(myBody.y), WHITE);
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
Rectangle Player::getPlayerCollider()
{
	return myBody;
}
void Player::reset()
{
	pause = false;
	flappingTime = 0.0f;
	myState = STAY;
	myBody.y = static_cast<float>(GetScreenHeight() / 2);
	points = 0;
}
void Player::increasePoints()
{
	points++;
}
int Player::getPoints()
{
	return points;
}
void Player::flapping()
{
	if (myState == FLAPPING && myBody.y > 0)
	{
		setPosition({ myBody.x,myBody.y -= speed * GetFrameTime() });
		flappingTime += GetFrameTime();
		if (flappingTime > maxFlappingTime)
		{
			myState = FALLING;
			flappingTime = 0.0f;
		}
	}
	else if (myState != STAY)
	{
		myState = FALLING;
		flappingTime = 0.0f;
	}
}
void Player::falling()
{
	if (myState == FALLING && myBody.y < GetScreenHeight() - myBody.height)
	{
		setPosition({ myBody.x,myBody.y+= gravity * GetFrameTime()});
	}
}