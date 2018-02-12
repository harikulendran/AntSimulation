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
	int mod = (raiding) ? 1 : -1;
	double pMax = (raiding) ? RAID_MAX : RETURN_MAX;
	double pAmt = (raiding) ? RAID_AMOUNT : (hasPrey) ? RETURN_AMOUNT : 0;

	double pL = (world->inBounds(cPos.x + mod,cPos.y)) ? world->position[cPos.x + mod][cPos.y]->pLevel : 0;
	double pR = (world->inBounds(cPos.x,cPos.y + mod)) ? world->position[cPos.x][cPos.y + mod]->pLevel : 0;

	double pM = 0.5*(1 + tanh(((pL + pR) / 100.0) - 1));

	if ((double)(rand() % 100) / 100.0 > pM)
		return;

	double probL = pow(5 + pL, 2) / (pow(5 + pL, 2) + pow(5 + pR, 2));

	if ((rand() % 100) / 100.0 < probL) {
		if (checkCell(cPos.x + mod, cPos.y)) {
			cPos.x += mod;
			updateWorld(pMax, pAmt);
		}
	} else {
		if (checkCell(cPos.x, cPos.y + mod)) {
			cPos.y += mod;
			updateWorld(pMax, pAmt);
		}
	}
}

void Ant::checkFood() {
	if (currentLocation->source > 0) {
		hasPrey = true;
		raiding = false;
		currentLocation->source--;
	}
	if (cPos.x == 0 && cPos.y == 0) {
		hasPrey = false;
		raiding = true;
	}
	if (cPos.x == 640 - 1 || cPos.y == 480 - 1) {
		raiding = false;
	}
}

void Ant::updateWorld(double pMax, double pAmt) {
	currentLocation->leaveHere();
	currentLocation = world->position[cPos.x][cPos.y];
	currentLocation->moveHere();
	if (currentLocation->pLevel < pMax)
		currentLocation->add(pAmt);
}

bool Ant::checkCell(int x, int y) {
	if (!world->inBounds(x, y))
		return false;
	if (world->position[x][y]->isFull())
		return false;
	return true;
}