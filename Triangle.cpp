#include "Triangle.h"

Triangle::Triangle () {
	this->setTriangle(Point(0, 0), Point(0, 0), Point(0, 0));
}

Triangle::Triangle (Point p1, Point p2, Point p3) : Line(p1, p2) {
    this->setP3(p3);
}

Triangle::Triangle (float x1, float y1, Point p2, Point p3) : Line(x1, y1, p2) {
    this->setP3(p3);
}

Triangle::Triangle (Point p1, float x2, float y2, Point p3) : Line(p1, x2, y2) {
    this->setP3(p3);
}

Triangle::Triangle (Point p1, Point p2, float x3, float y3) : Line(p1, p2) {
    this->setP3(x3, y3);
}

Triangle::Triangle (Point p1, float x2, float y2, float x3, float y3) : Line(p1, x2, y2) {
    this->setP3(x3, y3);
}
		
Triangle::Triangle (float x1, float y1, Point p2, float x3, float y3) : Line(x1, y1, p2) {
    this->setP3(x3, y3);
}

Triangle::Triangle (float x1, float y1, float x2, float y2, Point p3) : Line(x1, y1, x2, y2) {
    this->setP3(p3);
}
		
Triangle::Triangle (float x1, float y1, float x2, float y2, float x3, float y3)  : Line(x1, y1, x2, y2) {
    this->setP3(x3, y3);
}

Point Triangle::getP3 () {
    return this->p3;
}
		
void Triangle::setTriangle (Point p1, Point p2, Point p3) {
    Line::setLine(p1, p2);
    this->p3 = p3;
}
		
void Triangle::setP3 (Point p3) {
    this->p3 = p3;
}

void Triangle::setP3 (float x3, float y3) {
    this->p3 = Point(x3, y3);
}
