#ifndef _CIRCLE_H_
#define _CIRCLE_H_

#include "Point.h"

class Circle {
	private:
		Point p;
        float r;
	public:
		Circle ();

        Circle (float r);
		
		Circle (float x, float y, float r);

        Circle (Point p, float r);

        Point getPoint ();

        float getRadius ();
		
		void setCircle (float x, float y, float r);

		void setCircle (Point p, float r);

        void setRadius (float r);
};

#endif