#include "GeometryApp.h"


GeometryApp::GeometryApp(SDL_Window *win, SDL_Renderer *ren) : App(win, ren) {
	// widget for coordinate system and objects
	Graph *graph = new Graph(win, ren, 30, 30, 600, 400, "objects");

	// widget for input prompt
	TextOutput *prompt = new TextOutput{
		win, ren, 0, 450, 600, 500, "Eingabe ('q' zum Beenden): ", 24
	};

	// widget for input
	this->parser = new GeometryParser{};
	GeometryInput *input = new GeometryInput{
		win, ren, 320, 450, 600, 500, "", 24, graph, this->parser
	};

	this->widgets.push_back(graph);
	this->widgets.push_back(prompt);
	this->widgets.push_back(input);
}


GeometryApp::~GeometryApp() {
	delete this->parser;
	// deletion of widgets happens in superclass destructor
}
