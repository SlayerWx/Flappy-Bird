#include "Flappy_Bird.h"
#include "Game Objects/Player.h"
Flappy_Bird::Flappy_Bird()
{
	InitWindow(800, 400, "Flappy Bird");
	inGame = true;
	gameStatus = GAME;
	player = new Player();
}
Flappy_Bird::~Flappy_Bird()
{
}

void Flappy_Bird::Play()
{
	while (inGame && !WindowShouldClose())
	{
		update();
		draw();
	}
}
void Flappy_Bird::update()
{
	switch (gameStatus)
	{
	case MENU:
		updateMenu();
		break;
	case GAME:
		updateGame();
		break;
	}
}
void Flappy_Bird::draw()
{
	BeginDrawing();
	ClearBackground(SKYBLUE);
	switch (gameStatus)
	{
	case MENU:
		drawMenu();
		break;
	case GAME:
		drawGame();
		break;
	}
	EndDrawing();
}
void Flappy_Bird::updateMenu()
{

};

void Flappy_Bird::drawMenu()
{
}

void Flappy_Bird::updateGame()
{
	player->input();
	player->move();
}
void Flappy_Bird::drawGame()
{
	player->drawMe();
}

void Flappy_Bird::updateOptions()
{
}

void Flappy_Bird::drawOptions()
{
}

void Flappy_Bird::updateCredits()
{
}

void Flappy_Bird::drawCredits()
{
}
