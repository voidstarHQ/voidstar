#ifndef POINT_H
#define POINT_H
 
#include <iostream>
#include <GL/glut.h>
 
class Point {
 
public:
	Point(void) {}
	Point(float &x, float &y, float &z);
	~Point() {
		this->x = 0.0;
		this->y = 0.0;
		this->z = 0.0;
	}

	Point& getPoint() { return *this; }
	void setPoint(float &x, float &y, float &z);
	void setPoint(float x, float y, float z);
	void coordinates();
 
public:
	float x, y, z;
 
};
 
#endif
