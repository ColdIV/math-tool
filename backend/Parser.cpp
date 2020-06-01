#include <math.h>
#include "Parser.h"

Parser::Parser(TokenStream *tsp) {
	this->tsp = tsp;
	this->currentMemPos = 0;
	this->subExpr = false;
	this->memoryFull = false;
}

double Parser::expr(bool getNeeded) {
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
					throw "ERROR: division by zero";
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
				throw "ERROR: ) expected";
			}
			(*tsp).get(); // drop the ")" at the end of the expression from currentToken
			return expression;
		}
		case 'v': { // variable
			int varNumber = stoi((*tsp).current().strValue) - 1;
			if(varNumber > MAX_MEMORY) {
				throw "ERROR: variable number invalid";
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
		default:
			throw "ERROR: not a primary";
	}
}

std::string Parser::getMemory() {
	std::ostringstream out;

	int end = this->memoryFull ? MAX_MEMORY : this->currentMemPos;

	// build memory entries and add to output stream, we want nice formatting
	for(int i = 0; i < end; i++) {
		out << "[m" << i+1 << "] " << this->memory[i] << "\n";
	}

	return out.str();
}
