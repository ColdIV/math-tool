#include <iostream>

#include "debug.h"


extern const bool DEBUG;

void debug(std::string message) {
	if (true == DEBUG) {
		std::cout << message << std::endl;
	}
}
