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
public:
	Graph(
		SDL_Window *window, SDL_Renderer *renderer,
		int x1, int y1, int x2, int y2
	);

	virtual void draw();
	// TODO: addObject(Object *obj) for the Geometry Objects
	void setObjects(Object *obj);
};

#endif

// this->graph->setObjects(this->functionPlotter->getFunction());
