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

Point Square::getP1 () {
    return this->p1;
}

Point Square::getP2 () {
    return this->p2;
}

Point Square::getP3 () {
    return this->p3;
}

Point Square::getP4 () {
    return this->p4;
}

void Square::genPoints (Point p1, Point p2) {
    float x1 = p1.getX();
    float y1 = p1.getY();
    float x2 = p2.getX();
    float y2 = p2.getY();
    
    this->p1 = p1;
    this->p3 = p2;

    Point diff ((x1 - x2) / 2, (y1 - x2) / 2);
    Point mid (x1 - (x1 - x2) / 2, y1 - (y1 - y2) / 2);

    if (x1 < x2 && y1 > y2) {
        this->p2 = Point(mid.getX() - diff.getX(), mid.getY() - diff.getY());
        this->p4 = Point(mid.getX() + diff.getX(), mid.getY() + diff.getY());
    } else {
        this->p2 = Point(mid.getX() - diff.getX(), mid.getY() + diff.getY());
        this->p4 = Point(mid.getX() + diff.getX(), mid.getY() - diff.getY());
    }
}