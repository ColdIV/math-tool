#include "Circle.h"

Circle::Circle () : Object() {
	this->setRadius(0);
}

Circle::Circle (Point point, double radius) : Object (point) {
	this->setRadius(radius);
}

void Circle::setRadius (double radius) {
	this->radius = radius;
}

double Circle::getRadius () {
	return this->radius;
}