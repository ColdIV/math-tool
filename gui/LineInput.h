#ifndef _LINE_INPUT_H_
#define _LINE_INPUT_H_

#include <string>

#include "Widget.h"

class LineInput : public Widget {
protected:
	std::string text;
	int fontSize;
public:
	LineInput(
		SDL_Window *w, SDL_Renderer *r, int x1, int y1,
		int x2, int y2, std::string text, int fontSize
	);

	virtual App * handleEvent(SDL_Event event);
	virtual void draw();
};

#endif
