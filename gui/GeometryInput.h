#ifndef _GEOMETRY_INPUT_H_
#define _GEOMETRY_INPUT_H_

#include <unordered_map>
#include "backend/Object.h"
#include "backend/GeometryParser.h"
#include "Graph.h"
#include "TextOutput.h"
#include "LineInput.h"


class GeometryInput : public LineInput {
private:
	Graph *graph;
	GeometryParser *parser;
	TextOutput *createdObjects;
public:
	GeometryInput(
		SDL_Window *w, SDL_Renderer *r, int x1, int y1, int x2, int y2,
		std::string text, int fontSize, Graph *graph, GeometryParser *parser,
		TextOutput *createdObjects
	);

	virtual App * handleEvent(SDL_Event event);
};

#endif
