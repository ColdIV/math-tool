#ifndef _GRAPH_H_
#define _GRAPH_H_

#include <vector>
#include "backend/Object.h"
#include "backend/Point.h"
#include "Widget.h"
#include "debug.h"

class Graph : public Widget{
private:
	std::vector<Object*> objects;
	int xZero;
	int yZero;
	int xStart;
	int xEnd;
	int yStart;
	int yEnd;
	double zoomFactor;
public:
	Graph(
		SDL_Window *window, SDL_Renderer *renderer,
		int x1, int y1, int x2, int y2
	);

	virtual void draw();
	// TODO: addObject(Object *obj) for the Geometry Objects
	void setObjects(Object *obj);
	void setZoomFactor(bool increase);
	double calculateX(double x);
	double calculateY(double y);
};

#endif

// this->graph->setObjects(this->functionPlotter->getFunction());
