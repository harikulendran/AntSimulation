#pragma once

class Cell {
	public:
		int popSize = 0;
	public:
		double pLevel = 0.0;
		void evaporate();
		void add(bool returning);
		bool isFull();
		Cell() = default;

	private:
		double EVAPORATION_RATE = 1.0 / 30.0;
		double SCOUT_AMOUNT = 1.0;
		double RETURN_AMOUNT = 4.0;
		int MAX_POP_SIZE = 4;
};