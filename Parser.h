#ifndef _PARSER_H_
#define _PARSER_H_

#include "TokenStream.h"
#include "error.h"

class Parser {
	private:
		double memory[100] = {};
		int currentMemPos;
		bool subExpr;
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
