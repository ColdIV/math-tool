#ifndef _LINE_H_
#define _LINE_H_

#include "Point.h"

class Line {
	private:
		Point p[1];
		int size = 1;
	public:
		Line ();
		
		Line (Point p1, Point p2);

		Line (float x1, float y1, Point p2);

		Line (Point p1, float x2, float y2);

		Line (float x1, float y1, float x2, float y2);
		
		Point getP1 ();
		
		Point getP2 ();

		Point getPN (int n);
		
		void setLine (Point p1, Point p2);
		
		void setP1 (Point p1);

		void setP1 (float x1, float y1);
		
		void setP2 (Point p2);

		void setP2 (float x2, float y2);

		void setPN (int n, Point p);

		void setPN (int n, float xn, float yn);
};

#endif