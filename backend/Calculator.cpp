#include "Calculator.h"


Calculator::Calculator() {
	std::stringstream *s = new stringstream;
	this->ip = s;
	this->ts = new TokenStream(ip);
	this->parser = new Parser(ts);
	this->ownsStream = true; // we own the stream and have to delete it
}

Calculator::Calculator(std::istream *ip) {
	this->ip = ip;
	this->ts = new TokenStream{ip};
	this->parser = new Parser{ts};
	this->ownsStream = false; // we don't own the stream and can't delete it
}

Calculator::~Calculator() {
	if (this->ownsStream) {
		delete this->ip;
	}
	delete this->ts;
	delete this->parser;
}

double Calculator::calculate(std::string s) {
	// if ip is a stringstream, we have to dynamically cast it to one, because
	// it is saved as pointer to the base class (istream)
	if (typeid(*ip) == typeid(stringstream)){
		*(dynamic_cast<stringstream*>(ip)) << s;
	} else {
		throw "calculate() can't be called";
	}

	return this->parser->expr(true);
}

std::string Calculator::getMemory() {
	return this->parser->getMemory();
}
