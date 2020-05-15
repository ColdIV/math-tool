#include "Square.h"

Square::Square () {}

Square::Square (Point p1, Point p2) {
    genPoints(p1, p2);
}

Square::Square (float x1, float y1, Point p2) {
    genPoints(Point(x1, y1), p2);
}

Square::Square (Point p1, float x2, float y2) {
    genPoints(p1, Point(x2, y2));
}

Square::Square (float x1, float y1, float x2, float y2) {
    genPoints(Point(x1, y1), Point(x2, y2));
}

void Square::genPoints (Point p1, Point p3) {
    Point mid = Point((p1.x() + p3.x()) / 2, (p1.y() + p3.y()) / 2);
    Point t = Point((p3.y() - p1.y()) / 2, (p1.x() - p3.x()) / 2); // "vector"

    // missing points are mid + t and mid - t
    // due to the lack of a "point adding"-method, here we go:
    Point p2 = Point(mid.x() - t.x(), mid.y() - t.y());
    Point p4 = Point(mid.x() + t.x(), mid.y() + t.y());

    Object::setPoint(1, p1);
    Object::addPoint(p2);
    Object::addPoint(p3);
    Object::addPoint(p4);

}