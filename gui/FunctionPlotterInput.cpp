#include "FunctionPlotterInput.h"


FunctionPlotterInput::FunctionPlotterInput(
	SDL_Window *w, SDL_Renderer *r, int x1, int y1, int x2, int y2,
	std::string text, int fontSize, Graph *graph, FunctionPlotter *fP
) : LineInput(w, r, x1, y1, x2, y2, text, fontSize) {
	this->graph = graph;
	this->functionPlotter = fP;
}

App * FunctionPlotterInput::handleEvent(SDL_Event event) {
	App * nextApp = LineInput::handleEvent(event);
	if(nextApp != nullptr) {
		return nextApp;
	}

	if(event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_RETURN) {
		if (this->text == "+") {
			this->graph->changeZoomLevel(true);
		} else if (this->text == "-") {
			this->graph->changeZoomLevel(false);
		} else {
			this->functionPlotter->makeFunction(this->text);
			this->graph->setObjects(this->functionPlotter->getFunction());
		}
		this->text = "";
	}
	return nextApp; // if it's nullptr, we want to stay in the FunctionPlotter
}
