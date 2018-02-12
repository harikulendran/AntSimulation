#include "World.h"

World::World(double width, double height) : WIDTH(width), HEIGHT(height) {
	world = new Cell**[WIDTH];
	for (int i = 0; i < WIDTH; i++) {
		world[i] = new Cell*[HEIGHT];
		for (int j = 0; j < HEIGHT; j++)
			world[i][j] = new Cell();
	}
}

World::~World() {
	for (int i = 0; i < WIDTH; i++)
		for (int j = 0; j < HEIGHT; j++)
			delete world[i][j];
}