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
	SDL_SetRenderDrawColor(this->renderer, 255, 255, 255, 255);

	int xZeroPoint = 50;
	int yZeroPoint = 370;

	// iterate through all objects
	for(Object *obj : this->objects) {
		std::vector<Point> points = obj->getPoints();
		// iterate through the points (except the last one)
		for(int i = 0; i < points.size() - 1; i++) {
			Point p = points[i];
			Point nextP = points[i+1];
			// draw line between current point and next point (x and y values
			// have to be adjusted to the zero point of the coordinate system)
			double currentX = xZeroPoint + p.x();
			double currentY = yZeroPoint - p.y();
			double nextX = xZeroPoint + nextP.x();
			double nextY = yZeroPoint - nextP.y();
			SDL_RenderDrawLine(this->renderer, currentX, currentY, nextX, nextY);
		}
		// TODO: if the objects are not functions, we have to draw a line between
		// the last and the first point as well!
	}

	SDL_SetRenderDrawColor(this->renderer, 0, 0, 0, 255);
}

void Graph::setObjects(Object *obj) {
	std::vector<Object*> emptyVector;
	this->objects = emptyVector;
	this->objects.push_back(obj);
}
