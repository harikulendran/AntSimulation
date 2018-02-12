#pragma once
#include "Cell.h"

class World {
	private:
		double WIDTH, HEIGHT;

	public:
		Cell ***position;
		World(double width, double height);
		~World();
		bool inBounds(int x, int y);
};