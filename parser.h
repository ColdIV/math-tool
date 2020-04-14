#ifndef _PARSER_H_
#define _PARSER_H_

#include "tokenstream.h"

class Parser {
	private:
		double memory[100] = {};
		TokenStream *tsp;
	public:
		Parser(TokenStream *tsp);
		
		double expr(bool getNeeded);
		double term(bool getNeeded);
		double primary(bool getNeeded);
};

#endif
