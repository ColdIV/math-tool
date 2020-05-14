#include "FunctionPlotter.h"


FunctionPlotter::FunctionPlotter() {
	this->rangeStart = -5;
	this->rangeEnd = 5;
	this->stepSize = 0.05;
}

FunctionPlotter::FunctionPlotter(double rs, double re, double ss) {
	this->rangeStart = rs;
	this->rangeEnd = re;
	this->stepSize = ss;
}

void FunctionPlotter::plot(std::string s) {
	// TODO: check syntax of function?
	
	std::cout << "plotting function: " << s << "\n";
	
	// replace every x with * x
	s = replaceAll(s, "x", "*x");
	
	// replace x with every possible number in the given range, calculate result
	// and plot it
	for(double i = this->rangeStart; i < this->rangeEnd; i += this->stepSize) {
		std::string currentNum = std::to_string(i);
		std::string converted = replaceAll(s, "x", currentNum);
		double result = calculate_single(converted);
		std::cout << "result: " << result << "\n";
		// TODO: plot result!
	}
}

std::string FunctionPlotter::replaceAll(std::string s, std::string from, std::string to) {
	int pos = s.find(from);
	
	while(pos < s.length()) {
		s.replace(pos, from.length(), to);
		pos = s.find(from, pos + to.length()); // start next search after the replaced chars
	}
	
	return s;
}
