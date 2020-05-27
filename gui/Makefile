# os specifics
ifeq ($(OS),Windows_NT)
	OS_FLAGS = -w -Wl,-subsystem,windows -lmingw32
	SDL2_CFLAGS = -I"${CURDIR}\lib\SDL2\SDL2-2.0.12\i686-w64-mingw32\include" -I"${CURDIR}\lib\SDL2\SDL2-2.0.12\i686-w64-mingw32\include\SDL2" -I"${CURDIR}\lib\SDL2_ttf-2.0.15\i686-w64-mingw32\include" -I"${CURDIR}\lib\SDL2_ttf-2.0.15\i686-w64-mingw32\include\SDL2"
	ARCHIVE_COMMAND = ar
	COMPILER_COMMAND = g++
else
	OS_FLAGS = 
	SDL2_CFLAGS = `sdl2-config --cflags`
	ARCHIVE_COMMAND = ar
	COMPILER_COMMAND = g++
endif

# setting vars
ARCHIVE=libgui.a
SFILES = App.cpp CalculatorApp.cpp CalculatorInput.cpp debug.cpp \
	FunctionPlotterApp.cpp FunctionPlotterInput.cpp GeometryApp.cpp \
	GeometryInput.cpp Graph.cpp LineInput.cpp local_config.cpp MenuApp.cpp \
	MenuInput.cpp render_text.cpp run.cpp TextOutput.cpp Widget.cpp
OFILES = $(SFILES:.cpp=.o)
HFILES = App.h CalculatorApp.h CalculatorInput.h debug.h FunctionPlotterApp.h \
	FunctionPlotterInput.h GeometryApp.h GeometryInput.h Graph.h \
	LineInput.h MenuApp.h MenuInput.h render_text.h TextOutput.h Widget.h
COMPILER_FLAGS = --std=c++14 -I.. $(SDL2_CFLAGS) $(OS_FLAGS)


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
