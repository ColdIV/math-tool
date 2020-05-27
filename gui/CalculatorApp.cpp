#include "CalculatorApp.h"
#include "TextOutput.h"
#include "CalculatorInput.h"


CalculatorApp::CalculatorApp(SDL_Window *win, SDL_Renderer *ren) : App(win, ren) {
	// widget for memory
	TextOutput *memory = new TextOutput{
		win, ren, 30, 30, 600, 400, "", 18
	};

	// widget for input prompt
	TextOutput *prompt = new TextOutput{
		win, ren, 0, 450, 600, 500, "Eingabe ('q' zum Beenden): ", 24
	};

	// widget for input
	this->calculator = new Calculator{};
	CalculatorInput *input = new CalculatorInput{
		win, ren, 300, 450, 600, 500, "", 24, memory, this->calculator
	};


	widgets.push_back(memory);
	widgets.push_back(prompt);
	widgets.push_back(input);
}


CalculatorApp::~CalculatorApp() {
	delete this->calculator;
	// deletion of widgets happens in superclass destructor
}
