#ifndef _PARSER_H_
#define _PARSER_H_

#include "tokenstream.h"
#include "error.h"

class Parser {
	private:
		double memory[100] = {};
		TokenStream *tsp;
		Error error = {false, ""};
	public:
		Parser(TokenStream *tsp);
		
		double expr(bool getNeeded);
		double term(bool getNeeded);
		double primary(bool getNeeded);
		bool getError();
		std::string getErrorMsg();
		void setError(std::string msg);
		void clearError();
};

#endif
