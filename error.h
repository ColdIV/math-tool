#ifndef _ERROR_H_
#define _ERROR_H_

#include <string>

using namespace std;

struct Error {
	bool state = false;
	string message = "";
};

#endif
