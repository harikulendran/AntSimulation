#pragma once

#include <allegro5\allegro.h>

class Display {
	public:
		ALLEGRO_DISPLAY *display = nullptr;
		double FRAME_RATE = 60.0;

	public:
		void run();
		Display();

	private:

};