#include <iostream>

#include "debug.h"


void debug(std::string message) {
	if (true == DEBUG) {
		std::cout << message << std::endl;
	}
}
