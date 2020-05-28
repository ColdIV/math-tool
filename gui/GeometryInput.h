#ifndef _GEOMETRY_INPUT_H_
#define _GEOMETRY_INPUT_H_


#include "backend/Object.h"
#include "Graph.h"
#include "LineInput.h"


class GeometryInput : public LineInput {
private:
	Graph *graph;
public:
	GeometryInput(
		SDL_Window *w, SDL_Renderer *r, int x1, int y1, int x2, int y2,
		std::string text, int fontSize, Graph *graph
	);

	virtual App * handleEvent(SDL_Event event);
};

#endif
