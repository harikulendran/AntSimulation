#pragma once
#include "Cell.h"
#include "World.h"

class Pos {
	public:
		int x, y;
		Pos(int _x, int _y);
};

class Ant {
	private:
		double SCOUT_AMOUNT = 1.0;
		double RETURN_AMOUNT = 10.0;

	private:
		Cell* currentLocation = nullptr;
		Pos cPos;
		World* world;
		bool checkCell(int x, int y);

	public:
		Ant(World* _world, int x, int y);
		void move();
};