// AntSimulation.cpp : Defines the entry point for the console application.
//

#include "allegro5\allegro.h"
#include "allegro5\allegro_primitives.h"
#include "allegro5\allegro_image.h"
#include "stdafx.h"
#include "Display.h"
#include <iostream>


int main()
{
	if (!al_init()) {
		fprintf(stderr, "failed to initialize allegro\n");
		return 1;
	}
	al_init_primitives_addon();
	al_init_image_addon();

	//run 5 sims for each source type
	for (int i = 0; i < 5; i++) {
		Display disp{i,false};
		disp.animate();
		Display tisp{i,true};
		tisp.animate();
		std::cout << std::endl;
	}

    return 0;
}

