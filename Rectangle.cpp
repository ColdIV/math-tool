#include "Rectangle.h"

Rectangle::Rectangle () {
	this->setRectangle(Point(0, 0), Point(0, 0), Point(0, 0), Point(0, 0));
}

Rectangle::Rectangle (Point p1, Point p2, Point p3, Point p4) : Object () {
    this->setRectangle(p1, p2, p3, p4);
}

Rectangle::Rectangle (Point p1, Point p2, Point p3, float x4, float y4) : Object () {
    this->setRectangle(p1, p2, p3, Point (x4, y4));
}

Rectangle::Rectangle (Point p1, Point p2, float x3, float y3, Point p4) : Object () {
    this->setRectangle(p1, p2, Point(x3, y3), p4);
}

Rectangle::Rectangle (Point p1, Point p2, float x3, float y3, float x4, float y4) : Object () {
    this->setRectangle(p1, p2, Point(x3, y3), Point(x4, y4));
}

Rectangle::Rectangle (Point p1, float x2, float y2, Point p3, Point p4) : Object () {
    this->setRectangle(p1, Point(x2, y2), p3, p4);
}

Rectangle::Rectangle (Point p1, float x2, float y2, Point p3, float x4, float y4) : Object () {
    this->setRectangle(p1, Point(x2, y2), p3, Point(x4, y4));
}

Rectangle::Rectangle (Point p1, float x2, float y2, float x3, float y3, Point p4) : Object () {
    this->setRectangle(p1, Point(x2, y2), Point(x3, y3), p4);
}

Rectangle::Rectangle (Point p1, float x2, float y2, float x3, float y3, float x4, float y4) : Object () {
    this->setRectangle(p1, Point(x2, y2), Point(x3, y3), Point(x4, y4));
}

Rectangle::Rectangle (float x1, float y1, Point p2, Point p3, Point p4) : Object () {
    this->setRectangle(Point(x1, y1), p2, p3, p4);
}

Rectangle::Rectangle (float x1, float y1, Point p2, Point p3, float x4, float y4) : Object () {
    this->setRectangle(Point(x1, y1), p2, p3, Point(x4, y4));
}

Rectangle::Rectangle (float x1, float y1, Point p2, float x3, float y3, Point p4) : Object () {
    this->setRectangle(Point(x1, y1), p2, Point(x3, y3), p4);
}

Rectangle::Rectangle (float x1, float y1, Point p2, float x3, float y3, float x4, float y4) : Object () {
    this->setRectangle(Point(x1, y1), p2, Point(x3, y3), Point(x4, y4));
}

Rectangle::Rectangle (float x1, float y1, float x2, float y2, Point p3, Point p4) : Object () {
    this->setRectangle(Point(x1, y1), Point(x2, y2), p3, p4);
}

Rectangle::Rectangle (float x1, float y1, float x2, float y2, Point p3, float x4, float y4) : Object () {
    this->setRectangle(Point(x1, y1), Point(x2, y2), p3, Point(x4, y4));
}

Rectangle::Rectangle (float x1, float y1, float x2, float y2, float x3, float y3, Point p4) : Object () {
    this->setRectangle(Point(x1, y1), Point(x2, y2), Point(x3, y3), p4);
}

Rectangle::Rectangle (float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4) : Object () {
    this->setRectangle(Point(x1, y1), Point(x2, y2), Point(x3, y3), Point(x4, y4));
}

void Rectangle::setRectangle (Point p1, Point p2, Point p3, Point p4) {
    Object::setPoint(1, p1);
    Object::addPoint(p2);
    Object::addPoint(p3);
    Object::addPoint(p4);
}
