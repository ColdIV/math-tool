#ifndef _FUNCTION_PLOTTER_INPUT_H_
#define _FUNCTION_PLOTTER_INPUT_H_

#include "backend/FunctionPlotter.h"
#include "Graph.h"
#include "LineInput.h"

class FunctionPlotterInput : public LineInput {
private:
	Graph *graph;
	FunctionPlotter *functionPlotter;
public:
	FunctionPlotterInput(
		SDL_Window *w, SDL_Renderer *r, int x1, int y1, int x2, int y2,
		std::string text, int fontSize, Graph *graph, FunctionPlotter *fP
	);

	virtual App * handleEvent(SDL_Event event);
};

#endif
