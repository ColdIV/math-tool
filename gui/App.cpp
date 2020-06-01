#include "App.h"

App::App(SDL_Window *w, SDL_Renderer *r) {
	this->window = w;
	this->renderer = r;
}

App::~App() {
	debug("calling app destructor");
	for(Widget *widget : widgets) {
		delete widget;
	}
}

App* App::mainloop() {
	SDL_Event event;
	while(true) {
		while(SDL_PollEvent(&event)) {
			if(event.type == SDL_QUIT) {
				return nullptr; // nullptr means we want to stay in the running app
			}

			for (Widget *widget : this->widgets) {
				App *new_app = widget->handleEvent(event);
				if (nullptr != new_app) {
					return new_app;
				}

			}
			this->blankScreen();
			for (Widget *widget : this->widgets) {
				widget->draw();
			}
			SDL_RenderPresent(this->renderer);
			SDL_Delay(this->delay);
		}
	}
}

void App::blankScreen() {
	SDL_RenderClear(this->renderer);
}
