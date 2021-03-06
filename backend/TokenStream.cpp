#include "TokenStream.h"

TokenStream::TokenStream(std::istream *ip) {
	this->ip = ip;
	this->currentToken = {'e', "end", 0};
}

// reset stream in case we encountered an EOF, so that we can fill the
// stringstream again with a new string and that we can read from it again
void TokenStream::resetStream() {
	if (typeid(*ip) == typeid(std::stringstream)){
		// dynamic_cast needed because ip is stored as pointer to the base class
		std::stringstream *ssp = dynamic_cast<std::stringstream*>(ip);
		ssp->str(""); // get rid of the EOF
		ssp->clear(); // make it readable again
	}
}

Token TokenStream::get() {
	char ch = EOF;

	while((ch = this->ip->get()) != '\n' && isspace(ch));

	switch(ch) {
		case EOF:
		case 'q':
		case 'e': // end the stream with ctrl+d, q or e
			resetStream();
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
			char c;
			int inputLen;
			// read characters until we encounter a space or (
			// strValue can't be empty, otherwise the overwriting by character won't work
			this->currentToken.strValue = "placeholder";
			for (inputLen = 0; (c = this->ip->get()) != '(' && !isspace(c) && c != EOF; inputLen++) {
				this->currentToken.strValue[inputLen] = c;
			}
			// cat strValue at the end of the function name
			this->currentToken.strValue.resize(inputLen);

			if(c == '(') {
				this->ip->putback('(');
			}

			if((this->currentToken.strValue) == "sin") {
				this->currentToken.kind = 's';
			} else if((this->currentToken.strValue) == "cos") {
				this->currentToken.kind = 'c';
			} else if((this->currentToken.strValue) == "tan") {
				this->currentToken.kind = 't';
			} else{
				resetStream();
				throw "ERROR: not a valid function";
			}

			break;
		case 'M': // we have a variable
		case 'm':
			// read the subsequent number of the variable into strValue
			// numValue will later be the assigned value of that variable
			char nextChar;
			int varNumber;
			*(this->ip) >> nextChar;
			if(!isdigit(nextChar)) {
				resetStream();
				throw "ERROR: invalid variable number";
			} else {
				this->ip->putback(nextChar);
				*(this->ip) >> varNumber;
				this->currentToken.kind = 'v';
				this->currentToken.strValue = std::to_string(varNumber);
			}
			break;
		default: // error
			resetStream();
			throw "ERROR: invalid input";
	}

	return this->currentToken;
}

Token TokenStream::current() {
	return this->currentToken;
}
