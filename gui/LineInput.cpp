#include <sstream>

#include "LineInput.h"
#include "MenuApp.h"
#include "render_text.h"


LineInput::LineInput(
	SDL_Window *w, SDL_Renderer *r, int x1, int y1,
	int x2, int y2, std::string text, int fontSize
) : Widget(w, r, x1, y1, x2, y2) {
	this->text = text;
	this->fontSize = fontSize;
}

App * LineInput::handleEvent(SDL_Event event) {
	Widget::handleEvent(event);
	if(event.type == SDL_TEXTINPUT || event.type == SDL_KEYDOWN) {
		if(event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_RETURN) {
			if(this->text == "exit" || this->text == "quit" || this->text == "q") {
				App * nextApp = new MenuApp{this->window, this->renderer};
				return nextApp;
			}
		} else if(event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_BACKSPACE
			&& this->text.length() > 0
		) {
			this->text = this->text.substr(0, this->text.length() - 1);
		} else if(event.type == SDL_TEXTINPUT) {
			this->text += event.text.text;
		}
	}

	// subclasses return next App depending on user input
	return nullptr;
}

void LineInput::draw() {
	Widget::draw();

	render_text(
		this->renderer, this->xStart, this->yStart, this->xEnd, this->yEnd,
		this->fontSize, this->text
	);

	// reset color
	SDL_SetRenderDrawColor(this->renderer, 0, 0, 0, 255);
}
