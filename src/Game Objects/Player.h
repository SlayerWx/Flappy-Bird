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
	Player();
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
	BirdState myState;
	float flappingTime;
	float speed;
	static const float maxFlappingTime;
	static const float gravity;
	void flapping();
	void falling();
};
#endif