OBJS = sdl-test.cpp gui.cpp

OBJ_NAME = sdl-test

INCLUDES = -I"${CURDIR}\lib\SDL2\SDL2-2.0.12\i686-w64-mingw32\include" -I"${CURDIR}\lib\SDL2\SDL2-2.0.12\i686-w64-mingw32\include\SDL2" -I"${CURDIR}\lib\SDL2_ttf-2.0.15\i686-w64-mingw32\include" -I"${CURDIR}\lib\SDL2_ttf-2.0.15\i686-w64-mingw32\include\SDL2"
LIBRARIES = -L"${CURDIR}\lib\SDL2\SDL2-2.0.12\i686-w64-mingw32\lib" -L"${CURDIR}\lib\SDL2_ttf-2.0.15\i686-w64-mingw32\lib"
FLAGS = -w -Wl,-subsystem,windows -lmingw32 -lSDL2main -lSDL2 -lSDL2_ttf

all : $(OBJS)
	g++ $(OBJS) $(INCLUDES) $(LIBRARIES) $(FLAGS) -o $(OBJ_NAME)