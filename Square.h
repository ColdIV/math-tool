#ifndef _SQUARE_H_
#define _SQUARE_H_

#include "Line.h"

class Square : public Line {
	private:
		Point p1;
		Point p2;
	public:
		Square ();
		
		Square (Point p1, Point p2);

		Square (float x1, float y1, Point p2);

		Square (Point p1, float x2, float y2);

		Square (float x1, float y1, float x2, float y2);
		
        float getWidth ();
        float getHeight ();
};

#endif