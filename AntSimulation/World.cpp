#include "World.h"

World::World(double width, double height) : WIDTH(width), HEIGHT(height) {
	position = new Cell**[WIDTH];
	for (int i = 0; i < WIDTH; i++) {
		position[i] = new Cell*[HEIGHT];
		for (int j = 0; j < HEIGHT; j++)
			position[i][j] = new Cell();
	}
}

World::~World() {
	for (int i = 0; i < WIDTH; i++)
		for (int j = 0; j < HEIGHT; j++)
			delete position[i][j];
}

bool World::inBounds(int x, int y) {
	return (x < WIDTH && x > -1 && y < HEIGHT && y > -1);
}