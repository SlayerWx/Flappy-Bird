#ifndef SKY_H
#define SKY_H
#include "raylib.h"
#include "Game Objects/Back_Ground.h"
namespace FlappyBird
{
static const int backgroundLayers = 2;
static const float background1Speed = 90.0f;
static const float background2Speed = 140.0f;
class Sky
{
public:
	Sky(Texture2D newBackground1, Texture2D newBackground2);
	~Sky();
	void update();
	void drawMe();
private:
	BackGround* backGround[backgroundLayers];
	void parallax();
};
}
#endif
