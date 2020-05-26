#ifndef _POINT_H_
#define _POINT_H_

#include <tuple>

class Point {
	private:
		std::pair <double, double> p;
	public:
		Point ();
		
		Point (double x, double y);
		
		Point (std::pair <double, double> p);
		
		double x();
		
		double y();
		
		void setX(double x);
		
		void setY(double y);
};

#endif