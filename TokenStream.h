#ifndef _TOKENSTREAM_H_
#define _TOKENSTREAM_H_

#include <iostream>
#include <sstream>
#include "Token.h"

class TokenStream {
private:
	std::istream *ip;
	Token currentToken;
public:
	TokenStream(std::istream *ip);

	void resetStream();
	Token get();
	Token current();
};

#endif
