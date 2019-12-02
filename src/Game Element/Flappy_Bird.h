#ifndef FLAPPY_BIRD_H
#define FLAPPY_BIRD_H
#include "raylib.h"
#include "Game Objects/Player.h"
#include "Game Element/Sky.h"
enum GameStage
{
	MENU,GAME
};
class Flappy_Bird
{
public:
	Flappy_Bird();
	~Flappy_Bird();
	void Play();
private:
	bool inGame;
	Player* player;
	Sky* background;
	GameStage gameStatus;
	Texture2D birdSkin;
	Texture2D skinBackGround1;
	Texture2D skinBackGround2;
	const float birdHeight = 30.0f;
	const float birdWidth = 30.0f;
	static const float drawnCorrectionWidth;
	static const float drawnCorrectionHeight;
	void update();
	void draw();
	void updateMenu();
	void drawMenu();
	void updateGame();
	void drawGame();
	void updateOptions();
	void drawOptions();
	void updateCredits();
	void drawCredits();
};
#endif