#include "Display.h"
#include "World.h"
#include "Ant.h"
#include "Nest.h"
#include <vector>
#include <iostream>

Display::Display(int i, bool low) {
	name = (low) ? "./output/LSHF0" : "./output/HSLF0";
	name += std::to_string(i);
	percentage = (low) ? 50 : 1;
	richness = (low) ? 1 : 400;
}

void Display::run() {
	int count = 0;
	int antCount = 0;
	World world{ 640,480,percentage,richness };
	world.position[0][0] = new Nest{};
	std::vector<Ant*> ants;

	ALLEGRO_BITMAP* image = NULL;
	image = al_create_bitmap(640, 480);
	al_set_target_bitmap(image);
	al_clear_to_color(al_map_rgb(0, 0, 0));
	
	int a = 0;

	std::cout << "Simulating..." << std::endl;

	while (count < 2000) {
		if (!world.position[0][0]->isFull() && antCount < 10000000)
			for (int i = 0; i < 10; i++) {
				ants.push_back(new Ant{ &world,0,0 });
				world.position[0][0]->popSize++;
				antCount++;
			}
		for (Ant* a : ants) {
			a->move();
			a->checkFood();
		}
		int max = 640 * 480;

		
		for (int i = 0; i < 640; i++)
			for (int j = 0; j < 480; j++)
				if (world.position[i][j]->pLevel > 0)
					world.position[i][j]->evaporate();

		count++;
	}

	std::cout << "Simulation Complete!" << std::endl << "Nest Food: " << world.nestFood << std::endl << "Drawing..." << std::endl;

	double maxP = 0;
	for (int i = 0; i < 640; i++)
		for (int j = 0; j < 480; j++)
			if (world.position[i][j]->pLevel > 0)
				maxP = (maxP < world.position[i][j]->pLevel) ? world.position[i][j]->pLevel : maxP;

	for (int i = 0; i < 640; i++) {
		for (int j = 0; j < 480; j++) {
			if (world.position[i][j]->pLevel > 0) {
				double c = world.position[i][j]->pLevel / maxP * 255.0;
				c = (c > 255.0) ? 255.0 : c;
				al_put_pixel(i, j, al_map_rgb(c,0,0));
			}
		}
	}


	std::cout << "Drawing Complete!" << std::endl << "Saving to disk..." << std::endl;

	std::cout << al_save_bitmap((name+"P.png").c_str(), image) << std::endl;

	al_clear_to_color(al_map_rgb(0, 0, 0));
	for (Ant* a : ants)
		al_put_pixel(a->cPos.x, a->cPos.y, al_map_rgb(255, 255, 255));
	std::cout << al_save_bitmap((name+"A.png").c_str(), image) << std::endl;

	std::cout << "Saving Complete!" << std::endl;
}