#include "Game Element/Flappy_Bird.h"
void main()
{
	Flappy_Bird* game = new Flappy_Bird();
	game->Play();
	if (game)delete game;
}