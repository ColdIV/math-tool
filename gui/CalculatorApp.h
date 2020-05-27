#ifndef _CALCULATOR_APP_H_
#define _CALCULATOR_APP_H_

#include <string>

#include "backend/Calculator.h"
#include "App.h"


class CalculatorApp : public App {
private:
	Calculator *calculator;
public:
	CalculatorApp(SDL_Window *window, SDL_Renderer *renderer);
	virtual ~CalculatorApp();
};

#endif
