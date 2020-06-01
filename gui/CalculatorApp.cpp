#include "CalculatorApp.h"
#include "TextOutput.h"
#include "CalculatorInput.h"


CalculatorApp::CalculatorApp(SDL_Window *win, SDL_Renderer *ren) : App(win, ren) {
	// widget for memory
	TextOutput *memory = new TextOutput{
		win, ren, 30, 30, 600, 400, "", 18
	};

	// widget to display the errors
	TextOutput *errors = new TextOutput{
		win, ren, 0, 500, 600, 600, "", 24
	};

	// widget for input prompt
	TextOutput *prompt = new TextOutput{
		win, ren, 0, 450, 600, 500, "Eingabe ('q' zum Beenden): ", 24
	};

	// widget for input
	this->calculator = new Calculator{};
	CalculatorInput *input = new CalculatorInput{
		win, ren, 300, 450, 600, 500, "", 24, memory, errors, this->calculator
	};


	this->widgets.push_back(memory);
	this->widgets.push_back(errors);
	this->widgets.push_back(prompt);
	this->widgets.push_back(input);
}


CalculatorApp::~CalculatorApp() {
	delete this->calculator;
	// deletion of widgets happens in superclass destructor
}
