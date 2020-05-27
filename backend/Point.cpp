#include "Point.h"

Point::Point () {
	this->p = std::make_pair(0, 0);
}

Point::Point (double x, double y) {
	this->p = std::make_pair(x, y);
}

Point::Point (std::pair <double, double> p) {
	this->p = p;
}

double Point::x() {
	return this->p.first;
}

double Point::y() {
	return this->p.second;
}

void Point::setX(double x) {
	this->p.first = x;
}

void Point::setY(double y) {
	this->p.second = y;
}