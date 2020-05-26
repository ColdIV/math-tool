#ifndef _CALCULATOR_INPUT_H_
#define _CALCULATOR_INPUT_H_

#include "backend/Calculator.h"
#include "TextOutput.h"
#include "LineInput.h"

class Calculator;

class CalculatorInput : public LineInput{
private:
	TextOutput *output;
	std::stringstream *stream;
	Calculator *calculator;
public:
	CalculatorInput(
		SDL_Window *w, SDL_Renderer *r, int x1, int y1, int x2, int y2,
		std::string text, int fontSize, TextOutput *output
	);

	virtual App * handleEvent(SDL_Event event);
	double calculate(std::string text);
};

#endif
