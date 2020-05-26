#ifndef _PARSER_H_
#define _PARSER_H_

#include "TokenStream.h"
#include "error.h"

#define MAX_MEMORY 100

class Parser {
	private:
		double memory[MAX_MEMORY] = {};
		int currentMemPos;
		bool memoryFull;
		bool subExpr;
		TokenStream *tsp;
		Error error = {false, ""};
	public:
		Parser(TokenStream *tsp);

		double expr(bool getNeeded);
		double term(bool getNeeded);
		double power(bool getNeeded);
		double primary(bool getNeeded);

		std::string getMemory();

		bool getError();
		std::string getErrorMsg();
		void setError(std::string msg);
		void clearError();
};

#endif
