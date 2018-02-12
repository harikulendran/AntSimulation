#include "Cell.h"

void Cell::evaporate() {
	pLevel *= (1.0 - EVAPORATION_RATE);
}

void Cell::add(bool returning) {
	pLevel += (returning) ? RETURN_AMOUNT : SCOUT_AMOUNT;
}

bool Cell::isFull() {
	return popSize < MAX_POP_SIZE;
}