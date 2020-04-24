#include "Circle.h"

Circle::Circle () {
	this->setCircle(0, 0, 0);
}

Circle::Circle (float r) {
    this->setCircle(0, 0, r);
}

Circle::Circle (float x, float y, float r) {
	this->setCircle(x, y, r);
}

Circle::Circle (Point p, float r) {
    this->setCircle(p, r);
}

Point Circle::getPoint () {
    return this->p;
}

float Circle::getRadius () {
    return this->r;
}

void Circle::setCircle (float x, float y, float r) {
	this->p = Point (x, y);
    this->r = r;
}

void Circle::setCircle (Point p, float r) {
    this->p = p;
    this->r = r;
}

void Circle::setRadius (float r) {
    this->r = r;
}