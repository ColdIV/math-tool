#include "Parser.h"

Parser::Parser(TokenStream *tsp) {
	this->tsp = tsp;
	this->currentMemPos = 0;
	this->subExpr = false;
}

double Parser::expr(bool getNeeded) {
	this->clearError();
	double left = term(getNeeded);
	
	while(true) {
		switch((*tsp).current().kind) {
			case '+':
				left += term(true);
				break;
			case '-':
				left -= term(true);
				break;
			default:
				if(currentMemPos == 99) currentMemPos = 0; // reset memory
				if(!subExpr) memory[currentMemPos++] = left; // save result to memory
				
				subExpr = false;
				return left;
		}
	}
}

double Parser::term(bool getNeeded) {
	double left = primary(getNeeded);
	
	while(true) {
		switch((*tsp).current().kind) {
			case '*':
				left *= primary(true);
				break;
			case '/': {
				double right = primary(true);
				if(right == 0) {
					this->setError("ERROR: division by zero");
					return 0;
				}
				left /= right;
				break;
			}
			default:
				return left;
		}
	}
}

double Parser::primary(bool getNeeded) {
	if(getNeeded) {
		(*tsp).get();
	}
	
	switch((*tsp).current().kind) {
		case 'n': { // number
			double value = (*tsp).current().numValue;
			(*tsp).get();
			return value;
		}
		case '-': // unary minus
			return -primary(true);
		case '(': { // start of prioritized expression
			subExpr = true; // do not save subexpression to memory
			double expression = expr(true);
			if ((*tsp).current().kind != ')') {
				this->setError("ERROR: ) expected!");
				return 0;
			}
			(*tsp).get(); // drop the ")" at the end of the expression from currentToken
			return expression;
		}
		case 'v': { // variable
			int varNumber = stoi((*tsp).current().strValue) - 1;
			if(varNumber > 100) {
				this->setError("ERROR: you can store up to 100 variables");
				return 0;
			}
			(*tsp).get(); // get next token
			
			if((*tsp).current().kind == '=') { // calculate and store
				double value = expr(true); 
				memory[varNumber] = value;
				return value;
			} else { // no assignment, variable is used in expression
				return memory[varNumber];
			}
		}
		case '#': { // skip
			this->setError("");
			return 0;
		}
		default:
			this->setError("ERROR: not a primary!");
			return 0;
	}
}

bool Parser::getError() {
	return this->error.state;
}

std::string Parser::getErrorMsg() {
	return this->error.message;
}

void Parser::setError(std::string msg) {
	this->error = {true, msg};
}

void Parser::clearError() {
	this->error = {false, ""};
}
