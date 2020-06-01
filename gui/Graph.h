#ifndef _GRAPH_H_
#define _GRAPH_H_

#include <vector>
#include <typeinfo>
#include "backend/Object.h"
#include "backend/Point.h"
#include "backend/Circle.h"
#include "Widget.h"
#include "debug.h"

class Graph : public Widget{
private:
	std::vector<Object*> objects;
	std::vector<Point> intersections;
	int xZero;
	int yZero;
	double defaultZoomLevel;
	double currentZoomLevel;
	std::string mode;
public:
	Graph(
		SDL_Window *window, SDL_Renderer *renderer,
		int x1, int y1, int x2, int y2, std::string mode
	);

	virtual void draw();

	void drawCoordinateSystem();
	void drawFunction();
	void drawPolygon(Object *obj);
	void drawCircle(Circle *circle, bool filled);
	void connectPoints(Object *obj);

	void addIntersection(Point p);
	void addObject(Object *obj);
	void setObjects(Object *obj);
	void changeZoomLevel(bool increase);
	double calculateX(double x);
	double calculateY(double y);
};

#endif

// this->graph->setObjects(this->functionPlotter->getFunction());
