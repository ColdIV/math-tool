#include "FunctionPlotterInput.h"


FunctionPlotterInput::FunctionPlotterInput(
	SDL_Window *w, SDL_Renderer *r, int x1, int y1, int x2, int y2,
	std::string text, int fontSize, Graph *graph
) : LineInput(w, r, x1, y1, x2, y2, text, fontSize) {
	this->graph = graph;
}

App * FunctionPlotterInput::handleEvent(SDL_Event event) {
	App * nextApp = LineInput::handleEvent(event);
	if(nextApp != nullptr) {
		return nextApp;
	}

	if(event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_RETURN) {
		// TODO: pass text to math tool function plotter, it will return a
		// Figures object. Then, call Graph::setFigures to add this Figure to
		// the figures vector. Then, it can be drawn by Graph::draw()
		this->text = "";
	}

	return nextApp; // if it's nullptr, we want to stay in the FunctionPlotter?
}
