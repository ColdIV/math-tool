#include "Rectangle.h"

Rectangle::Rectangle () {
	this->setRectangle(Point(0, 0), Point(0, 0), Point(0, 0), Point(0, 0));
}

Rectangle::Rectangle (Point p1, Point p2, Point p3, Point p4) : Triangle (p1, p2, p3) {
    this->setP4(p4);
}

Rectangle::Rectangle (Point p1, Point p2, Point p3, float x4, float y4) : Triangle (p1, p2, p3) {
    this->setP4(x4, y4);
}

Rectangle::Rectangle (Point p1, Point p2, float x3, float y3, Point p4) : Triangle (p1, p2, x3, y3) {
    this->setP4(p4);
}

Rectangle::Rectangle (Point p1, Point p2, float x3, float y3, float x4, float y4) : Triangle (p1, p2, x3, y3) {
    this->setP4(x4, y4);
}

Rectangle::Rectangle (Point p1, float x2, float y2, Point p3, Point p4) : Triangle (p1, x2, y2, p3) {
    this->setP4(p4);
}

Rectangle::Rectangle (Point p1, float x2, float y2, Point p3, float x4, float y4) : Triangle (p1, x2, y2, p3) {
    this->setP4(x4, y4);
}

Rectangle::Rectangle (Point p1, float x2, float y2, float x3, float y3, Point p4) : Triangle (p1, x2, y2, x3, y3) {
    this->setP4(p4);
}

Rectangle::Rectangle (Point p1, float x2, float y2, float x3, float y3, float x4, float y4) : Triangle (p1, x2, y2, x3, y3) {
    this->setP4(x4, y4);
}

Rectangle::Rectangle (float x1, float y1, Point p2, Point p3, Point p4) : Triangle (x1, y1, p2, p3) {
    this->setP4(p4);
}

Rectangle::Rectangle (float x1, float y1, Point p2, Point p3, float x4, float y4) : Triangle (x1, y1, p2, p3) {
    this->setP4(x4, y4);
}

Rectangle::Rectangle (float x1, float y1, Point p2, float x3, float y3, Point p4) : Triangle (x1, y1, p2, x3, y3) {
    this->setP4(p4);
}

Rectangle::Rectangle (float x1, float y1, Point p2, float x3, float y3, float x4, float y4) : Triangle (x1, y1, p2, x3, y3) {
    this->setP4(x4, y4);
}

Rectangle::Rectangle (float x1, float y1, float x2, float y2, Point p3, Point p4) : Triangle (x1, y1, x2, y2, p3) {
    this->setP4(p4);
}

Rectangle::Rectangle (float x1, float y1, float x2, float y2, Point p3, float x4, float y4) : Triangle (x1, y1, x2, y2, p3) {
    this->setP4(x4, y4);
}

Rectangle::Rectangle (float x1, float y1, float x2, float y2, float x3, float y3, Point p4) : Triangle (x1, y1, x2, y2, x3, y3) {
    this->setP4(p4);
}

Rectangle::Rectangle (float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4) : Triangle (x1, y1, x2, y2, x3, y3) {
    this->setP4(x4, y4);
}

Point Rectangle::getP4 () {
    return this->p4;
}
		
void Rectangle::setRectangle (Point p1, Point p2, Point p3, Point p4) {
    Triangle::setTriangle(p1, p2, p3);
    this->p4 = p4;
}
		
void Rectangle::setP4 (Point p4) {
    this->p4 = p4;
}

void Rectangle::setP4 (float x4, float y4) {
    this->p4 = Point(x4, y4);
}
