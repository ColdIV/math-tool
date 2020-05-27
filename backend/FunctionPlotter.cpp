#include "FunctionPlotter.h"


FunctionPlotter::FunctionPlotter() {
	this->rangeStart = -50;
	this->rangeEnd = 50;
	this->stepSize = 0.05;
}

FunctionPlotter::FunctionPlotter(double rs, double re, double ss) {
	this->rangeStart = rs;
	this->rangeEnd = re;
	this->stepSize = ss;
}

void FunctionPlotter::makeFunction(std::string s) {
	// TODO: check syntax of function?

	// we can instanciate a calculator here, we don't need to save it
	Calculator C;

	std::cout << "plotting function: " << s << "\n";

	// replace every x with * x TODO: this does not allow stuff like "sin(x)"
	//s = replaceAll(s, "x", "*x");

	this->functionObject = nullptr;

	// replace x with every possible number in the given range, calculate result
	// and add the resulting point to the functionObject
	for(double i = this->rangeStart; i < this->rangeEnd; i += this->stepSize) {
		std::string currentNum = std::to_string(i);
		std::string converted = replaceAll(s, "x", currentNum);
		double result = C.calculate(converted);
		// make a point
		Point P(i, result);
		if (this->functionObject == nullptr) {
			functionObject = new Object(P); // set first point
		} else {
			functionObject->addPoint(P); // set all additional points
		}
	}
}

Object * FunctionPlotter::getFunction() {
	return this->functionObject;
}

std::string FunctionPlotter::replaceAll(std::string s, std::string from, std::string to) {
	int pos = s.find(from);

	while(pos < s.length()) {
		s.replace(pos, from.length(), to);
		pos = s.find(from, pos + to.length()); // start next search after the replaced chars
	}

	return s;
}
