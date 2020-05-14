#include "calculator.h"

void calculate(istream* s) {
	// TokenStream takes an "istream" pointer and splits it into specific Tokens.
	// Tokens are a specific "kind" which defines what the Parser (calculator)
	// will do with them.
	TokenStream TS(s);
	
	// The Parser handles the main calculation. It is initialized with a pointer 
	// to the TokenStream object. It uses recursive descent to handle complex
	// expressions.
	Parser P(&TS);
	
	while(true) {
		// get the first Token from the TokenStream
		TS.get();
		if (TS.current().kind == 'p') continue; // print the result of a calculation after a ";" or "\n"
		if(TS.current().kind == 'e') break; // end the calculation after "q", "e" or ctrl+d (input stream EOF)
		
		double res = P.expr(false); // main Parser entrypoint. Calling expr with false means that it will
									   // not get a new Token from the TokenStream.
		
		if(P.getError()) {
			std::cout << P.getErrorMsg() << endl;
		} else {
			std::cout << res << endl;
		}
	}
	
	P.listMemory();
}

void calculate(string s) {
	// string has to be converted to stream before passing it to TokenStream
	istringstream stream1;
	stream1.str(s);
	
	calculate(&stream1);
}

double calculate_single(string s) {
	istringstream stream1;
	stream1.str(s);
	
	TokenStream TS(&stream1);
	Parser P(&TS);
	
	return P.expr(true);
}
