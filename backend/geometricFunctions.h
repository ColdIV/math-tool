#ifndef _GEOMETRICFUNCTIONS_H_
#define _GEOMETRICFUNCTIONS_H_

#include "Object.h"
#include "Circle.h"
#include "Point.h"
#include "Line.h"
#include <vector>
#include <cmath>
#include <algorithm>
#include <float.h>

#ifndef M_PI
    #define M_PI 3.14159265358979323846
#endif

bool isPointInLine(Line l, Point p);

std::vector <Point> getIntersections (Circle *c, Object *o);

std::vector <Point> getIntersections (Object *o, Circle *c);

std::vector <Point> getIntersections (Circle *a, Circle *b);

std::vector <Point> getIntersections (Object *a, Object *b);

bool intersects (Line a, Line b);

bool intersects (Line a, Line b, Point &p);

double angle (Line a, Line b);

double distance (Point a, Point b);

#endif
