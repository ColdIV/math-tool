#ifndef _LINE_H_
#define _LINE_H_

#include "Object.h"

class Line : public Object {
	public:
		Line ();
		
		Line (Point p1, Point p2);

		Line (float x1, float y1, Point p2);

		Line (Point p1, float x2, float y2);

		Line (float x1, float y1, float x2, float y2);

		void setLine (Point p1, Point p2);
};

#endif