#include "Display.h"
#include "Nest.h"
#include <iostream>

Display::Display(int i, bool low) {
	name = (low) ? "./output/LSHF0" : "./output/HSLF0";
	name += std::to_string(i);
	percentage = (low) ? 50 : 1;
	richness = (low) ? 1 : 400;
}

void Display::run() {
	int timeStep = 0;
	int antCount = 0;

	World world{ 640,480,percentage,richness };
	world.position[0][0] = new Nest{};
	std::vector<Ant*> ants;

	//init image
	ALLEGRO_BITMAP* image = NULL;
	image = al_create_bitmap(640, 480);
	al_set_target_bitmap(image);
	al_clear_to_color(al_map_rgb(0, 0, 0));
	
	std::cout << "Simulating..." << std::endl;

	while (timeStep < 2000) {
		//generate new ants
		if (!world.position[0][0]->isFull() && antCount < 10000000)
			for (int i = 0; i < 10; i++) {
				ants.push_back(new Ant{ &world,0,0 });
				world.position[0][0]->popSize++;
				antCount++;
			}

		//calculate all ant moves
		for (Ant* a : ants) {
			a->move();
			a->checkFood();
		}
		
		//evaporate on all cells
		for (int i = 0; i < 640; i++)
			for (int j = 0; j < 480; j++)
				if (world.position[i][j]->pLevel > 0)
					world.position[i][j]->evaporate();

		timeStep++;
	}

	std::cout << "Simulation Complete!" << std::endl << "Nest Food: " << world.nestFood << std::endl << "Drawing..." << std::endl;

	drawPheromoneToImage(image, &world);

	drawAgentsToImage(image, &world);

	std::cout << "Saving Complete!" << std::endl;
}

void Display::animate() {
	int timeStep = 0;
	int antCount = 0;

	World world{ 640,480,percentage,richness };
	world.position[0][0] = new Nest{};
	std::vector<Ant*> ants;

	//init image
	ALLEGRO_BITMAP* image = NULL;
	image = al_create_bitmap(640, 480);
	al_set_target_bitmap(image);
	
	std::cout << "Simulating..." << std::endl;

	while (timeStep < 2000) {
		//generate new ants
		if (!world.position[0][0]->isFull() && antCount < 10000000)
			for (int i = 0; i < 10; i++) {
				ants.push_back(new Ant{ &world,0,0 });
				world.position[0][0]->popSize++;
				antCount++;
			}

		//calculate all ant moves
		for (Ant* a : ants) {
			a->move();
			a->checkFood();
		}
		
		//evaporate on all cells
		for (int i = 0; i < 640; i++)
			for (int j = 0; j < 480; j++)
				if (world.position[i][j]->pLevel > 0)
					world.position[i][j]->evaporate();

		drawAgentsToImage(image, &world, timeStep);
		drawPheromoneToImage(image, &world, timeStep);

		timeStep++;
	}

	std::cout << "Simulation Complete!" << std::endl << "Nest Food: " << world.nestFood << std::endl << "Drawing..." << std::endl;
}

void Display::drawPheromoneToImage(ALLEGRO_BITMAP* image, World* world, int count) {
	al_clear_to_color(al_map_rgb(0, 0, 0));
	//find max pheromone level for setting max colour
	double maxP = 0;
	for (int i = 0; i < 640; i++)
		for (int j = 0; j < 480; j++)
			if (world->position[i][j]->pLevel > 0)
				maxP = (maxP < world->position[i][j]->pLevel) ? world->position[i][j]->pLevel : maxP;

	//draw to image
	for (int i = 0; i < 640; i++) {
		for (int j = 0; j < 480; j++) {
			if (world->position[i][j]->pLevel > 0) {
				double c = world->position[i][j]->pLevel / maxP * 255.0;
				c = (c > 255.0) ? 255.0 : c;
				al_put_pixel(i, j, al_map_rgb(c,0,0));
			}
		}
	}

	std::string cnt = (count == -1) ? "" : std::to_string(count);

	std::cout << "Drawing " + cnt + " Complete!" << std::endl << "Saving to disk..." << std::endl;

	std::cout << al_save_bitmap((name+"P"+cnt+".png").c_str(), image) << std::endl;
}

void Display::drawAgentsToImage(ALLEGRO_BITMAP* image, World* world, int count) {
	al_clear_to_color(al_map_rgb(0, 0, 0));
	for (int i = 0; i < 640; i++) {
		for (int j = 0; j < 480; j++) {
			if (world->position[i][j]->popSize > 0) {
				int c = (int)((double)world->position[i][j]->popSize / 6.0 * 255.0);
				c = (c > 255) ? 255 : c;
				al_put_pixel(i, j, al_map_rgb(c,c,c));
			}
		}
	}
	std::string cnt = (count == -1) ? "" : std::to_string(count);
	std::cout << al_save_bitmap((name+"A"+cnt+".png").c_str(), image) << std::endl;
}