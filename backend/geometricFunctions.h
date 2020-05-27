#ifndef _GEOMETRICFUNCTIONS_H_
#define _GEOMETRICFUNCTIONS_H_

// We could probably only include "Line.h", <cmath> and <algorithm> - but this is less confusing.
#include "Object.h"
#include "Point.h"
#include "Line.h"
#include <vector>
#include <cmath>
#include <algorithm>
#include <float.h>

std::vector <Point> intersection (Object a, Object b);

double angle (Line a, Line b);

double distance (Point a, Point b);

#endif
