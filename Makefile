# os specifics
ifeq ($(OS),Windows_NT)
	OS_FLAGS = -w -Wl,-subsystem,windows -lmingw32
	SDL2_LIBS = -L"${CURDIR}\gui\lib\SDL2\SDL2-2.0.12\i686-w64-mingw32\lib" -L"${CURDIR}\gui\lib\SDL2_ttf-2.0.15\i686-w64-mingw32\lib" -lSDL2main -lSDL2
	SDL2_CFLAGS = -I"${CURDIR}\gui\lib\SDL2\SDL2-2.0.12\i686-w64-mingw32\include" -I"${CURDIR}\gui\lib\SDL2\SDL2-2.0.12\i686-w64-mingw32\include\SDL2" -I"${CURDIR}\gui\lib\SDL2_ttf-2.0.15\i686-w64-mingw32\include" -I"${CURDIR}\gui\lib\SDL2_ttf-2.0.15\i686-w64-mingw32\include\SDL2"
	ARCHIVE_COMMAND = ar
	COMPILER_COMMAND = g++
else
	OS_FLAGS = 
	SDL2_LIBS = `sdl2-config --libs`
	SDL2_CFLAGS = `sdl2-config --cflags`
	ARCHIVE_COMMAND = ar
	COMPILER_COMMAND = g++
endif

# setting vars
BIN = math_tool
SFILES = main.cpp
OFILES = $(SFILES:.cpp=.o)
HFILES = gui/run.h
LIB_GUI = gui/
LIB_BACKEND = backend/
LIBS = $(LIB_GUI) $(LIB_BACKEND)
COMPILER_FLAGS = --std=c++14 $(SDL2_CFLAGS)
LINKER_FLAGS = -L gui/ -L backend/ -lgui -lbackend $(OS_FLAGS) $(SDL2_LIBS) -lSDL2_ttf

.PHONY: $(LIBS) clean

# link binary from object files
# use the right order for the libs, because they depend on each other!
$(BIN): $(LIBS) $(OFILES)
	$(COMPILER_COMMAND) -o $(BIN) $(OFILES) $(LINKER_FLAGS)

# compile
$(OFILES): $(SFILES) $(HFILES)
	$(COMPILER_COMMAND) -c $(COMPILER_FLAGS) $(SFILES)

# compile subfolders
$(LIBS):
	$(MAKE) --directory=$@

clean:
	$(MAKE) --directory=$(LIB_BACKEND) clean
	$(MAKE) --directory=$(LIB_GUI) clean

ifeq ($(OS),Windows_NT)
	del $(OFILES)
	del $(BIN).exe
else
	rm -f $(OFILES)
	rm -f $(BIN)
endif