COMPILER_COMMAND = g++
ARCHIVE_COMMAND = ar

ARCHIVE=libbackend.a
SFILES = Calculator.cpp Circle.cpp Line.cpp Object.cpp Parser.cpp Point.cpp \
	Rectangle.cpp Square.cpp tests.cpp TokenStream.cpp Triangle.cpp
OFILES = $(SFILES:.cpp=.o)
HFILES= Calculator.h Circle.h error.h Line.h Object.h Parser.h Point.h \
	Rectangle.h Square.h tests.h Token.h TokenStream.h Triangle.h
COMPILER_FLAGS = --std=c++14


$(ARCHIVE): $(OFILES)
	$(ARCHIVE_COMMAND) rcs $(ARCHIVE) $(OFILES)

$(OFILES): $(SFILES) $(HFILES)
	$(COMPILER_COMMAND) $(COMPILER_FLAGS) -c $(SFILES)

.PHONY:
clean:
ifeq ($(OS),Windows_NT)
	del $(OFILES)
	del $(ARCHIVE)
else
	rm -f $(OFILES)
	rm -f $(ARCHIVE)
endif
