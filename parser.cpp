#include "parser.h"

Parser::Parser(TokenStream *tsp) {
	this->tsp = tsp;
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
					cout << "ERROR: division by zero" << endl;
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
			double expression = expr(true);
			if ((*tsp).current().kind != ')') {
				cout << "ERROR: ) expected!" << endl;
				return 0;
			}
			(*tsp).get(); // drop the ")" at the end of the expression from currentToken
			return expression;
		}
		case 'v': { // variable
			int varNumber = stoi((*tsp).current().strValue) - 1;
			if(varNumber > 100) {
				cout << "ERROR: you can store up to 100 variables" << endl;
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
		default:
			cout << "ERROR: not a primary!" << endl;
			return 0;
	}
}

