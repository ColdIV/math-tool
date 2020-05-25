#ifndef _MENU_INPUT_H_
#define _MENU_INPUT_H_

#include "LineInput.h"

class MenuInput : public LineInput{
public:
	MenuInput(
		SDL_Window *w, SDL_Renderer *r, int x1, int y1,
		int x2, int y2, std::string text, int fontSize
	);

	virtual App * handleEvent(SDL_Event event);
};

#endif
