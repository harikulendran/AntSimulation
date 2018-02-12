#include "Display.h"

Display::Display() {}

void Display::run() {

	while (true) {
		al_rest(1.0 / FRAME_RATE);

		//

		al_flip_display();
		al_clear_to_color(al_map_rgb(0, 0, 0));
	}
}