#include "Flappy_Bird.h"
#include <ctime>
#include <cstdlib>
#include <iostream>
#include "raylib.h"
#include "Game Objects/Player.h"
#include "Game Element/Sky.h"
#include "Game Objects/Pipeline.h"
using namespace std;
const float Flappy_Bird::drawnCorrectionWidth = 12.0f;
const float Flappy_Bird::drawnCorrectionHeight = 3.0f;
const int Flappy_Bird::screenHeight = 400;
const int Flappy_Bird::screenWidth = 800;
Flappy_Bird::Flappy_Bird()
{
	srand(unsigned(NULL));
	InitWindow(800, 400, "Flappy Bird");
	inGame = true;
	gameStatus = MENU;
	birdSkin = LoadTexture("assets/Kenney.nl/PNG/Planes/planeRed1.png");
	birdSkin.height = static_cast<int>(birdHeight+ drawnCorrectionHeight);
	birdSkin.width = static_cast<int>(birdWidth+ drawnCorrectionWidth);
	skinBackGround1 = LoadTexture("assets/sky1Background.png");
	skinBackGround2 = LoadTexture("assets/sky2Background.png");
	skinBackGround1.height = GetScreenHeight();
	skinBackGround1.width = GetScreenWidth();
	skinBackGround2.width = GetScreenWidth();
	skinPipeline = LoadTexture("assets/Pipeline.png");
	skinPipeline.width = pipelineWidth;
	skinPipeline.height = GetScreenHeight();
	player = new Player(birdSkin, birdHeight, birdWidth);
	background = new Sky(skinBackGround1, skinBackGround2);
	for (int i = 0; i < cantPipeline; i++)
	{
		pipe[i] = new Pipeline(skinPipeline, background1Speed, i * distanceBetweenPipes, distanceBetweenPipes);
	}
	menuInited = false;
	gameInited = false;
	scoreInited = false;
}
Flappy_Bird::~Flappy_Bird()
{
	if (player)delete player;
	if (background)delete background;
	UnloadTexture(birdSkin);
	UnloadTexture(skinPipeline);
	UnloadTexture(skinBackGround1);
	UnloadTexture(skinBackGround2);
	CloseWindow();
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
		initMenu();
		updateMenu();
		break;
	case GAME:
		initGame();
		updateGame();
		break;
	case SCORE:
		initScore();
		updateScore();
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
	case SCORE:
		drawScore();
		break;
	}
	EndDrawing();
}
void Flappy_Bird::initMenu()
{
	if (!menuInited)
	{
		menuInited = true;
		gameInited = false;
		scoreInited = false;
	}
}
void Flappy_Bird::updateMenu()
{
	if (menuInited)
	{
		if (IsKeyReleased(KEY_ENTER))
		{
			gameStatus = GAME;
		}
	}
}
void Flappy_Bird::drawMenu()
{
	if (menuInited)
	{
	}
}
void Flappy_Bird::initGame()
{
	if (!gameInited)
	{
		menuInited = false;
		gameInited = true;
		scoreInited = false;
		for (int i = 0; i < cantPipeline; i++)
		{
			pipe[i]->init();

		}
		player->reset();
	}
}
void Flappy_Bird::updateGame()
{
	if (gameInited)
	{
		if (!Pipeline::playerCollision)
		{
			background->update();
			player->input();
			player->move();
			for (int i = 0; i < cantPipeline; i++)
			{
				pipe[i]->update(player->getPlayerCollider());
				if (pipe[i]->getXPosition() + skinPipeline.width < 0)
				{
					if (i == 0)
					{
						pipe[0]->reset(pipe[cantPipeline - 1]->getXPosition());
					}
					else
					{
						pipe[i]->reset(pipe[i - 1]->getXPosition());
					}

				}
				pipe[i]->playerGetPoints(player);
			}		

		}
		else
		{
			gameStatus = SCORE;
		}

	}

}
void Flappy_Bird::drawGame()
{
	if (gameInited)
	{
		background->drawMe();
		for (int i = 0; i < cantPipeline; i++)
		{
			pipe[i]->drawMe();
		}
		player->drawMe();

	}
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
void Flappy_Bird::initScore()
{
	if (!scoreInited)
	{
		menuInited = false;
		gameInited = false;
		scoreInited = true;
	}
}
void Flappy_Bird::updateScore()
{
	if (scoreInited)
	{
		if (IsKeyReleased(KEY_ENTER))
		{
			gameStatus = MENU;
		}
	}
}
void Flappy_Bird::drawScore()
{
	if (scoreInited)
	{

	}
}
