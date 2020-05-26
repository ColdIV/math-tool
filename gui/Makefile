ARCHIVE=libgui.a
SFILES = App.cpp CalculatorApp.cpp CalculatorInput.cpp debug.cpp \
	FunctionPlotterApp.cpp FunctionPlotterInput.cpp GeometryApp.cpp \
	GeometryInput.cpp Graph.cpp LineInput.cpp local_config.cpp MenuApp.cpp \
	MenuInput.cpp render_text.cpp run.cpp TextOutput.cpp Widget.cpp
OFILES = $(SFILES:.cpp=.o)
HFILES = App.h CalculatorApp.h CalculatorInput.h debug.h FunctionPlotterApp.h \
	FunctionPlotterInput.h GeometryApp.h GeometryInput.h Graph.h \
	LineInput.h MenuApp.h MenuInput.h render_text.h TextOutput.h Widget.h
COMPILER_FLAGS = -std=c++14 -I.. $(SDL2_CFLAGS)


$(ARCHIVE): $(OFILES)
	$(ARCHIVE_COMMAND) rcs $(ARCHIVE) $(OFILES)

$(OFILES): $(SFILES) $(HFILES)
	$(COMPILER_COMMAND) $(COMPILER_FLAGS) -c $(SFILES)

.PHONY:
clean:
	rm -f $(OFILES)
	rm -f $(ARCHIVE)
