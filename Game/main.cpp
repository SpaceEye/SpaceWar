#include "Game.h"

#define LENGTH 1440
#define HIGHT  720

int main()
{
	Game SpaceGame(LENGTH, HIGHT);

	SpaceGame.GameLoop();
	
	return 0;
}