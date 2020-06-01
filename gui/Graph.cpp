#include "Graph.h"


Graph::Graph(
	SDL_Window *window, SDL_Renderer *renderer,
	int x1, int y1, int x2, int y2, std::string mode
) : Widget(window, renderer, x1, y1, x2, y2) {
	this->mode = mode;
	this->defaultZoomLevel = 10;
	this->currentZoomLevel = 5;
	this->xZero= (x1 + x2) / 2;
	this->yZero = (y1 + y2) / 2;
}

void Graph::draw() {
	Widget::draw();

	drawCoordinateSystem();

	if (this->mode == "functions") {
		drawFunction();
	} else { // mode must be "objects"
		// draw the created objects:
		for(Object *obj : this->objects) {
			if(typeid(*obj) == typeid(Circle)) {
				Circle *c = dynamic_cast<Circle *>(obj);
				SDL_SetRenderDrawColor(this->renderer, 255, 255, 255, 255);
				drawCircle(c, false);
			} else { // must be a polygon
				drawPolygon(obj);
			}
		}
		// draw the intersections:
		for(Point p : this->intersections) {
			Circle tempC (p, 1);
			SDL_SetRenderDrawColor(this->renderer, 153, 255, 51, 255);
			drawCircle(&tempC, true);
		}
	}


	SDL_SetRenderDrawColor(this->renderer, 0, 0, 0, 255);
}

void Graph::drawCoordinateSystem() {
	SDL_SetRenderDrawColor(this->renderer, 255, 100, 100, 255);
	// draw x axis
	SDL_RenderDrawLine(
		this->renderer, this->xStart, this->yZero, this->xEnd, this->yZero
	);
	// draw y axis
	SDL_RenderDrawLine(
		this->renderer, this->xZero, this->yStart, this->xZero, this->yEnd
	);
}

void Graph::drawFunction() {
	SDL_SetRenderDrawColor(this->renderer, 255, 255, 255, 255);

	// iterate through all objects
	for(Object *obj : this->objects) {
		connectPoints(obj);
	}
}

void Graph::drawPolygon(Object *obj) {
	SDL_SetRenderDrawColor(this->renderer, 255, 255, 255, 255);

	connectPoints(obj);

	// connect the first and last point
	std::vector<Point> points = obj->getPoints();
	double firstX = points[0].x();
	double firstY = points[0].y();
	double lastX = points[points.size() - 1].x();
	double lastY = points[points.size() - 1].y();
	SDL_RenderDrawLine(this->renderer, calculateX(firstX), calculateY(firstY),
		calculateX(lastX), calculateY(lastY)
	);
}

void Graph::drawCircle(Circle *circle, bool filled) {
	double radius = circle->getRadius() * this->currentZoomLevel;
	double centerX = calculateX(circle->getPoint().x());
	double centerY = calculateY(circle->getPoint().y());
	double diameter = radius * 2;
	double x = radius- 1;
	double y = 0;
	double tx = 1;
	double ty = 1;
	double error = tx - diameter;

	while(x >= y) {
		// draw an octant of the circle each time
		SDL_RenderDrawPoint(this->renderer, centerX + x, centerY - y);
		SDL_RenderDrawPoint(this->renderer, centerX + x, centerY + y);
		SDL_RenderDrawPoint(this->renderer, centerX - x, centerY - y);
		SDL_RenderDrawPoint(this->renderer, centerX - x, centerY + y);
		SDL_RenderDrawPoint(this->renderer, centerX + y, centerY - x);
		SDL_RenderDrawPoint(this->renderer, centerX + y, centerY + x);
		SDL_RenderDrawPoint(this->renderer, centerX - y, centerY - x);
		SDL_RenderDrawPoint(this->renderer, centerX - y, centerY + x);
		if (filled) {
			SDL_RenderDrawLine(
				this->renderer, centerX, centerY, centerX + x, centerY - y);
			SDL_RenderDrawLine(
				this->renderer, centerX, centerY, centerX + x, centerY + y);
			SDL_RenderDrawLine(
				this->renderer, centerX, centerY, centerX - x, centerY - y);
			SDL_RenderDrawLine(
				this->renderer, centerX, centerY, centerX - x, centerY + y);
			SDL_RenderDrawLine(
				this->renderer, centerX, centerY, centerX + y, centerY - x);
			SDL_RenderDrawLine(
				this->renderer, centerX, centerY, centerX + y, centerY + x);
			SDL_RenderDrawLine(
				this->renderer, centerX, centerY, centerX - y, centerY - x);
			SDL_RenderDrawLine(
				this->renderer, centerX, centerY, centerX - y, centerY + x);
		}

		if (error <= 0) {
			++y;
			error += ty;
			ty += 2;
		}

		if (error > 0) {
			--x;
			tx += 2;
			error += (tx - diameter);
		}
	}
}

void Graph::connectPoints(Object *obj) {
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

		// don't draw yet if point is not in range
		if (currentX < this->xStart || currentY < this->yStart ||
				nextY < this->yStart || currentY > this->yEnd || nextY > this->yEnd
		) {
			continue;
		}
		// stop drawing when next point would not be in range
		if (nextX > this->xEnd){
			break;
		}
		SDL_RenderDrawLine(this->renderer, currentX, currentY, nextX, nextY);
	}
}

void Graph::addIntersection(Point p) {
	this->intersections.push_back(p);
}

void Graph::addObject(Object *obj) {
	this->objects.push_back(obj);
}

void Graph::setObjects(Object *obj) {
	std::vector<Object*> emptyVector;
	this->objects = emptyVector;
	this->objects.push_back(obj);
}

void Graph::changeZoomLevel(bool increase) {
	if (increase && this->currentZoomLevel < (this->defaultZoomLevel * 3)) {
		this->currentZoomLevel += 5;
	} else if (!increase && this->currentZoomLevel > (this->defaultZoomLevel / 2)){
		this->currentZoomLevel -= 5;
	}
}

double Graph::calculateX(double x) {
	return this->xZero + x * this->currentZoomLevel;
}

double Graph::calculateY(double y) {
	return yZero - y * this->currentZoomLevel;
}
