#ifndef _RECTANGLE_H_
#define _RECTANGLE_H_

#include "Object.h"

class Rectangle : public Object {
	public:
		Rectangle ();
		
		Rectangle (Point p1, Point p2, Point p3, Point p4);

        Rectangle (Point p1, Point p2, Point p3, float x4, float y4);

        Rectangle (Point p1, Point p2, float x3, float y3, Point p4);

        Rectangle (Point p1, Point p2, float x3, float y3, float x4, float y4);

        Rectangle (Point p1, float x2, float y2, Point p3, Point p4);

        Rectangle (Point p1, float x2, float y2, Point p3, float x4, float y4);

        Rectangle (Point p1, float x2, float y2, float x3, float y3, Point p4);

        Rectangle (Point p1, float x2, float y2, float x3, float y3, float x4, float y4);

        Rectangle (float x1, float y1, Point p2, Point p3, Point p4);

        Rectangle (float x1, float y1, Point p2, Point p3, float x4, float y4);

        Rectangle (float x1, float y1, Point p2, float x3, float y3, Point p4);

        Rectangle (float x1, float y1, Point p2, float x3, float y3, float x4, float y4);

        Rectangle (float x1, float y1, float x2, float y2, Point p3, Point p4);

        Rectangle (float x1, float y1, float x2, float y2, Point p3, float x4, float y4);

        Rectangle (float x1, float y1, float x2, float y2, float x3, float y3, Point p4);

        Rectangle (float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4);
		
		void setRectangle (Point p1, Point p2, Point p3, Point p4);
};

#endif