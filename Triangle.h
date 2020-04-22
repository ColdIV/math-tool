#ifndef _TRIANGLE_H_
#define _TRIANGLE_H_

#include "Line.h"

class Triangle : public Line {
	private:
		Point p3;
	public:
		Triangle ();
		
		Triangle (Point p1, Point p2, Point p3);

		Triangle (float x1, float y1, Point p2, Point p3);

		Triangle (Point p1, float x2, float y2, Point p3);

		Triangle (Point p1, Point p2, float x3, float y3);

		Triangle (Point p1, float x2, float y2, float x3, float y3);
		
		Triangle (float x1, float y1, Point p2, float x3, float y3);

		Triangle (float x1, float y1, float x2, float y2, Point p3);
		
		Triangle (float x1, float y1, float x2, float y2, float x3, float y3);
		
		Point getP3 ();
		
		void setTriangle (Point p1, Point p2, Point p3);
		
		void setP3 (Point p3);

		void setP3 (float x3, float y3);
};

#endif