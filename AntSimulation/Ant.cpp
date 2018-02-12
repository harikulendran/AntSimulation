#include "Ant.h"
#include <math.h>
#include <random>
#include <time.h>

Pos::Pos(int _x, int _y) : x(_x), y(_y) {}

Ant::Ant(World* _world, int x, int y) : world(_world), cPos(x,y) {
	currentLocation = world->position[x][y];
	srand(time(NULL));
}

void Ant::move() {
	double pL = world->position[cPos.x + 1][cPos.y]->pLevel;
	double pR = world->position[cPos.x][cPos.y + 1]->pLevel;

	double pM = 0.5*(1 + tanh(((pL + pR) / 100.0) - 1));

	if ((double)(rand() % 100) / 100.0 > pM)
		return;

	double probL = pow(5 + pL, 2) / (pow(5 + pL, 2) + pow(5 + pR, 2));
	double probR = pow(5 + pR, 2) / (pow(5 + pL, 2) + pow(5 + pR, 2));

	if (probL > probR)

}

bool Ant::checkCell(int x, int y) {
	if (!world->inBounds(x, y))
		return false;
	if (world->position[x][y]->isFull())
		return false;
	return true;
}