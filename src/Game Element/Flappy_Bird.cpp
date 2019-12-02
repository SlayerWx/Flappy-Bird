#include "Flappy_Bird.h"
#include "Game Objects/Player.h"
#include "Game Element/Sky.h"
const float Flappy_Bird::drawnCorrectionWidth = 12.0f;
const float Flappy_Bird::drawnCorrectionHeight = 3.0f;
Flappy_Bird::Flappy_Bird()
{
	InitWindow(800, 400, "Flappy Bird");
	inGame = true;
	gameStatus = GAME;
	birdSkin = LoadTexture("assets/Kenney.nl/PNG/Planes/planeRed1.png");
	birdSkin.height = static_cast<int>(birdHeight+ drawnCorrectionHeight);
	birdSkin.width = static_cast<int>(birdWidth+ drawnCorrectionWidth);
	skinBackGround1 = LoadTexture("assets/sky1Background.png");
	skinBackGround2 = LoadTexture("assets/sky2Background.png");
	skinBackGround1.height = GetScreenHeight();
	skinBackGround1.width = GetScreenWidth();
	skinBackGround2.width = GetScreenWidth();
	player = new Player(birdSkin, birdHeight, birdWidth);
	background = new Sky(skinBackGround1, skinBackGround2);
}
Flappy_Bird::~Flappy_Bird()
{
	if (player)delete player;
	if (background)delete background;
	UnloadTexture(birdSkin);
	//CloseWindow();
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
	background->update();
	player->input();
	player->move();
}
void Flappy_Bird::drawGame()
{
	background->drawMe();
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
