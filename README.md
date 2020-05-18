# math-tool
math-tool - a school project

# General description
The tool consists of 3 main parts:

### Calculator
- The user can enter basic arithmetic calculations as well as some advanced functions: power, sin, tan, cos
- The results of those calculations will be saved to variables. In total, there are 100 available variables.
- The variables and their values will be shown as they are created
- The values inside of the variables can be used in further calculations

### Geometry
- The user can create geometrical objects: Point, Line, Triangle, Square, Rectangle, Circle
- The program saves some (at least 2) of those objects in variables
- Through those variables, the user can access the objects to use in functions: Intersection, Angle
- The objects and the results of the functions will be displayed in a coordinate system

### Function plotter
- The user can enter a polynomial function that will be displayed in a coordinate system
- The user can zoom in and out

# master branch
The master branch should always be clean and running fine!
If you work on an issue, please create a new branch and create a pull request when done.
The pull request should be reviewed by at least one person before it gets merged into the master.
You can push "bugs" to your branch but not to the master.

# Project management
Some issues / tasks depend on others, those are listed as "On hold".
If you start working on one of those tasks, please move them to "In progress".

If you start working on an issue, don't forget to assign it to you!

# Build Instructions (Windows, MinGW32)
We use MinGW32, SDL2 and SDL2_ttf. (Always the 32bit version)
The folder `lib/` should contain the SDL2 and SDL2_ttf files.
You can get them here: 
https://www.libsdl.org/download-2.0.php (Development Version for MinGW, version 2.0.12)
We need: `lib/SDL2/SDL2-2.0.12/i686-w64-mingw32/*` to compile.
And here:
https://www.libsdl.org/projects/SDL_ttf/ (Development Version for MinGW, version 2.0.15)
We need: `lib/SDL2_ttf-2.0.15/i686-w64-mingw32/` to compile.

Please make sure the paths are correct!

After you added the libraries, you will have to navigate to the `i686-w64-mingw32/bin/` of both libraries and copy its contents into `MinGW/bin/`.
(I didn't have to override `zlib1.dll`)

Now you should be able to compile the project by using `mingw32-make` in the root folder of the project.
(Note: You can create a copy of `mingw32-make` in your `MinGW/bin/` folder and rename it to `make` so that you can use `make` instead)

**Attention**: Since we only copy the SDL2 and SDL2_ttf binaries into the MinGW folder, the compiled *.exe only runs within the MinGW environment.
So it has to always be run through the console.