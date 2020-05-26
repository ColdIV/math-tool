#ifndef _CALCULATOR_H_
#define _CALCULATOR_H_

#include <string>
#include <iostream>
#include <sstream>
#include "Parser.h"
#include "TokenStream.h"

class Calculator {
private:
	std::istream *ip;
	Parser *parser;
public:
	Calculator(std::istream *ip);
	void calculate(std::string s);
	std::string getMemory();
};

#endif
