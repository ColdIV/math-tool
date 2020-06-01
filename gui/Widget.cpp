#include "Widget.h"
#include "debug.h"

Widget::Widget(
	SDL_Window *w, SDL_Renderer *r, int x1, int y1, int x2, int y2
) {
	this->window = w;
	this->renderer = r;
	this->xStart = x1;
	this->yStart = y1;
	this->xEnd = x2;
	this->yEnd = y2;
}

Widget::~Widget() {
	// TODO: in Graph, we need to delete the Figures vector elements
	debug("calling widget destructor");
}

App* Widget::handleEvent(SDL_Event event) {
	debug("handling event");
	return nullptr; // nullptr means we want to stay in the same app
}

void Widget::draw() {
	debug("drawing in superclass");
	if (DEBUG) { // draw border around widget
		SDL_SetRenderDrawColor(this->renderer, 255, 255, 255, 255);

		SDL_RenderDrawLine(
			this->renderer, this->xStart, this->yStart, this->xEnd, this->yStart
		);
		SDL_RenderDrawLine(
			this->renderer, this->xStart, this->yStart, this->xStart, this->yEnd
		);
		SDL_RenderDrawLine(
			this->renderer, this->xEnd, this->yStart, this->xEnd, this->yEnd
		);
		SDL_RenderDrawLine(
			this->renderer, this->xStart, this->yEnd, this->xEnd, this->yEnd
		);
	}

	SDL_SetRenderDrawColor(this->renderer, 0, 0, 0, 255);
}
