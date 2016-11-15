#include "point.h"


Point::Point(float &x_, float &y_, float &z_) {
	this->x = x_;
	this->y = y_;
	this->z = z_;
}

void
Point::setPoint(float &x_, float &y_, float &z_) {
	this->x = x_;
	this->y = y_;
	this->z = z_;
}

void
Point::setPoint(float x_, float y_, float z_) {
	this->x = x_;
	this->y = y_;
	this->z = z_;
}

void
Point::coordinates() {
	std::cout << "x = " << this->x;
	std::cout << "y = " << this->y;
	std::cout << "z = " << this->z;
}
