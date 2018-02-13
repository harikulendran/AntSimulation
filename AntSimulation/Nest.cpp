#include "Nest.h"

Nest::Nest() : Cell(10,10) {
	//Allow nest to hold more than regular cells
	MAX_POP_SIZE = 10000;
	source = 0;
}