#ifndef PLAYER_H
#define PLAYER_H
#include "raylib.h"
enum BirdState
{
	STAY,FLAPPING,FALLING
};
class Player
{
public:
	Player(Texture2D myNewSkin, float birdHeight, float birdWidth);
	~Player();
	void input();
	void move();
	void drawMe();
	void setPosition(Vector2 myNewPosition);
	Vector2 getPosition();
	BirdState getBirdState();
	void setBirdState(BirdState myNewState);
private:
	Rectangle myBody;
	Texture2D mySkin;
	BirdState myState;
	float flappingTime;
	float speed;
	static const float maxFlappingTime;
	static const float gravity;
	static const float drawnCorrection;
	void flapping();
	void falling();
};
#endif