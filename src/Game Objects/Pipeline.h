#ifndef PIPELINE_H
#define PIPELINE_H
#include <ctime>
#include <cstdlib>
#include "raylib.h"
#include "Game Objects/Player.h"
namespace FlappyBird
{
static const int minDistanceBetweenPipes = 90;
static const int maxDistanceBetweenPipes = 180;
static const int minPosY = 30;
static const int maxPosY = 180;
class Pipeline
{
public:
	Pipeline(Texture2D skin, float speed, float distance, float minDistance);
	~Pipeline();
	void update(Rectangle player);
	void drawMe();
	static bool playerCollision;
	static bool getPlayerCollision();
	float getXPosition();
	void reset(float lastPipeXPosition);
	void playerGetPoints(Player* player);
	void init();
private:
	Texture2D mySkin;
	Rectangle myCollider1;
	Rectangle myCollider2;
	float mySpeed;
	float myMinDistance;
	float myDistanceReset;
	void move();
	void collision(Rectangle player);
	static float newYDistance();
	static float newYPosition();
	void create();
	bool iCanGivePoints;
};
}
#endif
