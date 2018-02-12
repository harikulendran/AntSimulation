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
	/*
	ALLEGRO_DISPLAY *display = NULL;
	*/
	if (!al_init()) {
		fprintf(stderr, "failed to initialize allegro\n");
		return 1;
	}
	/*
	display = al_create_display(640, 480);

	if (!display) {
		fprintf(stderr, "failed to create display\n");
		return 1;
	}

	al_clear_to_color(al_map_rgb(0, 0, 0));
	*/
	al_init_primitives_addon();
	al_init_image_addon();

	Display disp{};
	disp.run();


	//al_destroy_display(display);
	
    return 0;
}

