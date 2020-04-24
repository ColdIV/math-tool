#include "Square.h"

Square::Square () : Line () {}

Square::Square (Point p1, Point p2) : Line (p1, p2) {}

Square::Square (float x1, float y1, Point p2) : Line (x1, y1, p2) {}

Square::Square (Point p1, float x2, float y2) : Line (p1, x2, y2) {}

Square::Square (float x1, float y1, float x2, float y2) : Line (x1, y1, x2, y2) {}