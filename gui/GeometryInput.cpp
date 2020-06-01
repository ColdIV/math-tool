#include "GeometryInput.h"


GeometryInput::GeometryInput(
	SDL_Window *w, SDL_Renderer *r, int x1, int y1, int x2, int y2,
	std::string text, int fontSize, Graph *graph, GeometryParser *parser,
	TextOutput *createdObjects, TextOutput *funcResults
) : LineInput(w, r, x1, y1, x2, y2, text, fontSize) {
	this->graph = graph;
	this->parser = parser;
	this->createdObjects = createdObjects;
	this->funcResults = funcResults;
}

App * GeometryInput::handleEvent(SDL_Event event) {
	App * nextApp = LineInput::handleEvent(event);
	if(nextApp != nullptr) {
		return nextApp;
	}

	if(event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_RETURN) {
		if (this->text == "+") {
			this->graph->changeZoomLevel(true);
		} else if (this->text == "-") {
			this->graph->changeZoomLevel(false);
		} else {
			std::string inputType = this->parser->identify(this->text);
			if (inputType == "") {
				this->text = "";
			} else if (inputType == "angle" || inputType == "intersection") {
				if (inputType == "angle") {
					displayAngle();
				} else {
					displayIntersections();
				}
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
		}
		this->text = "";
	}

	return nextApp;
}

void GeometryInput::displayAngle() {
	std::vector<Object*> params; // we need 2 lines to calc angle
	params = this->parser->parseParameters(this->text);
	Line *line1 = dynamic_cast<Line*>(params[0]);
	Line *line2 = dynamic_cast<Line*>(params[1]);
	double result = angle(*line1, *line2);
	std::string resultString = this->funcResults->getText();
	resultString += this->text;
	resultString += ": ";
	resultString += std::to_string(result);
	resultString += "\n";
	this->funcResults->setText(resultString);
}

void GeometryInput::displayIntersections() {
	std::vector<Object *> params; // we need to objects to calculate intersection
	params = this->parser->parseParameters(this->text);
	std::vector<Point> intersections; // the resulting intersections
	intersections = getIntersections(*(params[0]), *(params[1]));
	// add Intersections to the objects to be drawn
	// TODO: maybe add it to a different vector, so that they can be drawn differently
	// from regular objects (e.g. filled)
	// display string representation of the intersections on screen
	std::string resultString = this->funcResults->getText();
	resultString += this->text;
	for (Point p : intersections) {
		resultString += ": (";
		resultString += std::to_string(p.x());
		resultString += "/";
		resultString += std::to_string(p.y());
		resultString += "),\n";
		this->funcResults->setText(resultString);
	}
}
