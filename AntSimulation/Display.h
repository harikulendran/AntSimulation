#pragma once

#include <allegro5\allegro.h>
#include <string>

class Display {
	public:
		ALLEGRO_DISPLAY *display = nullptr;
		double FRAME_RATE = 60.0;
		std::string name = "";
		int percentage, richness;

	public:
		void run();
		Display(int i, bool low);
};