#include "geometricFunctions.h"

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
        double distIA1 = distance(ic, a.getPoint(1));
        double distIA2 = distance(ic, a.getPoint(2));
        double distA12 = distance(a.getPoint(1), a.getPoint(2));

        return (distIA1 + distIA2 == distA12);
    }

    return false;
}

// @TODO: Support points somehow
std::vector <Point> getIntersections (Object a, Object b) {
    std::vector <Point> intersections (0);

    // Get all points of the objects
    std::vector <Point> aPoints = a.getPoints();
    std::vector <Point> bPoints = b.getPoints();

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

    // Find intersctions between those lines
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

// Necessary for std::find in intersection()
bool operator== (Point a, Point b) {
    return (a.x() == b.x() && a.y() == b.y());
}
