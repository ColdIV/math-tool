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

std::string Circle::toString() {
	std::string s = Object::toString();

	std::stringstream stream;
	std::string radius;

	stream << std::fixed << std::setprecision(2) << this->getRadius();
	radius = stream.str();
	

	s += ", Radius: " + radius;

	return s;
}