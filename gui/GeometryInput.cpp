#include "GeometryInput.h"


GeometryInput::GeometryInput(
	SDL_Window *w, SDL_Renderer *r, int x1, int y1, int x2, int y2,
	std::string text, int fontSize, Graph *graph
) : LineInput(w, r, x1, y1, x2, y2, text, fontSize) {
	this->graph = graph;
}

App * GeometryInput::handleEvent(SDL_Event event) {
	App * nextApp = LineInput::handleEvent(event);
	if(nextApp != nullptr) {
		return nextApp;
	}

	if(event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_RETURN) {
		// TODO: pass text to math tool geometry to create an object or
		// call the object functions
		// Also, once the Graph Widget has an addFigure function, call it with
		// the created object.
		this->text = "";
	}

	return nextApp;
}
