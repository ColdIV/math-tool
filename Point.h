#ifndef _POINT_H_
#define _POINT_H_

class Point {
	private:
		float x;
		float y;
	public:
		Point ();
		
		Point (float x, float y);
		
		float getX ();
		
		float getY ();
		
		void setPoint (float x, float y);
		
		void setX (float x);
		
		void setY (float y);

		float distanceTo(Point x);
};

#endif