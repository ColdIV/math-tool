#include "geometricFunctions.h"

// Necessary for std::find in intersection()
bool operator== (Point a, Point b) {
    return (a.x() == b.x() && a.y() == b.y());
}

bool isPointInLine(Line l, Point p) {
    double dist1 = distance(p, l.getPoint(1));
    double dist2 = distance(p, l.getPoint(2));
    double dist3 = distance(l.getPoint(1), l.getPoint(2));
    return ((int)(dist1 + dist2) == (int)dist3);
}

bool intersects (Line a, Line b) {
    Point p = Point();
    return intersects (a, b, p);
}

bool intersects (Line a, Line b, Point &p) {
     // Line A
    double a1 = a.getPoint(2).y() - a.getPoint(1).y();
    double b1 = a.getPoint(1).x() - a.getPoint(2).x();
    double c1 = a1 * (a.getPoint(1).x()) + b1 * (a.getPoint(1).y());

    // Line B
    double a2 = b.getPoint(2).y() - b.getPoint(1).y();
    double b2 = b.getPoint(1).x() - b.getPoint(2).x();
    double c2 = a2 * (b.getPoint(1).x()) + b2 * (b.getPoint(1).y());

    double determinant = a1 * b2 - a2 * b1; 

    // If determinant is 0, the lines are parallel, we don't care about that though.
    if (determinant) { 
        double x = (b2 * c1 - b1 * c2) / determinant;
        double y = (a1 * c2 - a2 * c1) / determinant;

        Point ic = Point (x, y);
        p = ic;

        // Check if point is in the desired range (as a line usually is endless)
        return isPointInLine(a, ic);
    }

    return false;
}

std::vector <Point> getIntersections (Circle *c, Object *o) {
    std::vector <Point> intersections;

    // Shamelessly stolen from:
    // http://csharphelper.com/blog/2014/09/determine-where-a-line-intersects-a-circle-in-c/
    double cx = c->getPoint().x(), cy = c->getPoint().y(), radius = c->getRadius();

    // Get all lines of object
    std::vector <Point> points = o->getPoints();
    std::vector <Line> lines (0);

    Line tmp;

    for (int i = 1; i < points.size(); ++i) {
        tmp = Line (points[i - 1], points[i]);
        lines.push_back(tmp);

        if (i == points.size() - 1) {
            tmp = Line (points[i], points[0]);
            lines.push_back(tmp);
        }
    }


    // Look for intersections between any line and circle
    for (Line l : lines) {
        double p1x = l.getPoint(1).x(), p1y = l.getPoint(1).y(), p2x = l.getPoint(2).x(), p2y = l.getPoint(2).y();
        Point ic = Point();

        double dx, dy, A, B, C, det, t;

        dx = p2x - p1x;
        dy = p2y - p1y;

        A = dx * dx + dy * dy;
        B = 2 * (dx * (p1x - cx) + dy * (p1y - cy));
        C = (p1x - cx) * (p1x - cx) + (p1y - cy) * (p1y - cy) - radius * radius;

        det = B * B - 4 * A * C;

        if ((A <= 0.0000001) || (det < 0)) {
            // No solution
        } else if (det == 0) {
            // One solution
            t = -B / (2 * A);
            ic = Point(p1x + t * dx, p1y + t * dy);

            if (isPointInLine(l, ic) && std::find(intersections.begin(), intersections.end(), ic) == intersections.end()) {
                intersections.push_back(ic);
            }
        } else {
            // Two solutions
            t = (double)((-B + sqrt(det)) / (2 * A));
            ic = Point(p1x + t * dx, p1y + t * dy);

            if (isPointInLine(l, ic) && std::find(intersections.begin(), intersections.end(), ic) == intersections.end()) {
                intersections.push_back(ic);
            }

            t = (double)((-B - sqrt(det)) / (2 * A));
            ic = Point(p1x + t * dx, p1y + t * dy);

            if (isPointInLine(l, ic) && std::find(intersections.begin(), intersections.end(), ic) == intersections.end()) {
                intersections.push_back(ic);
            }
        }
    }

    return intersections;
}

std::vector <Point> getIntersections (Object *o, Circle *c) {
    return getIntersections (c, o);
}

std::vector <Point> getIntersections (Circle *a, Circle *b) {
    std::vector <Point> intersections;

    // check if circles are identical
    if (a->getPoint() == b->getPoint() && a->getRadius() == b->getRadius()) return intersections;

    // Shamelessly stolen from:
    // https://www.xarg.org/2016/07/calculate-the-intersection-points-of-two-circles/
    double d = std::hypot(b->getPoint().x() - a->getPoint().x(), b->getPoint().y() - a->getPoint().y());

    if (d <= a->getRadius() + b->getRadius() && d >= abs(b->getRadius() - a->getRadius())) {
        double ex = (b->getPoint().x() - a->getPoint().x()) / d;
        double ey = (b->getPoint().y() - a->getPoint().y()) / d;

        double x = (a->getRadius() * a->getRadius() - b->getRadius() * b->getRadius() + d * d) / (2* d);
        double y = sqrt(a->getRadius() * a->getRadius() - x * x);

        Point P1 = Point (
            a->getPoint().x() + x * ex - y * ey,
            a->getPoint().y() + x * ey + y * ex
        );

        Point P2 = Point (
            a->getPoint().x() + x * ex + y * ey,
            a->getPoint().y() + x * ey - y * ex
        );

        intersections.push_back(P1);
        intersections.push_back(P2);
    }

    return intersections;
}

std::vector <Point> getIntersections (Object *a, Object *b) {
    // Check if one of the objects is a circle
    Circle *c1 = dynamic_cast<Circle *>(a);
    Circle *c2 = dynamic_cast<Circle *>(b);
    if (c1 && c2) return getIntersections (c1, c2);
    else if (c1 && !c2) return getIntersections (c1, b);
    else if (!c1 && c2) return getIntersections (a, c2);


    std::vector <Point> intersections (0);

    // Get all points of the objects
    std::vector <Point> aPoints = a->getPoints();
    std::vector <Point> bPoints = b->getPoints();

    // Get all lines of the objects
    std::vector <Line> aLines (0);
    std::vector <Line> bLines (0);

    Line tmp;

    for (int i = 1; i < aPoints.size(); ++i) {
        tmp = Line (aPoints[i - 1], aPoints[i]);
        aLines.push_back(tmp);

        if (i == aPoints.size() - 1) {
            tmp = Line (aPoints[i], aPoints[0]);
            aLines.push_back(tmp);
        }
    }

    for (int i = 1; i < bPoints.size(); ++i) {
        tmp = Line (bPoints[i - 1], bPoints[i]);
        bLines.push_back(tmp);

        if (i == bPoints.size() - 1) {
            tmp = Line (bPoints[i], bPoints[0]);
            bLines.push_back(tmp);
        }
    }

    // Find intersections between those lines
    for (Line aL : aLines) {
        for (Line bL : bLines) {
            Point ic = Point();

            if (intersects(aL, bL, ic)) {
                // Check for duplicates
                if (std::find(intersections.begin(), intersections.end(), ic) == intersections.end()) {
                    // Add point to intersections
                    intersections.push_back(ic); 
                }
            } 
        }
    }

    return intersections;
}

double angle (Line a, Line b) {
    if (!intersects (a, b)) return 0;

    double da, db, dc, dd, cosAngle, deg, mag1, mag2;

    da = a.getPoint(1).x() - a.getPoint(2).x();
    db = a.getPoint(1).y() - a.getPoint(2).y();
    dc = b.getPoint(1).x() - b.getPoint(2).x();
    dd = b.getPoint(1).y() - b.getPoint(2).y();

    // calculate magnitudes
    mag1 = sqrt(da * da + db * db);
    mag2 = sqrt(dc * dc + dd * dd);

    // get radiant
    cosAngle = (da * dc + db * dd) / (mag1 * mag2);
    deg = acos(cosAngle);

    // get degree from radiant
    deg = deg * 180.0 / M_PI;

    return deg;
}

double distance (Point a, Point b) {
    return sqrt(pow(b.x() - a.x(), 2) + pow(b.y() - a.y(), 2));
}

