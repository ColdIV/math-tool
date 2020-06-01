#ifndef _TEXT_OUTPUT_H_
#define _TEXT_OUTPUT_H_

#include <string>

#include "Widget.h"


class TextOutput : public Widget {
private:
	std::string text;
	int fontSize;
public:
	TextOutput(
		SDL_Window *w, SDL_Renderer *r, int x1, int y1,
		int x2, int y2, std::string text, int fontSize
	);

	virtual void draw();
	std::string getText();
	void setText(std::string newText);
};

#endif
