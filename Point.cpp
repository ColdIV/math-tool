#include "Point.h"

#include <math.h>

Point::Point () {
	this->setPoint(0, 0);
}

Point::Point (float x, float y) {
	this->setPoint(x, y);
}

float Point::getX () {
	return this->x;
}

float Point::getY () {
	return this->y;
}

void Point::setPoint (float x, float y) {
	this->setX(x);
	this->setY(y);
}

void Point::setX (float x) {
	this->x = x;
}

void Point::setY (float y) {
	this->y = y;
}

float Point::distanceTo (Point x) {
	return sqrt(pow(x.getX() - this->getX(), 2) + pow(x.getY() - this->getY(), 2));
}