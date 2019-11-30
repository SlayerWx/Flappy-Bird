#ifndef FLAPPY_BIRD_H
#define FLAPPY_BIRD_H
#include "raylib.h"
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
	GameStage gameStatus;
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