#ifndef _WIDGET_H_
#define _WIDGET_H_

#include <SDL.h>
#include <SDL_ttf.h>
#include "debug.h"

class App;

class Widget {
protected:
	SDL_Window *window;
	SDL_Renderer *renderer;
	int xStart;
	int yStart;
	int xEnd;
	int yEnd;
public:
	Widget(SDL_Window *w, SDL_Renderer *r, int x1, int y1, int x2, int y2);
	virtual ~Widget();

	virtual App * handleEvent(SDL_Event event);
	virtual void draw();
};

#endif
