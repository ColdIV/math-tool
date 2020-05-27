#include "Object.h"

Object::Object () {
	this->points = std::vector <Point> (1, Point());
}

Object::Object (Point point) {
	this->points = std::vector <Point> (1, point);
}

void Object::setPoint (Point point) {
	this->points = std::vector <Point> (1, point);
}
		
void Object::setPoint (int n, Point point) {
	if (n-- && n < this->points.size()) this->points[n] = point;
}

void Object::addPoint (Point point) {
	this->points.push_back(point);
}

Point Object::getPoint () {
	return this->points[0];
}

Point Object::getPoint (int n) {
	if (n-- && n < this->points.size()) return this->points[n];
	return Point();
}

std::vector <Point> Object::getPoints () {
	return this->points;
}