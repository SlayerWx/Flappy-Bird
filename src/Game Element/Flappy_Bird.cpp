#include "Flappy_Bird.h"
Flappy_Bird::Flappy_Bird()
{
	InitWindow(800, 400, "Flappy Bird");
	inGame = true;
	gameStatus = GAME;
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
		updateMenu();
		break;
	case GAME:
		updateGame();
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
}

void Flappy_Bird::drawGame()
{
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
