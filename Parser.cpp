#include <math.h>
#include "Parser.h"

Parser::Parser(TokenStream *tsp) {
	this->tsp = tsp;
	this->currentMemPos = 0;
	this->subExpr = false;
	this->memoryFull = false;
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
				if(currentMemPos == MAX_MEMORY - 1) {
					currentMemPos = 0; // reset memory
					memoryFull = true;
				}
				if(!subExpr) memory[currentMemPos++] = left; // save result to memory
				
				subExpr = false;
				return left;
		}
	}
}

double Parser::term(bool getNeeded) {
	double left = power(getNeeded);
	
	while(true) {
		switch((*tsp).current().kind) {
			case '*':
				left *= power(true);
				break;
			case '/': {
				double right = power(true);
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

double Parser::power(bool getNeeded) {
	double left = primary(getNeeded);
	
	while(true) {
		switch((*tsp).current().kind) {
			case '^':
				left = pow(left, primary(true));
				break;
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
			if(varNumber > MAX_MEMORY) {
				this->setError("ERROR: variable number invalid!");
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
		// trigonometric functions:
		case 's': {
			return sin(primary(true));
		}
		case 'c': {
			return cos(primary(true));
		}
		case 't': {
			return tan(primary(true));
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

void Parser::listMemory() {
	int end = this->memoryFull ? MAX_MEMORY : this->currentMemPos;
	
	for(int i = 0; i < end; i++) {
		std::cout << "[m" << i+1 << "] " << this->memory[i] << "\n";
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
