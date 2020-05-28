#include "Graph.h"


Graph::Graph(
	SDL_Window *window, SDL_Renderer *renderer,
	int x1, int y1, int x2, int y2, std::string mode
) : Widget(window, renderer, x1, y1, x2, y2) {
	this->mode = mode;
	this->zoomFactor = 100;
	this->xZero= (x1 + x2) / 2;
	this->yZero = (y1 + y2) / 2;
	// TODO: it should be possible to access the following members through
	// the Widget superclass - why isn't it?
	this->xStart = x1;
	this->xEnd = x2;
	this->yStart = y1;
	this->yEnd = y2;
}

void Graph::draw() {
	Widget::draw();

	SDL_SetRenderDrawColor(this->renderer, 255, 100, 100, 255);
	// draw x axis
	SDL_RenderDrawLine(
		this->renderer, this->xStart, this->yZero, this->xEnd, this->yZero
	);
	// draw y axis
	SDL_RenderDrawLine(
		this->renderer, this->xZero, this->yStart, this->xZero, this->yEnd
	);
	SDL_SetRenderDrawColor(this->renderer, 255, 255, 255, 255);

	// iterate through all objects
	// TODO: the following for loop does not apply to circles, check here if
	// object is a circle and draw accordingly
	for(Object *obj : this->objects) {
		std::vector<Point> points = obj->getPoints();
		// iterate through the points (except the last one)
		for(int i = 0; i < points.size() - 1; i++) {
			Point p = points[i];
			Point nextP = points[i+1];
			// draw line between current point and next point (x and y values
			// have to be adjusted to the zero point of the coordinate system)
			double currentX = calculateX(p.x());
			double currentY = calculateY(p.y());
			double nextX = calculateX(nextP.x());
			double nextY = calculateY(nextP.y());
			SDL_RenderDrawLine(this->renderer, currentX, currentY, nextX, nextY);
		}
		// TODO: if the objects are not functions, we have to draw a line between
		// the last and the first point as well: if (mode == "objects")
	}

	SDL_SetRenderDrawColor(this->renderer, 0, 0, 0, 255);
}

void Graph::addObject(Object *obj) {
	debug("adding an object\n\n");
	this->objects.push_back(obj);
	int x = obj->getPoints()[0].x();
	int y = obj->getPoints()[0].y();
	debug(std::to_string(x));
	debug(std::to_string(y));
	debug("\n\n");
}

void Graph::setObjects(Object *obj) {
	std::vector<Object*> emptyVector;
	this->objects = emptyVector;
	this->objects.push_back(obj);
}

void Graph::setZoomFactor(bool increase) {
	if (increase && zoomFactor < 175) { // allow zooming 3 times
		this->zoomFactor += 25;
	} else if (!increase && zoomFactor > 25){
		this->zoomFactor -= 25;
	}
}

double Graph::calculateX(double x) {
	return this->xZero + x * this->zoomFactor;
}

double Graph::calculateY(double y) {
	return yZero - y * this->zoomFactor;
}
