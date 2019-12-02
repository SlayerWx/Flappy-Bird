#ifndef BACK_GROUND_H
#define BACK_GROUND_H
#include "raylib.h"
class BackGround
{
public:
	BackGround(Texture2D myNewSkin, Vector2 myNewPosition,float speed);
	~BackGround();
	void move();
	void drawMe();
	void setPosition1(Vector2 newPosition);
	void setPosition2(Vector2 newPosition);
	Vector2 getPosition1();
	Vector2 getPosition2();
private:
	Texture2D mySkin;
	Vector2 myPosition1;
	Vector2 myPosition2;
	float mySpeed;
};
#endif