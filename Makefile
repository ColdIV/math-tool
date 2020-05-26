BIN = math_tool
SFILES = main.cpp
OFILES = $(SFILES:.cpp=.o)
HFILES = gui/run.h
LIB_GUI = gui/
LIB_BACKEND = backend/
LIBS = $(LIB_GUI) $(LIB_BACKEND)
COMPILER_FLAGS = -std=c++14 $(SDL2_CFLAGS)
LINKER_FLAGS= -L gui/ -L backend/ -lgui -lbackend $(SDL2_LIBS) -lSDL2_ttf


.PHONY: $(LIBS) clean

# link binary from object files
# use the right order for the libs, because they depend on each other!
$(BIN): $(LIBS) $(OFILES)
	$(COMPILER_COMMAND) -o $(BIN) $(OFILES) $(LINKER_FLAGS)

# compile
$(OFILES): $(SFILES) $(HFILES)
	$(COMPILER_COMMAND) -c $(COMPILER_FLAGS)  $(SFILES)

# compile subfolders
$(LIBS):
	$(MAKE) --directory=$@

clean:
	$(MAKE) --directory=$(LIB_BACKEND) clean
	$(MAKE) --directory=$(LIB_GUI) clean
	rm -f $(OFILES)
	rm -f $(BIN)
