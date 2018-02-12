#include "Display.h"
#include "World.h"
#include "Ant.h"
#include "Nest.h"
#include <vector>
#include <iostream>

Display::Display() {}

void Display::run() {
	int count = 0;
	int antCount = 0;
	World world{ 640,480 };
	world.position[0][0] = new Nest{};
	std::vector<Ant*> ants;

	ALLEGRO_BITMAP* image = NULL;
	image = al_create_bitmap(640, 480);
	al_set_target_bitmap(image);
	al_clear_to_color(al_map_rgb(0, 0, 0));
	
	int a = 0;

	std::cout << "Simulating..." << std::endl;

	while (count < 4000) {
		if (!world.position[0][0]->isFull() && antCount < 500000)
			for (int i = 0; i < 20; i++) {
				ants.push_back(new Ant{ &world,0,0 });
				world.position[0][0]->popSize++;
				antCount++;
			}
		for (Ant* a : ants) {
			a->move();
			a->checkFood();
		}
		int max = 640 * 480;
		count++;
	}

	std::cout << "Simulation Complete!" << std::endl << "Drawing..." << std::endl;

	for (int i = 0; i < 640; i++) {
		for (int j = 0; j < 480; j++) {
			if (world.position[i][j]->pLevel > 10) {
				double c = world.position[i][j]->pLevel / 1000.0 * 255.0;
				al_put_pixel(i, j, al_map_rgb(c,c,c));
			}
		}
	}

	std::cout << "Drawing Complete!" << std::endl << "Saving to disk..." << std::endl;

	std::cout << al_save_bitmap("LSHF.png", image) << std::endl;

	std::cout << "Saving Complete!" << std::endl;
}