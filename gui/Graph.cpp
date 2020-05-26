#include "Graph.h"

/*
TODO: the graph class should have a list/vector of all objects to draw and
2 functions to manage the objects: setObjects (deletes all other objects and
adds 1) and addObject(adds another object to the list)
in handleEvent, call either addObject or setObject, depending on whether
we are in the geometry or functionplotter app.
*/

Graph::Graph(
	SDL_Window *window, SDL_Renderer *renderer,
	int x1, int y1, int x2, int y2
) : Widget(window, renderer, x1, y1, x2, y2) {}

void Graph::draw() {
	Widget::draw();

	SDL_SetRenderDrawColor(this->renderer, 255, 100, 100, 255);
	SDL_RenderDrawLine(this->renderer, 50, 20, 50, 420);
	SDL_RenderDrawLine(this->renderer, 20, 370, 500, 370);
	SDL_SetRenderDrawColor(this->renderer, 0, 0, 0, 255);

	// TODO: go through the figures vector and draw each one
}
