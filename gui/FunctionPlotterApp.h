#ifndef _FUNCTION_PLOTTER_APP_H_
#define _FUNCTION_PLOTTER_APP_H_

#include "App.h"
#include "Graph.h"
#include "TextOutput.h"
#include "FunctionPlotterInput.h"

class FunctionPlotterApp : public App {
public:
	FunctionPlotterApp(SDL_Window *window, SDL_Renderer *renderer);
};

#endif
