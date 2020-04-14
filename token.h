#ifndef _TOKEN_H_
#define _TOKEN_H_

#include <string>

using namespace std;

struct Token {
	char kind;
	string strValue;
	double numValue = 0;
};

#endif
