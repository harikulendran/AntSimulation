#pragma once

class Cell {
	public:
		int popSize = 0;
	public:
		double pLevel = 0.0;
		void evaporate();
		void add(double amount);
		bool isFull();
		void moveHere();
		Cell() = default;

	protected:
		double EVAPORATION_RATE = 1.0 / 30.0;
		int MAX_POP_SIZE = 20;
};