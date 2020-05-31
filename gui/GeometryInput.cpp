#include "GeometryInput.h"

GeometryInput::GeometryInput(
	SDL_Window *w, SDL_Renderer *r, int x1, int y1, int x2, int y2,
	std::string text, int fontSize, Graph *graph, GeometryParser *parser,
	TextOutput *createdObjects
) : LineInput(w, r, x1, y1, x2, y2, text, fontSize) {
	this->graph = graph;
	this->parser = parser;
	this->createdObjects = createdObjects;
}

App * GeometryInput::handleEvent(SDL_Event event) {
	App * nextApp = LineInput::handleEvent(event);
	if(nextApp != nullptr) {
		return nextApp;
	}

	if(event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_RETURN) {
		std::string inputType = this->parser->identify(this->text);
		if (inputType == "") {
			this->text = "";
		} else if (inputType == "angle" || inputType == "intersection") {
			// TODO: call geometricFunctions
		} else { // must be an object
			std::unordered_map <std::string, Object*> allObjects;
			allObjects = this->parser->parseObject(this->text);
			std::string createdObjs = "Angelegte Objekte: ";
			for(auto element : allObjects) {
				// add object to graph to be drawn
				this->graph->addObject(element.second);
				// add object and name to textoutput to be displayed
				createdObjs += element.first;
				createdObjs += " ";
				createdObjs += element.second->toString();
				createdObjs += "\n";
			}
			this->createdObjects->setText(createdObjs);
		}
		this->text = "";
	}

	return nextApp;
}
