#ifndef _TOKEN_H_
#define _TOKEN_H_

#include <string>

struct Token {
	char kind;
	std::string strValue;
	double numValue = 0;
};

#endif
