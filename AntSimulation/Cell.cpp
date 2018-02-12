#include "Cell.h"

void Cell::evaporate() {
	pLevel *= (1.0 - EVAPORATION_RATE);
}

void Cell::add(double amount) {
	pLevel += amount;
}

bool Cell::isFull() {
	return popSize < MAX_POP_SIZE;
}

void Cell::moveHere() {
	popSize++;
}