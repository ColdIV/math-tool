#include "CalculatorInput.h"


CalculatorInput::CalculatorInput(
	SDL_Window *w, SDL_Renderer *r, int x1, int y1, int x2, int y2,
	std::string text, int fontSize, TextOutput *output, Calculator *calculator
) : LineInput(w, r, x1, y1, x2, y2, text, fontSize) {
	this->output = output;
	this->calculator = calculator;
}

App * CalculatorInput::handleEvent(SDL_Event event) {
	App * nextApp = LineInput::handleEvent(event);
	if(nextApp != nullptr) {
		return nextApp;
	}

	if(event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_RETURN) {
		this->calculator->calculate(this->text);
		this->output->setText(this->calculator->getMemory());
		this->text = "";
	}
	return nextApp; // if it's nullptr, we want to stay in the calculator
}
