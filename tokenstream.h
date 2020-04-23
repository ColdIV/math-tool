#ifndef _TOKENSTREAM_H_
#define _TOKENSTREAM_H_

#include <iostream>
#include "token.h"

class TokenStream {
private:
	std::istream *ip;
	Token currentToken;
public:
	TokenStream(std::istream *ip);
	
	Token get(); 
	Token current();
};

#endif
