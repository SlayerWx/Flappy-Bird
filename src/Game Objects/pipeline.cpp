#include "Pipeline.h"
#include <ctime>
#include <cstdlib>
#include "Game Objects/Player.h"
namespace FlappyBird
{
bool Pipeline::playerCollision = false;
Pipeline::Pipeline(Texture2D skin,float speed,float distance, float minDistance)
{
	mySpeed = speed;
	mySkin = skin;
	myCollider1.height = static_cast<float>(mySkin.height);
	myCollider2.height = myCollider1.height;
	myCollider1.width = static_cast<float>(mySkin.width);
	myCollider2.width = myCollider1.width;
	playerCollision = false;
	myMinDistance = minDistance;
	myDistanceReset = distance;
	init();
	create();
}
Pipeline::~Pipeline()
{
}

void Pipeline::update(Rectangle player)
{
	if (!Player::pause)
	{
		move();
		collision(player);
	}
}

void Pipeline::drawMe()
{
#if DEBUG
	DrawRectangle(static_cast<int>(myCollider1.x),
		static_cast<int>(myCollider1.y),
		static_cast<int>(myCollider1.width),
		static_cast<int>(myCollider1.height), RED);
	DrawRectangle(static_cast<int>(myCollider2.x),
		static_cast<int>(myCollider2.y),
		static_cast<int>(myCollider2.width),
		static_cast<int>(myCollider2.height), RED); 
#endif
	DrawTexture(mySkin, static_cast<int>(myCollider1.x),
		static_cast<int>(myCollider1.y), WHITE);
	DrawTexture(mySkin, static_cast<int>(myCollider2.x),
		static_cast<int>(myCollider2.y), WHITE);
}
bool Pipeline::getPlayerCollision()//static
{
	return playerCollision;
}
float Pipeline::getXPosition()
{
	return myCollider1.x;
}
void Pipeline::move()
{
	myCollider1.x -= mySpeed * GetFrameTime();
	myCollider2.x -= mySpeed * GetFrameTime();
}

void Pipeline::collision(Rectangle player)
{
	if (CheckCollisionRecs(player, myCollider1) || CheckCollisionRecs(player, myCollider2))
	{
		playerCollision = true;
	}

}
float Pipeline::newYDistance()//static
{
	return static_cast<float>(rand() % maxDistanceBetweenPipes + minDistanceBetweenPipes);
}
float Pipeline::newYPosition()//static
{
	return static_cast<float>(rand() % maxPosY + minPosY);
}

void Pipeline::create()
{
	float distance = newYDistance();
	float position = newYPosition();
	myCollider1.y = position - myCollider1.height;
	myCollider2.y = position + distance;
	iCanGivePoints = true;
}
void Pipeline::reset(float lastPipeXPosition)
{
	myCollider1.x = lastPipeXPosition + myMinDistance;
	myCollider2.x = lastPipeXPosition + myMinDistance;
	create();
}
void Pipeline::playerGetPoints(Player* player)
{
	if (player->getPosition().x > myCollider1.x + mySkin.width && iCanGivePoints)
	{
		player->increasePoints();
		iCanGivePoints = false;
	}
}
void Pipeline::init()
{
	myCollider1.x = static_cast<float>(GetScreenWidth()) + myDistanceReset;
	myCollider2.x = static_cast<float>(GetScreenWidth()) + myDistanceReset;
	playerCollision = false;
}
}