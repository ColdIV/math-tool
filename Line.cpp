#include "Line.h"

Line::Line () {
	this->setLine(Point(0, 0), Point(0, 0));
}

Line::Line (Point p1, Point p2) {
	this->setLine(p1, p2);
}

Line::Line (float x1, float y1, Point p2) {
    this->setLine(Point(x1, y1), p2);
}

Line::Line (Point p1, float x2, float y2) {
    this->setLine(p1, Point(x2, y2));
}

Line::Line (float x1, float y1, float x2, float y2) {
    this->setLine(Point(x1, y1), Point(x2, y2));
}

Point Line::getP1 () {
    return this->p1;
}
		
Point Line::getP2 () {
    return this->p2;
}
		
void Line::setLine (Point p1, Point p2) {
    this->p1 = p1;
    this->p2 = p2;
}
		
void Line::setP1 (Point p1) {
    this->p1 = p1;
}

void Line::setP1 (float x1, float y1) {
    this->p1 = Point(x1, y1);
}
		
void Line::setP2 (Point p2) {
    this->p2 = p2;
}

void Line::setP2 (float x2, float y2) {
    this->p2 = Point(x2, y2);
}