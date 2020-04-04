#include "Line.h"

Line::Line () {
	this->setLine(Point(0, 0), Point(0, 0));
}

Line::Line (Point p1, Point p2) {
	this->setLine(p1, p2);
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
		
void Line::setP2 (Point p2) {
    this->p2 = p2;
}