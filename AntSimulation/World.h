#pragma once
#include "Cell.h"
#include "Ant.h"

class World {
	private:
		double WIDTH, HEIGHT;
		Cell ***world;

	public:
		World(double width, double height);
};