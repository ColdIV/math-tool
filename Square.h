#ifndef _SQUARE_H_
#define _SQUARE_H_

#include "Point.h"

class Square {
	private:
		Point p1;
		Point p2;
		Point p3;
		Point p4;
	public:
		Square ();
		
		Square (Point p1, Point p2);

		Square (float x1, float y1, Point p2);

		Square (Point p1, float x2, float y2);

		Square (float x1, float y1, float x2, float y2);

		Point getP1 ();
		Point getP2 ();
		Point getP3 ();
		Point getP4 ();

		void genPoints (Point p1, Point p2);
};

#endif