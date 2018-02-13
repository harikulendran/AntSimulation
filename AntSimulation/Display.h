#pragma once

#include <allegro5\allegro.h>
#include <string>

class Display {
	public:
		ALLEGRO_DISPLAY *display = nullptr;
		double FRAME_RATE = 60.0;

	public:
		void run();
		Display(int i, bool low);
		std::string name = "";
		int percentage, richness;

	private:

};