#include "FunctionPlotter.h"

#include <regex>
#include <iostream>

FunctionPlotter::FunctionPlotter() {
	this->rangeStart = -100;
	this->rangeEnd = 100;
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

	// replace every x with *x if it is preceded by a number
	s = normalizeInput(s);

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

std::string FunctionPlotter::normalizeInput(std::string s) {
	// digit followed by a "x"
	std::regex r ("([[:digit:]])x");
	return std::regex_replace(s, r, "$1*x");
}

std::string FunctionPlotter::replaceAll(std::string s, std::string from, std::string to) {
	int pos = s.find(from);

	while(pos < s.length()) {
		s.replace(pos, from.length(), to);
		pos = s.find(from, pos + to.length()); // start next search after the replaced chars
	}

	return s;
}
