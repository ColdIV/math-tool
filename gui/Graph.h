#ifndef _GRAPH_H_
#define _GRAPH_H_

#include "Widget.h"

class Graph : public Widget{
	//TODO: add a private Figures vector here. This will be used in the
	// Graph::draw function
public:
	Graph(
		SDL_Window *window, SDL_Renderer *renderer,
		int x1, int y1, int x2, int y2
	);

	virtual void draw();
	// TODO: addFigure and setFigures functions that add to or overwrite the
	// figures vector
};

#endif
