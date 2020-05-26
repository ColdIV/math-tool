#ifndef _APP_H_
#define _APP_H_

#include <SDL.h>
#include <vector>

#include "debug.h"
#include "Widget.h"


class App {
private:
	static const int delay = 30;
	SDL_Window *window;
	SDL_Renderer *renderer;
	void blankScreen();
protected:
	std::vector<Widget *> widgets;
public:
	App(SDL_Window *w, SDL_Renderer *r);
	virtual ~App();
	App* mainloop();
};

#endif
