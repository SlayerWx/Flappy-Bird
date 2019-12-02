#ifndef FLAPPY_BIRD_H
#define FLAPPY_BIRD_H
#include <ctime>
#include <cstdlib>
#include "raylib.h"
#include "Game Objects/Player.h"
#include "Game Element/Sky.h"
#include "Game Objects/Pipeline.h"
enum GameStage
{
	MENU, GAME,CREDITS_SCREEN, SCORE
};
enum MenuState
{
	PLAY,CREDITS,EXIT
};
static const int cantPipeline = 10;
class Flappy_Bird
{
public:
	Flappy_Bird();
	~Flappy_Bird();
	void Play();
private:
	bool inGame;
	Player* player;
	Pipeline* pipe[cantPipeline];
	Sky* background;
	GameStage gameStatus;
	Texture2D skinBackGround1;
	Texture2D skinBackGround2;
	Texture2D birdSkin;
	const float birdHeight = 30.0f;
	const float birdWidth = 30.0f;
	Texture2D skinPipeline;
	const float distanceBetweenPipes = 150.0f;
	const int pipelineWidth = 30;
	Texture2D titleTexture;
	Texture2D playTexture;
	Texture2D creditsTexture;
	Texture2D exitTexture;
	Texture2D creditsScreenTexture;
	const int distanceTitleTopY = 5;
	const int distanceMenuLeftX = 7;
	const int distanceMenuToMenu = 4;
	const int distanceTitleBackY = 8;
	const float sizeDecrease = 1.5f;
	Color playColor;
	Color exitColor;
	Color creditsColor;
	static const float drawnCorrectionWidth;
	static const float drawnCorrectionHeight;
	static const int screenHeight;
	static const int screenWidth;
	MenuState myState;
	void update();
	void draw();

	bool menuInited;
	void initMenu();
	void updateMenu();
	void drawMenu();
	void resetColorMenu();

	bool gameInited;
	void initGame();
	void updateGame();
	void drawGame();

	void updateOptions();
	void drawOptions();

	void updateCredits();
	void drawCredits();

	bool scoreInited;
	void initScore();
	void updateScore();
	void drawScore();
};
#endif