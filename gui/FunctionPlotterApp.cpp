#include "FunctionPlotterApp.h"

FunctionPlotterApp::FunctionPlotterApp(
	SDL_Window *window, SDL_Renderer *renderer
) : App(window, renderer) {
	// widget for the graph
	Graph *graph = new Graph{window, renderer, 30, 30, 600, 400};

	// widget for input prompt
	TextOutput *prompt = new TextOutput{
		window, renderer, 0, 450, 600, 500, "Eingabe ('q' zum Beenden): ", 24
	};

	// widget for input
	this->functionPlotter = new FunctionPlotter{};
	FunctionPlotterInput *input = new FunctionPlotterInput{
		window, renderer, 320, 450, 600, 500, "", 24, graph
	};

	widgets.push_back(graph);
	widgets.push_back(prompt);
	widgets.push_back(input);
}


FunctionPlotterApp::~FunctionPlotterApp() {
	delete this->functionPlotter;
	// deletion of widgets happens in superclass destructor
}
