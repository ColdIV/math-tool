#include "GeometryApp.h"
#include "Graph.h"
#include "TextOutput.h"
#include "GeometryInput.h"


GeometryApp::GeometryApp(SDL_Window *win, SDL_Renderer *ren) : App(win, ren) {
	// widget for coordinate system and objects
	Graph *graph = new Graph(win, ren, 30, 30, 600, 400);

	// widget for input prompt
	TextOutput *prompt = new TextOutput{
		win, ren, 0, 450, 600, 500, "Eingabe ('q' zum Beenden): ", 24
	};

	// TODO: widget for input: new GeometryInput()
	// widget for input
	GeometryInput *input = new GeometryInput{
		win, ren, 320, 450, 600, 500, "", 24, graph
	};

	widgets.push_back(graph);
	widgets.push_back(prompt);
	widgets.push_back(input);
}
