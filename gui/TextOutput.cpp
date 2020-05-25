#include <sstream>

#include "TextOutput.h"
#include "debug.h"
#include "render_text.h"


TextOutput::TextOutput(
	SDL_Window *w, SDL_Renderer *r, int x1, int y1,
	int x2, int y2, std::string text, int fontSize
) : Widget(w, r, x1, y1, x2, y2) {
	this->text = text;
	this->fontSize = fontSize;
}

void TextOutput::draw(){
	Widget::draw();
	debug("drawing in textoutput");

	render_text(
		this->renderer, this->xStart, this->yStart, this->xEnd, this->yEnd,
		this->fontSize, this->text
	);

	// reset color
	SDL_SetRenderDrawColor(this->renderer, 0, 0, 0, 255);
}

void TextOutput::setText(std::string newText) {
	this->text = newText;
}
