#include "Triangle.h"

Triangle::Triangle () : Object () {
	this->setTriangle(Point(), Point(), Point());
}

Triangle::Triangle (Point p1, Point p2, Point p3) : Object () {
    this->setTriangle(p1, p2, p3);
}

Triangle::Triangle (double x1, double y1, Point p2, Point p3) : Object () {
    this->setTriangle(Point(x1, y1), p2, p3);
}

Triangle::Triangle (Point p1, double x2, double y2, Point p3) : Object () {
    this->setTriangle(p1, Point(x2, y2), p3);
}

Triangle::Triangle (Point p1, Point p2, double x3, double y3) : Object () {
    this->setTriangle(p1, p2, Point(x3, y3));
}

Triangle::Triangle (Point p1, double x2, double y2, double x3, double y3) : Object () {
    this->setTriangle(p1, Point(x2, y2), Point(x3, y3));
}
		
Triangle::Triangle (double x1, double y1, Point p2, double x3, double y3) : Object () {
    this->setTriangle(Point(x1, y1), p2, Point(x3, y3));
}

Triangle::Triangle (double x1, double y1, double x2, double y2, Point p3) : Object () {
    this->setTriangle(Point(x1, y1), Point(x2, y2), p3);
}
		
Triangle::Triangle (double x1, double y1, double x2, double y2, double x3, double y3) : Object () {
    this->setTriangle(Point(x1, y1), Point(x2, y2), Point(x3, y3));
}

void Triangle::setTriangle (Point p1, Point p2, Point p3) {
    Object::setPoint(1, p1);
    Object::addPoint(p2);
    Object::addPoint(p3);
}
