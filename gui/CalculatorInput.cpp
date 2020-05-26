#include "CalculatorInput.h"


CalculatorInput::CalculatorInput(
	SDL_Window *w, SDL_Renderer *r, int x1, int y1, int x2, int y2,
	std::string text, int fontSize, TextOutput *output
) : LineInput(w, r, x1, y1, x2, y2, text, fontSize) {
	this->output = output;
}

App * CalculatorInput::handleEvent(SDL_Event event) {
	App * nextApp = LineInput::handleEvent(event);
	if(nextApp != nullptr) {
		return nextApp;
	}

	if(event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_RETURN) {
		// TODO: call math-tool calculate_single, then call math-tool get_current_memory(),
		// then assign the result of that to this->output
		this->output->setText("[m1] 15\n[m2] 27.2");
		this->text = "";
	}
	return nextApp; // if it's nullptr, we want to stay in the calculator
}


double CalculatorInput::calculate(std::string text) {
	// TODO: call the math-tool Calculator here
	return 14.2;
}
