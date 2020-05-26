#include "Calculator.h"


Calculator::Calculator(std::istream *ip) {
	this->ip = ip;
	TokenStream *ts = new TokenStream{ip};
	Parser *ps = new Parser{ts};
	this->parser = ps;
}

void Calculator::calculate(std::string s) {
	// if ip is a stringstream, we have to dynamically cast it to one, because
	// it is saved as pointer to the base class (istream)
	if (typeid(*ip) == typeid(stringstream)){
		*(dynamic_cast<stringstream*>(ip)) << s;
	} else {
		throw "calculate() can't be called";
	}

	this->parser->expr(true);
}

std::string Calculator::getMemory() {
	return this->parser->getMemory();
}
