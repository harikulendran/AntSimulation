#pragma once
#include "Cell.h"

class World {
	private:
		double WIDTH, HEIGHT;

	public:
		Cell ***position;
		int nestFood = 0;
	public:
		World(double width, double height, int percent, int richness);
		~World();
		bool inBounds(int x, int y);
};