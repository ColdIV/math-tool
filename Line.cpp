#include "Line.h"

Line::Line () {
	this->setLine(Point(0, 0), Point(0, 0));
}

Line::Line (Point p1, Point p2) : Object () {
	this->setLine(p1, p2);
}

Line::Line (float x1, float y1, Point p2) : Object () {
    this->setLine(Point(x1, y1), p2);
}

Line::Line (Point p1, float x2, float y2) : Object () {
    this->setLine(p1, Point(x2, y2));
}

Line::Line (float x1, float y1, float x2, float y2) : Object () {
    this->setLine(Point(x1, y1), Point(x2, y2));
}
		
void Line::setLine (Point p1, Point p2) {
    Object::setPoint(1, p1);
    Object::addPoint(p2);
}
