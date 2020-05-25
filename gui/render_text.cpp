#include <SDL.h>
#include <SDL_ttf.h>
#include <string>
#include <sstream>

#include "render_text.h"

void render_text(
	SDL_Renderer *renderer, int xStart, int yStart, int xEnd, int yEnd,
	int fontSize, std::string text
){
	// set font and color

	TTF_Font *font = TTF_OpenFont("arial.ttf", fontSize);
	SDL_Color color = {150, 200, 255, 255};

	// helper variables
	int textW = xEnd - xStart;
	int textH = yEnd - yStart;

	// starting point of message rectangle
	int startX = xStart;
	int startY = yStart - 70;

	// text has to be converted to istream in order to call getline
	std::stringstream ss(text);
	std::string textToRender;

	// break at newline and render single line
	while(getline(ss, textToRender, '\n')) {
		startY += 70;
		SDL_Surface *textSurface = TTF_RenderText_Solid(
			font, textToRender.c_str(), color
		);
		SDL_Texture *texture = SDL_CreateTextureFromSurface(
			renderer, textSurface
		);
		// depending on font size used, determine width and height automatically
		SDL_QueryTexture(texture, NULL, NULL, &textW, &textH);
		SDL_Rect messageRect = {startX, startY, textW, textH};
		SDL_RenderCopy(renderer, texture, NULL, &messageRect);
		SDL_FreeSurface(textSurface);
		SDL_DestroyTexture(texture);
	}

	TTF_CloseFont(font);
}
