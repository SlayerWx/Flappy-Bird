#include "Game Element/Flappy_Bird.h"
using namespace FlappyBird;
int main()
{
	Flappy_Bird* game = new Flappy_Bird();
	game->Play();
	if (game)delete game;
	return 0;
}