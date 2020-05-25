#include <SDL.h>
#include <SDL_ttf.h>

#include "App.h"
#include "MenuApp.h"
#include "debug.h"

int main() {
	// setup
	SDL_Window *window;
	SDL_Renderer *renderer;

	if (SDL_Init(SDL_INIT_VIDEO) == -1){
		debug("Error while initializing SDL");
		exit(1);
	};
	if (TTF_Init() == -1){
		debug("Error while initializing TTF");
		SDL_Quit();
		exit(1);
	};
	SDL_CreateWindowAndRenderer(800, 600, 0, &window, &renderer);
	if (window == nullptr)
	{
		debug("Error while initializing screen");
		TTF_Quit();
		SDL_Quit();
		exit(1);
	}

	SDL_StartTextInput();

	// start app
	App *app = new MenuApp{window, renderer};
	while(true) {
		App *newApp = app->mainloop();
		delete app;
		if(nullptr != newApp) {
			app = newApp;
		} else {
			break;
		}
	};

	// cleanup

	SDL_StopTextInput();

	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	TTF_Quit();
	SDL_Quit();
	debug("We're at the end!");

	return 0;
}
