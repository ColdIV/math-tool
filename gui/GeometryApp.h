#ifndef _GEOMETRY_APP_H_
#define _GEOMETRY_APP_H_

#include "backend/GeometryParser.h"
#include "App.h"
#include "Graph.h"
#include "TextOutput.h"
#include "GeometryInput.h"

class GeometryApp : public App {
private:
	GeometryParser *parser;
public:
	GeometryApp(SDL_Window *window, SDL_Renderer *renderer);
	virtual ~GeometryApp();
};

#endif
