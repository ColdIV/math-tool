#include "MenuApp.h"
#include "GeometryApp.h"
#include "FunctionPlotterApp.h"
#include "CalculatorApp.h"
#include "MenuInput.h"


MenuInput::MenuInput(
	SDL_Window *w, SDL_Renderer *r, int x1, int y1,
	int x2, int y2, std::string text, int fontSize
) : LineInput(w, r, x1, y1, x2, y2, text, fontSize) {}

App * MenuInput::handleEvent(SDL_Event event) {
	App * nextApp = LineInput::handleEvent(event);

	if(event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_RETURN) {
		if(this->text == "1") {
			// new Geometry App
			nextApp = new GeometryApp{this->window, this->renderer};
		} else if(this->text == "2") {
			// new Functions App
			nextApp = new FunctionPlotterApp{this->window, this->renderer};
		} else if(this->text == "3") {
			// new Calculator App
			nextApp = new CalculatorApp{this->window, this->renderer};
		} else {
			// reset text
			this->text = "";
		}
	}

	return nextApp;
}
