#pragma once

#include <allegro5\allegro.h>
#include <string>
#include <vector>
#include "World.h"
#include "Ant.h"

class Display {
	public:
		ALLEGRO_DISPLAY *display = nullptr;
		double FRAME_RATE = 60.0;
		std::string name = "";
		int percentage, richness;

	public:
		void run();
		void animate();
		Display(int i, bool low);

	private:
		void drawAgentsToImage(ALLEGRO_BITMAP* image, World* world, int count = -1);
		void drawPheromoneToImage(ALLEGRO_BITMAP* image, World* world, int count = -1);
};