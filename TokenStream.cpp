#include "TokenStream.h"

TokenStream::TokenStream(std::istream *ip) {
	this->ip = ip;
	this->currentToken = {'e', "end", 0};
}

Token TokenStream::get() {
	char ch = 0;

	// skip whitespace except for new lines
	do {
		if(!(this->ip->get(ch))) {
			this->currentToken = {'e', "end", 0};
			return this->currentToken;
		}
	} while (ch != '\n' && isspace(ch));
	
	switch(ch) {
		case 0:
		case 'q':
		case 'e': // end the stream with ctrl+d, q or e
			this->currentToken = {'e', "end", 0};
			break;
		case ';':
		case '\n':
			this->currentToken = {'p', "print", 0};
			break;
		case '/':
		case '*':
		case '+':
		case '-':
		case '^':
		case '(':
		case ')':
		case '=': // operator
			this->currentToken = {ch, "", 0};
			break;
		case '0':
		case '1':
		case '2':
		case '3':
		case '4':
		case '5':
		case '6':
		case '7':
		case '8':
		case '9':
		case '.':
			// we're reading a (floating point) number, put the first digit back
			this->ip->putback(ch);
			// read the whole number into the current Token's numValue
			*(this->ip) >> this->currentToken.numValue;
			this->currentToken.kind = 'n';
			this->currentToken.strValue = "";
			break;
		case 's':
		case 'c':
		case 't':
			// we're reading a trigonometric function, put first char back
			this->ip->putback(ch);
			// record the type of the function, can't use >> because it won't
			// stop at the (
			std::getline(*(this->ip), this->currentToken.strValue, '(');
			// error checking: what if ( is missing?
			// possible error checking: check if strValue == sin, cos or tan
			this->ip->putback('(');
			this->currentToken.kind = 't';
			break;
		case 'M': // we have a variable
		case 'm':
			// read the subsequent number of the variable into strValue
			// numValue will later be the assigned value of that variable
			char nextChar;
			int varNumber;
			*(this->ip) >> nextChar;
			if(!isdigit(nextChar)) {
				std::cout << "ERROR: invalid variable number: " << nextChar << "\n";
				this->currentToken = {'#', "skip", 0};
			} else {
				this->ip->putback(nextChar);
				*(this->ip) >> varNumber;
				this->currentToken.kind = 'v';
				this->currentToken.strValue = std::to_string(varNumber);
			}
			break;
		default: // error
			std::cout << "ERROR: invalid input: " << ch << "\n";
			this->currentToken = {'#', "skip", 0};
			break;
	}
	
	return this->currentToken;
}

Token TokenStream::current() {
	return this->currentToken;
}
