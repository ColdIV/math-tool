#ifndef _FUNCTION_PLOTTER_APP_H_
#define _FUNCTION_PLOTTER_APP_H_

#include "backend/FunctionPlotter.h"
#include "App.h"
#include "Graph.h"
#include "TextOutput.h"
#include "FunctionPlotterInput.h"

class FunctionPlotterApp : public App {
private:
	FunctionPlotter *functionPlotter;
public:
	FunctionPlotterApp(SDL_Window *window, SDL_Renderer *renderer);
	virtual ~FunctionPlotterApp();
};

#endif
