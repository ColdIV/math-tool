#ifndef _FUNCTIONPLOTTER_H_
#define _FUNCTIONPLOTTER_H_

#include <iostream>
#include <string>

#include "calculator.h"

class FunctionPlotter {
	private:
		double rangeStart;
		double rangeEnd;
		double stepSize;
		
		std::string replaceAll(std::string s, std::string from, std::string to);
	public:
		FunctionPlotter();
		FunctionPlotter(double rs, double re, double ss);
		
		void plot(std::string s);
};

#endif
