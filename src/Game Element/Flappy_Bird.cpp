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
const int Flappy_Bird::screenHeight = 600;
const int Flappy_Bird::screenWidth = 1200;
const float Flappy_Bird::modifyVolume = 0.1f;
Flappy_Bird::Flappy_Bird()
{
	srand(unsigned(NULL));
	InitWindow(screenWidth, screenHeight, "Flappy Bird");
	InitAudioDevice();
	myMusicMenu = LoadMusicStream("assets/sound/Menu.ogg");
	mySoundMenu = LoadSound("assets/sound/menuSelector.wav");
	myGameLoss = LoadSound("assets/sound/LossSong.wav");
	gameplayMusic = LoadMusicStream("assets/sound/musicGameplay.ogg");
	controlsTexture = LoadTexture("assets/controls.png");
	controlsTexture.width = GetScreenWidth();
	controlsTexture.height = GetScreenHeight();
	controlsTexture.width /= 2;
	controlsTexture.height /= 3;
	inGame = true;
	gameStatus = MENU;
	titleTexture = LoadTexture("assets/coolText/Title.png");
	playTexture = LoadTexture("assets/coolText/Play.png");
	playTexture.width = static_cast<int>(playTexture.width / sizeDecrease);
	playTexture.height = static_cast<int>(playTexture.height / sizeDecrease);
	exitTexture = LoadTexture("assets/coolText/Exit.png");
	exitTexture.width = static_cast<int>(exitTexture.width / sizeDecrease);
	exitTexture.height = static_cast<int>(exitTexture.height / sizeDecrease);
	creditsTexture = LoadTexture("assets/coolText/Credits.png");
	creditsTexture.width = static_cast<int>(creditsTexture.width / sizeDecrease);
	creditsTexture.height = static_cast<int>(creditsTexture.height / sizeDecrease);
	creditsScreenTexture = LoadTexture("assets/CreditsScreen.png");
	creditsScreenTexture.width = GetScreenWidth();
	creditsScreenTexture.height = GetScreenHeight();
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
	myState = PLAY;
	playColor = WHITE;
	exitColor = GRAY;
	creditsColor = GRAY;
}
Flappy_Bird::~Flappy_Bird()
{
	if (player)delete player;
	if (background)delete background;
	UnloadTexture(titleTexture);
	UnloadTexture(playTexture);
	UnloadTexture(birdSkin);
	UnloadTexture(exitTexture);
	UnloadTexture(creditsTexture);
	UnloadTexture(skinPipeline);
	UnloadTexture(creditsScreenTexture);
	UnloadTexture(skinBackGround1);
	UnloadTexture(skinBackGround2);
	UnloadSound(mySoundMenu);
	UnloadSound(myGameLoss);
	UnloadMusicStream(gameplayMusic);
	UnloadTexture(controlsTexture);
	for (int i = 0; i < cantPipeline; i++)
	{
		if (pipe[i])delete pipe[i];
	}
	UnloadMusicStream(myMusicMenu);
	CloseAudioDevice();
	CloseWindow();
}
void Flappy_Bird::Play()
{
	while (inGame)
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
		updateOptions();
		break;
	case GAME:
		initGame();
		updateGame();
		updateOptions();
		break;
	case CREDITS_SCREEN:
		updateCredits();
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
	ClearBackground(BLACK);
	switch (gameStatus)
	{
	case MENU:
		drawMenu();
		break;
	case GAME:
		drawGame();
		break;
	case CREDITS_SCREEN:
		drawCredits();
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
		PlayMusicStream(myMusicMenu);
	}
}
void Flappy_Bird::updateMenu()
{
	if (menuInited)
	{
		UpdateMusicStream(myMusicMenu);
		switch (myState)
		{
		case PLAY:
			if (IsKeyReleased(KEY_ENTER))
			{
				gameStatus = GAME;
			}
			if (IsKeyReleased(KEY_UP))
			{
				myState = EXIT;
				resetColorMenu();
				exitColor = WHITE;
				PlaySound(mySoundMenu);
			}
			if (IsKeyReleased(KEY_DOWN))
			{
				myState = CREDITS;
				resetColorMenu();
				creditsColor = WHITE;
				PlaySound(mySoundMenu);
			}
			break;
		case CREDITS:
			if (IsKeyReleased(KEY_ENTER))
			{
				gameStatus = CREDITS_SCREEN;
			}
			if (IsKeyReleased(KEY_UP))
			{
				myState = PLAY;
				resetColorMenu();
				playColor = WHITE;
				PlaySound(mySoundMenu);
			}
			if (IsKeyReleased(KEY_DOWN))
			{
				myState = EXIT;
				resetColorMenu();
				exitColor = WHITE;
				PlaySound(mySoundMenu);
			}
			break;	
		case EXIT:
			if (IsKeyReleased(KEY_ENTER))
			{
				inGame = false;
			}
			if (IsKeyReleased(KEY_UP))
			{
				myState = CREDITS;
				resetColorMenu();
				creditsColor = WHITE;
				PlaySound(mySoundMenu);
			}
			if (IsKeyReleased(KEY_DOWN))
			{
				myState = PLAY;
				resetColorMenu();
				playColor = WHITE;
				PlaySound(mySoundMenu);
			}
			break;
		}
	}
}
void Flappy_Bird::drawMenu()
{
	if (menuInited)
	{
		DrawTexture(skinBackGround1, 0, 0, WHITE);
		DrawTexture(skinBackGround2, 0, 0, WHITE);
		DrawTexture(titleTexture,static_cast<int>((GetScreenWidth()/2) - (titleTexture.width/2)),
			distanceTitleTopY,WHITE);
		int aux = static_cast<int>((GetScreenHeight() - distanceTitleBackY - exitTexture.height ));
		DrawTexture(exitTexture, distanceMenuLeftX,
			aux, exitColor);
		aux -= distanceMenuToMenu + creditsTexture.height;
		DrawTexture(creditsTexture, distanceMenuLeftX,
			aux, creditsColor);
		aux -= distanceMenuToMenu + playTexture.height;
		DrawTexture(playTexture, distanceMenuLeftX ,
			aux, playColor);
		DrawTexture(controlsTexture,GetScreenWidth() - controlsTexture.width,
			GetScreenHeight() - controlsTexture.height, BLACK);
	}
}
void Flappy_Bird::resetColorMenu()
{
	playColor = GRAY;
	exitColor = GRAY;
	creditsColor = GRAY;
}
void Flappy_Bird::initGame()
{
	if (!gameInited)
	{
		menuInited = false;
		gameInited = true;
		scoreInited = false;
		StopMusicStream(myMusicMenu);
		for (int i = 0; i < cantPipeline; i++)
		{
			pipe[i]->init();
		}
		PlayMusicStream(gameplayMusic);
		player->reset();
	}
}
void Flappy_Bird::updateGame()
{
	if (gameInited)
	{
		if (!Pipeline::playerCollision)
		{
			UpdateMusicStream(gameplayMusic);
			if (!Player::pause)
			{
				background->update();
			}
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
			StopMusicStream(gameplayMusic);
			PlaySound(myGameLoss);
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
		DrawText(TextFormat("%02i", player->getPoints()), (GetScreenWidth() / 2)
				- correctionFontPosition, distanceTitleTopY, fontSizeScore, BLACK);
	}
}
void Flappy_Bird::updateOptions()
{
	if (IsKeyReleased(KEY_O))
	{
		volume -= modifyVolume;
		if (volume > 1.0f)
		{
			volume = 1.0f;
		}
		SetMasterVolume(volume);
	}
	if (IsKeyReleased(KEY_P))
	{
		volume += modifyVolume;
		if (volume < 0.001f)
		{
			volume = 0.000f;
		}
		SetMasterVolume(volume);
	}
	if (IsKeyReleased(KEY_BACKSPACE))
	{
		cout << "enter" << endl;
		gameStatus = MENU;
	}
}
void Flappy_Bird::updateCredits()
{
	UpdateMusicStream(myMusicMenu);
	if (IsKeyReleased(KEY_ENTER))
	{
		gameStatus = MENU;
	}
}
void Flappy_Bird::drawCredits()
{
	DrawTexture(skinBackGround1, 0, 0, WHITE);
	DrawTexture(skinBackGround2, 0, 0, WHITE);
	DrawTexture(creditsScreenTexture, 0, 0, BLACK);
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
		DrawText(FormatText("Total Score: %02i", player->getPoints())
			, (GetScreenWidth()/2) - correctionFontPosition * 3, (GetScreenHeight()/3) - correctionFontPosition * 2,fontSizeScore, WHITE);
		DrawTexture(exitTexture, (GetScreenWidth() / 2) - correctionFontPosition * 2,
			static_cast<int>((GetScreenHeight() - distanceTitleBackY * 2 - exitTexture.height)), WHITE);
	}
}
