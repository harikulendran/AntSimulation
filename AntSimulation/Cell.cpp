#include "Cell.h"
#include <random>
#include <time.h>

Cell::Cell(int percent, int richness) {
	srand(time(NULL));
	if (rand() % 100 < percent)
		source = richness;
}

void Cell::evaporate() {
	pLevel *= (1.0 - EVAPORATION_RATE);
}

void Cell::add(double amount) {
	pLevel += amount;
}

bool Cell::isFull() {
	return popSize >= MAX_POP_SIZE;
}

void Cell::moveHere() {
	popSize++;
}
void Cell::leaveHere() {
	popSize--;
}