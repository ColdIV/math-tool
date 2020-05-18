#ifndef _GUI_H_
#define _GUI_H_

#include <SDL.h>
#include <SDL_ttf.h>
#include <iostream>
#include <cstdlib>
#include <sstream>

using namespace std;

enum class Modes{MENU, CALCULATOR, GEOMETRY, FUNCTIONS};

class GUI {
private:
	Modes mode;
	int screen_width;
	int screen_height;
	SDL_Window *window;
	SDL_Renderer *renderer;
public:
	GUI();
	GUI(int w, int h);
	
	void start();
	void setup();
	void check_window();
	void menu_loop();
	void calculator_loop();
	void reset_screen(SDL_Renderer *renderer);
	void render_text(SDL_Renderer *renderer, string complete_text, int font_size, int x_pos, int y_pos, SDL_Color color);
	void draw_coord_sys_and_lines(SDL_Renderer *renderer);
	void draw_memory();
};

#endif
