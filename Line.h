#ifndef _LINE_H_
#define _LINE_H_

#include "Point.h"

class Line {
	private:
		Point p1;
		Point p2;
	public:
		Line ();
		
		Line (Point p1, Point p2);
		
		Point getP1 ();
		
		Point getP2 ();
		
		void setLine (Point p1, Point p2);
		
		void setP1 (Point p1);
		
		void setP2 (Point p2);
};

#endif