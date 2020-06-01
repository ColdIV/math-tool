#ifndef _FUNCTIONPLOTTER_H_
#define _FUNCTIONPLOTTER_H_

#include <iostream>
#include <string>
#include <regex>

#include "Object.h"
#include "Point.h"
#include "Calculator.h"

class FunctionPlotter {
	private:
		Object *functionObject;
		double rangeStart;
		double rangeEnd;
		double stepSize;

		std::string normalizeInput(std::string s);
		std::string replaceAll(std::string s, std::string from, std::string to);
	public:
		FunctionPlotter();
		FunctionPlotter(double rs, double re, double ss);

		void makeFunction(std::string s);
		Object * getFunction();
};

#endif
