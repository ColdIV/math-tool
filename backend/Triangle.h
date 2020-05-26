#ifndef _TRIANGLE_H_
#define _TRIANGLE_H_

#include "Object.h"

class Triangle : public Object {
	public:
		Triangle ();
		
		Triangle (Point p1, Point p2, Point p3);

		Triangle (double x1, double y1, Point p2, Point p3);

		Triangle (Point p1, double x2, double y2, Point p3);

		Triangle (Point p1, Point p2, double x3, double y3);

		Triangle (Point p1, double x2, double y2, double x3, double y3);
		
		Triangle (double x1, double y1, Point p2, double x3, double y3);

		Triangle (double x1, double y1, double x2, double y2, Point p3);
		
		Triangle (double x1, double y1, double x2, double y2, double x3, double y3);
		
		void setTriangle (Point p1, Point p2, Point p3);
};

#endif