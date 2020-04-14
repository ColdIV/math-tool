#ifndef _TOKENSTREAM_H_
#define _TOKENSTREAM_H_

#include <iostream>
#include "token.h"

using namespace std;

class TokenStream {
private:
	istream *ip;
	Token currentToken;
public:
	TokenStream(istream *ip);
	
	Token get(); 
	Token current();
};

#endif
