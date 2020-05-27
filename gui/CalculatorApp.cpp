#include "CalculatorApp.h"
#include "TextOutput.h"
#include "CalculatorInput.h"


CalculatorApp::CalculatorApp(SDL_Window *win, SDL_Renderer *ren) : App(win, ren) {
	// widget for memory
	TextOutput *memory = new TextOutput{
		win, ren, 30, 30, 600, 400, currentMemory(), 24
	};

	// widget for input prompt
	TextOutput *prompt = new TextOutput{
		win, ren, 0, 450, 600, 500, "Eingabe ('q' zum Beenden): ", 24
	};

	// widget for input
	CalculatorInput *input = new CalculatorInput{win, ren, 300, 450, 600, 500, "", 24, memory};

	widgets.push_back(memory);
	widgets.push_back(prompt);
	widgets.push_back(input);
}

// TODO: we don't need this here, CalculatorInput takes care of it
std::string CalculatorApp::currentMemory() {
	// TODO: call calculator and get memory
	// or if it's not the same instance every time, maybe have a separate memory
	// as member of Calculator App, that will be passed every time a new
	// Calculator App instance is made
	return "[m1] 15.2\n[m2] 122\n[m3] 99";
}
