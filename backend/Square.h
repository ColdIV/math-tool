#ifndef _SQUARE_H_
#define _SQUARE_H_

#include "Object.h"

class Square : public Object {
	public:
		Square ();
		
		Square (Point p1, Point p2);

		Square (float x1, float y1, Point p2);

		Square (Point p1, float x2, float y2);

		Square (float x1, float y1, float x2, float y2);

		void genPoints (Point p1, Point p2);
};

#endif