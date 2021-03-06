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
		double RAID_AMOUNT = 1.0, RAID_MAX = 1000.0;
		double RETURN_AMOUNT = 10.0, RETURN_MAX = 300.0;
		Cell* currentLocation = nullptr;
		World* world;

	private:
		bool checkCell(int x, int y);
		void updateWorld(double pMax, double pAmt);

	public:
		Pos cPos;
		bool hasPrey = false;
		bool raiding = true;

	public:
		Ant(World* _world, int x, int y);
		void move();
		void checkFood();
};