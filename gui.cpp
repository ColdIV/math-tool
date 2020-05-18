#include "gui.h"

using namespace std;

GUI::GUI() {
	this->mode = Modes::MENU;
	this->screen_width = 800;
	this->screen_height = 600;
}

GUI::GUI(int w, int h) {
	this->mode = Modes::MENU;
	this->screen_width = w;
	this->screen_height = h;
}

void GUI::start() {
	setup();
	
	SDL_CreateWindowAndRenderer(
		this->screen_width, this->screen_height, 0, &(this->window), &(this->renderer)
	);
	
	check_window();
	
	reset_screen(this->renderer);
	
	menu_loop();
	
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}


void GUI::setup() {
	if (SDL_Init(SDL_INIT_VIDEO) == -1){
		cerr << "Error while initializing SDL" << endl;
		exit(1);
	};
	
	if (TTF_Init() == -1){
		cerr << "Error while initializing TTF" << endl;
		exit(1);
	};
}

void GUI::check_window() {
	if (this->window == nullptr) 
	{
		cerr << "Error while initializing screen: " << SDL_GetError() << endl;
		SDL_Quit();
		exit(1);
	}
}

void GUI::menu_loop(){
	string text = "";
	SDL_Color color = {150, 200, 255, 255};
	SDL_Event event;
	bool choice = false;

	while(!choice){
		SDL_StartTextInput();
		while(SDL_PollEvent(&event)) {
			if (event.type == SDL_QUIT) {
				SDL_StopTextInput();
				return;
			} else if(event.type == SDL_TEXTINPUT || event.type == SDL_KEYDOWN) {
				if(event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_RETURN) {
					if(text == "1") {
						this->mode = Modes::CALCULATOR;
						choice = true;
					} else if(text == "2") {
						this->mode = Modes::GEOMETRY;
						choice = true;
					} else if(text == "3") {
						this->mode = Modes::FUNCTIONS;
						choice = true;
					} else {
						reset_screen(this->renderer);
						text = "";
					}
				} else if(event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_BACKSPACE && text.length() > 0) {
					text = text.substr(0, text.length() - 1);
					reset_screen(renderer);
					render_text(renderer, text, 24, 100, 450, color);
				} else if(event.type == SDL_TEXTINPUT) {
					text += event.text.text;
					reset_screen(renderer);
					render_text(renderer, text, 24, 100, 450, color);
				}
			}
		}
		SDL_StopTextInput();
		SDL_Delay(30);
	}
	
	// a choice has been made
	reset_screen(this->renderer);
	if(this->mode == Modes::CALCULATOR) {
		calculator_loop();
	}
}

void GUI::calculator_loop(){
	string text = "";
	SDL_Color color = {150, 200, 255, 255};
	SDL_Event event;

	while(true){
		SDL_StartTextInput();
		while(SDL_PollEvent(&event)) {
			if (event.type == SDL_QUIT) {
				SDL_StopTextInput();
				return;
			} else if(event.type == SDL_TEXTINPUT || event.type == SDL_KEYDOWN) {
				if(event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_RETURN) {
					reset_screen(this->renderer);
					cout << "returning text " << text << endl;
					text = "";
				} else if(event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_BACKSPACE && text.length() > 0) {
					text = text.substr(0, text.length() - 1);
					reset_screen(renderer);
					render_text(renderer, text, 24, 100, 450, color);
				} else if(event.type == SDL_TEXTINPUT) {
					text += event.text.text;
					reset_screen(renderer);
					render_text(renderer, text, 24, 100, 450, color);
				}
			}
		}
		SDL_StopTextInput();
		SDL_Delay(30);
	}
}



void GUI::reset_screen(SDL_Renderer *renderer) {
	SDL_Color color = {255, 255, 255, 255};
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderClear(renderer);
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	SDL_RenderDrawLine(renderer, 0, 450, 800, 450);
	render_text(renderer, "Eingabe: ", 24, 0, 450, color);
	if(this->mode == Modes::MENU) {
		render_text(renderer, "Hauptmenue:\n1) Geometrie\n2) Funktionsplotter\n3) Taschenrechner", 50, 25, 0, color);
	}
	if(this->mode == Modes::CALCULATOR) {
		draw_memory();
	}
	
	SDL_RenderPresent(renderer);
}


void GUI::render_text(SDL_Renderer *renderer, string complete_text, int font_size, int x_pos, int y_pos, SDL_Color color) {
	// set font and color
	TTF_Font *font = TTF_OpenFont("arial.ttf", font_size);
	//SDL_Color color = {150, 200, 255, 255};
	
	// helper variables
	int textW = 0;
	int textH = 0;
	
	// starting point of message rectangle
	int startX = x_pos;
	int startY = y_pos;
	
	// text has to be converted to istream in order to call getline
	stringstream ss(complete_text);
	string text_to_render;
	
	// break at newline and render single line
	while(getline(ss, text_to_render, '\n')) {
		startY += 70;
		SDL_Surface *textSurface = TTF_RenderText_Solid(font, text_to_render.c_str(), color);
		SDL_Texture *text = SDL_CreateTextureFromSurface(renderer, textSurface);
		// depending on font size used, determine width and height automatically
		SDL_QueryTexture(text, NULL, NULL, &textW, &textH);
		SDL_Rect messageRect = {startX, startY, textW, textH};
		SDL_RenderCopy(renderer, text, NULL, &messageRect);
		SDL_FreeSurface(textSurface);
		SDL_DestroyTexture(text);
	}
	
	// present result
	SDL_RenderPresent(renderer);
	
	TTF_CloseFont(font);
}

void GUI::draw_memory() {
	SDL_Color color = {255, 255, 255, 255};
	render_text(this->renderer, "[m1] 15.2\n[m2] 157", 30, 20, 20, color);
}

void GUI::draw_coord_sys_and_lines(SDL_Renderer *renderer) {
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	SDL_RenderDrawLine(renderer, 50, 50, 50, 550);
	SDL_RenderDrawLine(renderer, 10, 400, 750, 400);
	SDL_SetRenderDrawColor(renderer, 200, 50, 200, 255);
	SDL_RenderDrawLine(renderer, 100, 100, 200, 100);
	SDL_RenderDrawLine(renderer, 100, 100, 150, 200);
	SDL_RenderDrawLine(renderer, 150, 200, 200, 100);
	SDL_RenderPresent(renderer);
}
